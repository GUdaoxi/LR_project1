<template>
  <AppShell>
    <div class="grid gap-4 xl:grid-cols-3">
      <section class="card space-y-4 p-4 xl:col-span-2">
        <div class="flex flex-wrap gap-2">
          <input v-model="query" class="input flex-1" placeholder="搜索 symbol 或名称" @keyup.enter="loadAssets" />
          <select v-model="market" class="input w-40">
            <option value="">全部市场</option>
            <option value="US">美股</option>
            <option value="HK">港股</option>
          </select>
          <input v-model="tag" class="input w-44" placeholder="标签（可选）" @keyup.enter="loadAssets" />
          <button class="btn-primary" @click="loadAssets">查询</button>
        </div>

        <div v-if="loading" class="py-12 text-center text-slate-500">加载中...</div>
        <div v-else-if="assets.length === 0" class="py-12 text-center text-slate-500">暂无匹配资产</div>
        <table v-else class="w-full text-sm">
          <thead class="text-left text-slate-500">
            <tr>
              <th class="py-2">代码</th>
              <th>名称</th>
              <th>市场</th>
              <th>币种</th>
              <th>标签</th>
              <th></th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="item in assets" :key="item.id" class="border-t border-slate-100 hover:bg-slate-50">
              <td class="py-3 font-medium">{{ item.symbol }}</td>
              <td>{{ item.name }}</td>
              <td>{{ item.market_display }}</td>
              <td>{{ item.currency }}</td>
              <td class="space-x-1">
                <span v-for="t in item.tags_list.slice(0, 2)" :key="t" class="badge">{{ t }}</span>
              </td>
              <td><button class="btn-secondary" @click="goDetail(item.id)">详情</button></td>
            </tr>
          </tbody>
        </table>
      </section>

      <section class="card p-4">
        <h3 class="mb-3 text-base font-semibold">我的关注</h3>
        <div v-if="watchlistLoading" class="text-sm text-slate-500">加载中...</div>
        <div v-else-if="watchlist.length === 0" class="text-sm text-slate-500">你还没有关注任何资产</div>
        <ul v-else class="space-y-2">
          <li v-for="item in watchlist" :key="item.asset.id" class="flex items-center justify-between rounded-lg border border-slate-200 p-2">
            <div>
              <p class="text-sm font-medium">{{ item.asset.symbol }}</p>
              <p class="text-xs text-slate-500">{{ item.asset.name }}</p>
            </div>
            <button class="btn-secondary" @click="removeWatch(item.asset.id)">取消</button>
          </li>
        </ul>
      </section>
    </div>
    <ToastMessage :message="toast" />
  </AppShell>
</template>

<script setup lang="ts">
import { onMounted, ref } from 'vue'
import { useRouter } from 'vue-router'

import { api } from '../api'
import AppShell from '../components/AppShell.vue'
import ToastMessage from '../components/ToastMessage.vue'
import type { Asset, PaginatedResponse, WatchlistItem } from '../types'

const router = useRouter()
const query = ref('')
const market = ref('')
const tag = ref('')
const assets = ref<Asset[]>([])
const watchlist = ref<WatchlistItem[]>([])
const loading = ref(false)
const watchlistLoading = ref(false)
const toast = ref('')

const showToast = (msg: string) => {
  toast.value = msg
  setTimeout(() => (toast.value = ''), 2000)
}

const loadAssets = async () => {
  try {
    loading.value = true
    const { data } = await api.get<PaginatedResponse<Asset>>('/assets/', {
      params: { query: query.value, market: market.value, tag: tag.value },
    })
    assets.value = data.results
  } catch {
    showToast('资产加载失败，请稍后重试。')
  } finally {
    loading.value = false
  }
}

const loadWatchlist = async () => {
  try {
    watchlistLoading.value = true
    const { data } = await api.get<WatchlistItem[]>('/watchlist/')
    watchlist.value = data
  } catch {
    showToast('关注列表加载失败。')
  } finally {
    watchlistLoading.value = false
  }
}

const removeWatch = async (assetId: number) => {
  await api.delete(`/watchlist/${assetId}/`)
  showToast('已取消关注')
  loadWatchlist()
}

const goDetail = (id: number) => router.push(`/assets/${id}`)

onMounted(() => {
  loadAssets()
  loadWatchlist()
})
</script>
