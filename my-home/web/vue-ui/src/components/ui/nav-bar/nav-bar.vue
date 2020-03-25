<template>
    <div id='nav-bar' class="nav-bar " >
        <nav-bar-brand  :brandName="this.$store.state.appTitle"/>
        <nav-bar-item v-for="item in this.$store.state.navBarItems" :key="item.id"  :item="item">  </nav-bar-item>
    </div>
</template>

<script lang="ts">
//import { Component, Prop, Vue } from "vue-property-decorator";
import NavBarItem from "@/components/ui/nav-bar/nav-bar-item.vue";
import NavBarBrand from "@/components/ui/nav-bar/nav-bar-brand.vue"

export default {
    name : "NavBarBrand",
    components :{
       'nav-bar-item' : NavBarItem,
        'nav-bar-brand' : NavBarBrand
    }
}
</script>
<style lang="scss" scoped>

#nav-bar {
    border : 1px solid red;
    background-color : orange;
    padding: 1em;
    margin: 0;
    text-align: left;
    display: flex;
    flex-flow: row wrap;
}

</style>