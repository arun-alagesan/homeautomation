<template>
    <router-link  v-bind:to="item.url">
    <div id='nav-bar-item' class="nav-bar-item" name="nav-bar-item" > {{item.name}} </div>
    </router-link>
</template>

<script lang="ts">
import { Prop } from 'vue-property-decorator'
//import { Component, Prop, Vue } from "vue-property-decorator";
export default {

   name : 'NavBarItem',
   
   props :{
       item : Object
   }
}
</script>
<style lang="scss" >

#nav-bar-item {
    border : 1px solid green;
    color : white;
    padding: 1em;
    margin: .25em;
}

</style>