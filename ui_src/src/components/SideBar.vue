<template>
  <div class="sidebar-layout">
    <div class="sidebar-menu">
      <div class="sidebar-icon-container sidebar-icon-container-active" v-if="current_tool === 'file_manager'">
        <img class="sidebar-icon" src="../assets/file_manager_active.svg" alt="" draggable="false" />
      </div>

      <div class="sidebar-icon-container" v-on:click="this.current_tool = 'file_manager'" v-else>
        <img class="sidebar-icon" src="../assets/file_manager.svg" alt="" draggable="false" />
      </div>
      <div class="sidebar-icon-spacer"></div>

      <div class="sidebar-icon-container sidebar-icon-container-active" v-if="current_tool === 'table_of_contents'">
        <img class="sidebar-icon" src="../assets/table_of_contents_active.svg" alt="" draggable="false" />
      </div>

      <div class="sidebar-icon-container" v-on:click="this.current_tool = 'table_of_contents'" v-else>
        <img class="sidebar-icon" src="../assets/table_of_contents.svg" alt="" draggable="false" />
      </div>
      <div class="sidebar-icon-spacer"></div>

      <div class="sidebar-icon-container sidebar-icon-container-active" v-if="current_tool === 'version_control'">
        <img class="sidebar-icon" src="../assets/version_control_active.svg" alt="" draggable="false" />
      </div>

      <div class="sidebar-icon-container" v-on:click="this.current_tool = 'version_control'" v-else>
        <img class="sidebar-icon" src="../assets/version_control.svg" alt="" draggable="false" />
      </div>
      <div class="sidebar-icon-spacer"></div>
    </div>

    <div class="sidebar-widget" v-if="current_tool === 'file_manager'">
      <span class="sidebar-widget-title">FILE MANAGER</span><br/>
    </div>

    <div class="sidebar-divider" />
  </div>
</template>

<script>
  export default {
    data() {
      return {
        name: 'SideBar',
        current_tool: 'file_manager',
      }
    }
  }
</script>

<style scoped>
  .sidebar-layout {
    min-width: 320px;
    max-width: 480px;
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

  .sidebar-icon-container {
    background-color: var(--background);
    width: 48px;
    height: 48px;
    border: 0px solid var(--background);
    border-radius: 7px;
    display: flex;
    flex-direction: row;
    flex-wrap: nowrap;
    align-content: center;
    justify-content: center;
    align-items: center;
  }

  .sidebar-icon-container-active {
    background-color: var(--primary) !important;
    border: 0px solid var(--primary) !important;
  }

  .sidebar-icon {
    width: 32px;
    height: 32px;
  }

  .sidebar-icon-spacer {
    background: transparent;
    width: 100%;
    height: 12px;
  }

  .sidebar-widget {
    padding-left: 12px;
    padding-right: 24px;
    flex-grow: 1;
  }

  .sidebar-widget-title {
    color: var(--primary);
    font-size: 16px;
    font-family: sans-serif;
    font-weight: bold;
  }
</style>