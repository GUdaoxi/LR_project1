import axios from 'axios'

const ACCESS_TOKEN_KEY = 'lr_access'
const REFRESH_TOKEN_KEY = 'lr_refresh'

export const tokenStore = {
  get access() {
    return localStorage.getItem(ACCESS_TOKEN_KEY)
  },
  get refresh() {
    return localStorage.getItem(REFRESH_TOKEN_KEY)
  },
  set(access: string, refresh: string) {
    localStorage.setItem(ACCESS_TOKEN_KEY, access)
    localStorage.setItem(REFRESH_TOKEN_KEY, refresh)
  },
  clear() {
    localStorage.removeItem(ACCESS_TOKEN_KEY)
    localStorage.removeItem(REFRESH_TOKEN_KEY)
  },
}

export const api = axios.create({
  baseURL: '/api',
})

api.interceptors.request.use((config) => {
  const token = tokenStore.access
  if (token) {
    config.headers.Authorization = `Bearer ${token}`
  }
  return config
})

api.interceptors.response.use(
  (response) => response,
  (error) => {
    if (error.response?.status === 401) {
      tokenStore.clear()
      alert('登录状态已失效，请重新登录。')
      if (window.location.pathname !== '/login') {
        window.location.href = '/login'
      }
    }
    return Promise.reject(error)
  },
)
