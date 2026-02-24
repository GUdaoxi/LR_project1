import { createRouter, createWebHistory } from 'vue-router'

import { tokenStore } from './api'
import AssetDetailPage from './views/AssetDetailPage.vue'
import AssetsPage from './views/AssetsPage.vue'
import LoginPage from './views/LoginPage.vue'
import PortfolioLabPage from './views/PortfolioLabPage.vue'

const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/login', component: LoginPage },
    { path: '/assets', component: AssetsPage },
    { path: '/assets/:id', component: AssetDetailPage },
    { path: '/lab/portfolio', component: PortfolioLabPage },
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
