<template>
  <div class="min-h-screen">
    <header class="border-b border-slate-200 bg-white/90 backdrop-blur">
      <div class="mx-auto flex h-14 max-w-7xl items-center justify-between px-4">
        <h1 class="text-lg font-semibold text-indigo-600">LR 投资助手</h1>
        <button class="btn-secondary" @click="logout">退出登录</button>
      </div>
    </header>
    <div class="mx-auto grid max-w-7xl grid-cols-12 gap-4 px-4 py-4">
      <aside class="card col-span-12 p-4 md:col-span-3 lg:col-span-2">
        <nav class="space-y-2 text-sm">
          <RouterLink class="block rounded-md px-3 py-2 hover:bg-slate-100" to="/assets">资产检索</RouterLink>
          <RouterLink class="block rounded-md px-3 py-2 hover:bg-slate-100" to="/lab/portfolio">组合实验室</RouterLink>
        </nav>
      </aside>
      <main class="col-span-12 md:col-span-9 lg:col-span-10">
        <slot />
      </main>
    </div>
  </div>
</template>

<script setup lang="ts">
import { useRouter } from 'vue-router'
import { tokenStore } from '../api'

const router = useRouter()

const logout = () => {
  tokenStore.clear()
  router.push('/login')
}
</script>
