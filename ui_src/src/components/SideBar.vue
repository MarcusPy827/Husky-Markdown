<template>
  <div class="sidebar-layout">
    <div class="sidebar-menu">
      <div class="file-manager-active" v-if="current_tool === 'file_manager'">
        <img class="sidebar-icon" src="../assets/file_manager_active.svg" alt="" />
      </div>
    </div>

    <div class="sidebar-divider" />
  </div>
</template>

<script>
  export default {
    name: 'SideBar',
    props: {
      current_tool: {
        type: String,
        default: 'file_manager',
      }
    }
  }
</script>

<style scoped>
  .sidebar-layout {
    min-width: 128px;
    max-width: 320px;
    height: calc(100vh - 32px);
    padding: 16px;
    display: flex;
    flex-direction: row;
    flex-wrap: nowrap;
    align-content: flex-start;
    justify-content: flex-start;
    align-items: flex-start;
  }

  .sidebar-menu {
    margin-right: 8px;
  }

  .sidebar-divider {
    background: #CCCCCC;
    margin-top: 0px;
    margin-left: 4px;
    margin-right: 4px;
    margin-bottom: 0px;
    width: 2px;
    height: calc(100% - 12px);
  }

  .sidebar-icon {
    width: 32px;
    height: 32px;
  }

  .file-manager-active {
    background-color: var(--primary);
    width: 48px;
    height: 48px;
    border: 0px solid var(--primary);
    border-radius: 7px;
    display: flex;
    flex-direction: row;
    flex-wrap: nowrap;
    align-content: center;
    justify-content: center;
    align-items: center;
  }
</style>