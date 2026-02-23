import { createApp, defineComponent } from 'vue'

const App = defineComponent({
  template: `
    <main style="font-family: sans-serif; margin: 2rem;">
      <h1>LR Project1 Frontend</h1>
      <p>Vue 3 + Vite + TypeScript is ready.</p>
    </main>
  `,
})

createApp(App).mount('#app')
