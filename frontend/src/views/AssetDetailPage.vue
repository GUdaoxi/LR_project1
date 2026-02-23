<template>
  <AppShell>
    <div class="space-y-4">
      <section class="card p-5" v-if="asset">
        <div class="mb-3 flex items-start justify-between">
          <div>
            <h2 class="text-xl font-semibold">{{ asset.name }} <span class="text-slate-400">{{ asset.symbol }}</span></h2>
            <p class="text-sm text-slate-500">{{ asset.market_display }} · {{ asset.currency }} · {{ asset.exchange }}</p>
          </div>
          <button class="btn-primary" @click="toggleWatch">{{ watched ? '取消关注' : '加入关注' }}</button>
        </div>
        <div class="grid gap-2 text-sm md:grid-cols-2">
          <p><span class="text-slate-500">板块：</span>{{ asset.sector || '-' }}</p>
          <p><span class="text-slate-500">行业：</span>{{ asset.industry || '-' }}</p>
          <p class="md:col-span-2"><span class="text-slate-500">标签：</span>
            <span v-for="t in asset.tags_list" :key="t" class="badge mr-1">{{ t }}</span>
          </p>
        </div>
      </section>

      <section class="card p-5">
        <h3 class="mb-3 font-semibold">为你推荐</h3>
        <div v-if="recLoading" class="text-sm text-slate-500">推荐生成中...</div>
        <div v-else-if="recs.length === 0" class="text-sm text-slate-500">暂无推荐，先去关注几只股票吧。</div>
        <ul v-else class="space-y-2">
          <li v-for="item in recs" :key="item.id" class="rounded-lg border border-slate-200 p-3">
            <p class="font-medium">{{ item.symbol }} · {{ item.name }} <span class="text-xs text-slate-500">{{ item.market_display }}</span></p>
            <p class="mt-1 text-sm text-indigo-600">{{ item.reason }}</p>
          </li>
        </ul>
      </section>
    </div>
    <ToastMessage :message="toast" />
  </AppShell>
</template>

<script setup lang="ts">
import { onMounted, ref } from 'vue'
import { useRoute } from 'vue-router'

import { api } from '../api'
import AppShell from '../components/AppShell.vue'
import ToastMessage from '../components/ToastMessage.vue'
import type { Asset, Recommendation, WatchlistItem } from '../types'

const route = useRoute()
const asset = ref<Asset | null>(null)
const recs = ref<Recommendation[]>([])
const watched = ref(false)
const recLoading = ref(false)
const toast = ref('')

const showToast = (msg: string) => {
  toast.value = msg
  setTimeout(() => (toast.value = ''), 2000)
}

const assetId = Number(route.params.id)

const loadAsset = async () => {
  const { data } = await api.get<Asset>(`/assets/${assetId}/`)
  asset.value = data
}

const loadWatchState = async () => {
  const { data } = await api.get<WatchlistItem[]>('/watchlist/')
  watched.value = data.some((item) => item.asset.id === assetId)
}

const loadRecs = async () => {
  recLoading.value = true
  try {
    const { data } = await api.get<Recommendation[]>('/recommendations/')
    recs.value = data
  } finally {
    recLoading.value = false
  }
}

const toggleWatch = async () => {
  if (watched.value) {
    await api.delete(`/watchlist/${assetId}/`)
    watched.value = false
    showToast('已取消关注')
  } else {
    await api.post('/watchlist/', { asset_id: assetId })
    watched.value = true
    showToast('关注成功')
  }
  loadRecs()
}

onMounted(async () => {
  try {
    await Promise.all([loadAsset(), loadWatchState(), loadRecs()])
  } catch {
    showToast('加载详情失败，请重试。')
  }
})
</script>
