<template>
    <div id='nav-bar' class="nav-bar " >
        <nav-bar-brand  :brandName="BrandName"/>
        <nav-bar-item v-for="item in Items" :key="item.id"  :displayName="item.name" :item="item">  </nav-bar-item>
    </div>
</template>

<script lang="ts">
//import { Component, Prop, Vue } from "vue-property-decorator";
import NavBarItem from "@/components/ui/nav-bar/nav-bar-item.vue";
import NavBarBrand from "@/components/ui/nav-bar/nav-bar-brand.vue"

export default {
    name : "NavBarBrand",
    data () {
                return{
                    Items : [
                        {id :"1", name : "Item 1", iconname : "power" ,url: "/home"},
                        {id :"2", name : "Item 2", iconname : "power" ,url: "/about"},
                        {id :"3", name : "Item 3", iconname : "power" ,url: "/login"},
                        {id :"4", name : "Item 4", iconname : "power" ,url: "#"},
                        {id :"5", name : "Item 5", iconname : "power" ,url: "#"},
                        {id :"6", name : "Item 6", iconname : "power" ,url: "#"},
                    ],
                    BrandName : "WiFi Home - Smart"
                }
            },

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