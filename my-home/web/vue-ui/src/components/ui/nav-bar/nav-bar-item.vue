<template>
    <!-- <router-link  v-bind:to="item.url"> -->
    <li id='nav-bar-item' class="nav-bar-item" name="nav-bar-item" > <a class="" v-bind:href="item.url">{{item.name}}</a> </li>
    <!-- </router-link> -->
</template>

<script lang="ts">

export default {

   name : 'NavBarItem',
   
   props :{
       item : Object
   }
}
</script>
<style lang="scss" >

li{
    list-style: none;

    a{
        display:block;
        margin: 10px 0;
        padding: 10px 20px;
        text-decoration: none;
        color : #fff;

        &.active , &:hover {
            background-color:  rgb(241, 163,73);
            color : #fff;
            transition: .5s;
        }
    }
    
}

/* #nav-bar-item {
    border : 1px solid green;
    color : white;
    padding: 1em;
    margin: .25em;
} */

</style>