<template>
  <div v-if="message" class="fixed right-4 top-4 z-50 rounded-lg bg-slate-900 px-4 py-2 text-sm text-white shadow">
    {{ message }}
  </div>
</template>

<script setup lang="ts">
defineProps<{ message: string }>()
</script>
