<template>
  <AppShell>
    <div class="space-y-4">
      <h2 class="text-xl font-semibold">组合实验室</h2>

      <div class="grid gap-4 xl:grid-cols-3">
        <section class="card space-y-3 p-4">
          <h3 class="font-semibold">1) 从我的关注中选股</h3>
          <div v-if="loadingWatchlist" class="text-sm text-slate-500">加载中...</div>
          <div v-else-if="watchlist.length === 0" class="text-sm text-slate-500">暂无关注资产，请先去资产页添加。</div>
          <ul v-else class="space-y-2">
            <li v-for="item in watchlist" :key="item.asset.id" class="flex items-center gap-2 text-sm">
              <input v-model="selectedSymbols" :disabled="item.asset.market !== 'US'" :value="item.asset.symbol" type="checkbox" />
              <span>{{ item.asset.symbol }} - {{ item.asset.name }}</span>
              <span v-if="item.asset.market !== 'US'" class="text-xs text-amber-600">暂不支持</span>
            </li>
          </ul>
        </section>

        <section class="card space-y-3 p-4">
          <h3 class="font-semibold">2) 生成组合</h3>
          <select v-model="method" class="input w-full">
            <option value="equal_weight">等权</option>
            <option value="risk_parity">风险平价</option>
            <option value="min_var">最小方差</option>
            <option value="max_sharpe">最大夏普</option>
          </select>
          <input v-model.number="lookbackDays" class="input w-full" type="number" min="30" />
          <button class="btn-primary w-full" :disabled="loadingOptimize" @click="runOptimize">
            {{ loadingOptimize ? '生成中...' : '生成组合' }}
          </button>
          <div v-if="weights.length" class="space-y-1 text-sm">
            <p v-for="row in weights" :key="row.symbol">{{ row.symbol }}：{{ (row.w * 100).toFixed(2) }}%</p>
          </div>
          <div v-else class="text-sm text-slate-500">尚未生成组合</div>
        </section>

        <section class="card space-y-3 p-4">
          <h3 class="font-semibold">3) 运行回测</h3>
          <input v-model="start" class="input w-full" type="date" />
          <input v-model="end" class="input w-full" type="date" />
          <select v-model="rebalance" class="input w-full">
            <option value="monthly">月度再平衡</option>
            <option value="buy_hold">买入并持有</option>
          </select>
          <input v-model.number="costBps" class="input w-full" type="number" min="0" />
          <button class="btn-primary w-full" :disabled="loadingBacktest" @click="runBacktest">
            {{ loadingBacktest ? '回测中...' : '运行回测' }}
          </button>
        </section>
      </div>

      <div v-if="equityCurve.length" class="grid gap-4 xl:grid-cols-2">
        <section class="card p-4">
          <h3 class="mb-2 font-semibold">NAV 曲线</h3>
          <svg viewBox="0 0 600 220" class="h-56 w-full">
            <polyline fill="none" stroke="#4f46e5" stroke-width="2" :points="curvePoints(equityCurve, 'nav')" />
          </svg>
        </section>
        <section class="card p-4">
          <h3 class="mb-2 font-semibold">回撤曲线</h3>
          <svg viewBox="0 0 600 220" class="h-56 w-full">
            <polyline fill="none" stroke="#dc2626" stroke-width="2" :points="curvePoints(drawdownCurve, 'dd')" />
          </svg>
        </section>
      </div>

      <section v-if="stats" class="card p-4">
        <h3 class="mb-3 font-semibold">指标</h3>
        <div class="grid grid-cols-2 gap-3 text-sm md:grid-cols-6">
          <div class="badge">CAGR {{ pct(stats.CAGR) }}</div>
          <div class="badge">Vol {{ pct(stats.ann_vol) }}</div>
          <div class="badge">MaxDD {{ pct(stats.max_dd) }}</div>
          <div class="badge">Sharpe {{ stats.sharpe.toFixed(2) }}</div>
          <div class="badge">Turnover {{ stats.turnover.toFixed(2) }}</div>
          <div class="badge">再平衡 {{ stats.rebalance_count }}</div>
        </div>
      </section>
    </div>
    <ToastMessage :message="toast" />
  </AppShell>
</template>

<script setup lang="ts">
import { onMounted, ref } from 'vue'

import { api } from '../api'
import AppShell from '../components/AppShell.vue'
import ToastMessage from '../components/ToastMessage.vue'
import type { WatchlistItem } from '../types'

interface WeightRow { symbol: string; w: number }

const watchlist = ref<WatchlistItem[]>([])
const loadingWatchlist = ref(false)
const selectedSymbols = ref<string[]>([])
const method = ref('equal_weight')
const lookbackDays = ref(252)
const weights = ref<WeightRow[]>([])
const loadingOptimize = ref(false)
const loadingBacktest = ref(false)
const start = ref('2022-01-01')
const end = ref(new Date().toISOString().slice(0, 10))
const rebalance = ref('monthly')
const costBps = ref(10)
const equityCurve = ref<Array<{ date: string; nav: number }>>([])
const drawdownCurve = ref<Array<{ date: string; dd: number }>>([])
const stats = ref<any>(null)
const toast = ref('')

const showToast = (msg: string) => {
  toast.value = msg
  setTimeout(() => (toast.value = ''), 2200)
}

const loadWatchlist = async () => {
  try {
    loadingWatchlist.value = true
    const { data } = await api.get<WatchlistItem[]>('/watchlist/')
    watchlist.value = data
  } catch {
    showToast('关注列表加载失败')
  } finally {
    loadingWatchlist.value = false
  }
}

const runOptimize = async () => {
  if (selectedSymbols.value.length === 0) {
    showToast('请先选择资产')
    return
  }
  try {
    loadingOptimize.value = true
    const { data } = await api.post('/portfolio/optimize/', {
      symbols: selectedSymbols.value,
      method: method.value,
      lookback_days: lookbackDays.value,
      risk_free: 0.02,
    })
    weights.value = data.weights
    if (data.notes?.length) showToast(data.notes[0])
  } catch {
    showToast('组合优化失败')
  } finally {
    loadingOptimize.value = false
  }
}

const runBacktest = async () => {
  if (!weights.value.length) {
    showToast('请先生成组合')
    return
  }
  const weightMap = Object.fromEntries(weights.value.map((x) => [x.symbol, x.w]))
  try {
    loadingBacktest.value = true
    const { data } = await api.post('/backtest/run/', {
      symbols: selectedSymbols.value,
      weights: weightMap,
      start: start.value,
      end: end.value,
      rebalance: rebalance.value,
      cost_bps: costBps.value,
    })
    equityCurve.value = data.equity_curve
    drawdownCurve.value = data.drawdown_curve
    stats.value = data.stats
    if (data.notes?.length) showToast(data.notes[0])
  } catch {
    showToast('回测失败')
  } finally {
    loadingBacktest.value = false
  }
}

const curvePoints = (series: Array<{ [k: string]: number }>, key: 'nav' | 'dd') => {
  if (!series.length) return ''
  const values = series.map((x) => x[key])
  const min = Math.min(...values)
  const max = Math.max(...values)
  const span = max - min || 1
  return series
    .map((row, i) => {
      const x = (i / Math.max(series.length - 1, 1)) * 600
      const y = 210 - ((row[key] - min) / span) * 180
      return `${x},${y}`
    })
    .join(' ')
}

const pct = (x: number) => `${(x * 100).toFixed(2)}%`

onMounted(loadWatchlist)
</script>
