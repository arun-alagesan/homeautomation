<template>
    <div id='nav-bar-brand' class="nav-bar-brand" name="nav-bar-brand" > {{brandName}}</div>
</template>

<script lang="ts">
//import { Prop } from 'vue-property-decorator'
//import { Component, Prop, Vue } from "vue-property-decorator";
export default {

   name : 'NavBarBrand',

   data () {
       return{
           
       }
   },
   
   props :{
       brandName :String
   }

    
}
</script>
<style lang="scss" >

#nav-bar-brand {
    border : 1px solid blue;
    color : black;
    padding: 1em;
    margin: .25em;
}

</style>