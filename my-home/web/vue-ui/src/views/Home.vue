<template>
  <div class="home">
    <switch-panel></switch-panel>
  </div>
</template>

<script>
// @ is an alias to /src
import SwitchPanel from "@/components/ui/switch/switch-panel.vue";

export default {
  name: "Home",
  components: {
    "switch-panel": SwitchPanel
  }
};
</script>
