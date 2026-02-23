<template>
  <div class="flex min-h-screen items-center justify-center bg-gradient-to-br from-indigo-50 to-slate-100 p-4">
    <div class="card w-full max-w-md p-6">
      <h2 class="mb-1 text-2xl font-semibold">欢迎登录</h2>
      <p class="mb-6 text-sm text-slate-500">使用你的账号进入资产检索系统</p>
      <form class="space-y-4" @submit.prevent="submit">
        <input v-model="username" class="input" placeholder="用户名" />
        <input v-model="password" class="input" placeholder="密码" type="password" />
        <button class="btn-primary w-full" :disabled="loading">{{ loading ? '登录中...' : '登录' }}</button>
      </form>
    </div>
    <ToastMessage :message="toast" />
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue'
import { useRouter } from 'vue-router'

import { api, tokenStore } from '../api'
import ToastMessage from '../components/ToastMessage.vue'

const router = useRouter()
const username = ref('')
const password = ref('')
const loading = ref(false)
const toast = ref('')

const showToast = (msg: string) => {
  toast.value = msg
  setTimeout(() => (toast.value = ''), 2000)
}

const submit = async () => {
  try {
    loading.value = true
    const { data } = await api.post('/auth/token/', {
      username: username.value,
      password: password.value,
    })
    tokenStore.set(data.access, data.refresh)
    router.push('/assets')
  } catch {
    showToast('登录失败，请检查用户名或密码。')
  } finally {
    loading.value = false
  }
}
</script>
