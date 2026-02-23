import { createRouter, createWebHistory } from 'vue-router'

import { tokenStore } from './api'
import AssetDetailPage from './views/AssetDetailPage.vue'
import AssetsPage from './views/AssetsPage.vue'
import LoginPage from './views/LoginPage.vue'

const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/login', component: LoginPage },
    { path: '/assets', component: AssetsPage },
    { path: '/assets/:id', component: AssetDetailPage },
    { path: '/:pathMatch(.*)*', redirect: '/assets' },
  ],
})

router.beforeEach((to) => {
  if (to.path !== '/login' && !tokenStore.access) {
    return '/login'
  }
  if (to.path === '/login' && tokenStore.access) {
    return '/assets'
  }
  return true
})

export default router
