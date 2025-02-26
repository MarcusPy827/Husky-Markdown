<template>
  <div class="app-layout">
    <SideBar />
  </div>
</template>

<script>
import SideBar from "@/components/SideBar.vue";

export default {
  name: 'App',
  components: {
    SideBar
  }
}
</script>

<style>
  :root {
    --background: #F6F5F5;
    --primary: #4592AF;
  }

  @media(prefers-color-scheme: dark) {
    :root {
      --background: #33313B;
      --primary: #4592AF;
    }
  }

  #app {
    width: 100vw;
    height: 100vh;
    margin: 0;
    padding: 0;
  }

  body {
    width: 100vw;
    height: 100vh;
    background: var(--background);
    margin: 0;
    padding: 0;
  }

  .app-layout {
    width: 100%;
    height: 100%;
    display: flex;
    flex-direction: row;
    flex-wrap: nowrap;
    align-content: flex-start;
    justify-content: flex-start;
    align-items: flex-start;
  }
</style>
