<template>
    <!--<div id='nav-bar-brand' class="nav-bar-brand" name="nav-bar-brand" > {{brandName}}</div>-->
    <a class="nav-bar-brand" id='nav-bar-brand' href="#" >{{brandName}}</a>
</template>

<script lang="ts">

export default {

   name : 'NavBarBrand',

    props :{
       brandName :String
    }

    
}
</script>
<style lang="scss" >

#nav-bar-brand {
   color : rgb(241, 163,73);
   height : 60px;
   font-size:36px;
   line-height: 60px;
   padding: 0 20px;
   text-align: center;
   box-sizing: border-box;
   float:left;
   text-decoration: none;
   font-weight: 700;
   
   @media (max-width: 768px ) {

      font-size: 26px;
      height : 40px;
      line-height: 40px;
      padding: 0;
      margin : 10px
      
   }
}

</style>