<template>
  <div id="app">
    <header>
      <nav-bar-brand :brandName="this.$store.state.appTitle"/>
       <div ref="menuToggle" @click="showMenu" class="menu-toggle " v-bind:class="{active : isActive}"> <!--&#x2630; &#x2715;--> </div>  
      <nav-bar  ></nav-bar>
      <div class="clearfix"></div>
    </header>
    
    
    <router-view v-on:setAuthenticated = "setAuthenticated" />
  </div>
</template>

<style lang="scss">

#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  margin:0 auto;
  padding: 0;
  max-width: 1200px;
  background-color : rgb(17, 17,17);
  
  color : rgb(241, 163,73)
}

header{
  position: relative;
  max-width: 1200px;
  margin : 20px;
  padding: 10px auto;
  background-color:  rgb(17, 17,17);
  box-sizing: border-box;
  border-radius: 4px;
  color : #fff;

  .menu-toggle{
    display: none;
  }

  @media (max-width: 1200px) {
    margin:20px;
  }

  @media (max-width: 768px) {

    .menu-toggle{
        display:block;
          width: 40px;
          height: 40px;
          margin: 10px;
          float: right;
          cursor: pointer;
          font-size: 36px;
          font-weight: 700;
          color:rgb(241, 163,73);
          text-align : center;

          
    }

    .menu-toggle::before{
      content: '\2630';
      position: relative;
      line-height: 40px;
    }

    .menu-toggle.active::before{
            content: '\2715';
            position: relative;
            line-height: 40px;
          }

  }

}

.clearfix{
  clear: both;
}


</style>
<script>
import NavBar from "@/components/ui/nav-bar/nav-bar.vue"
import NavBarItem from "@/components/ui/nav-bar/nav-bar-item.vue"
import NavBarBrand from "@/components/ui/nav-bar/nav-bar-brand.vue"

import {EventBus} from "../src/events/events"

export default {
  name : 'app',
  data() {
    return{
      authenticated : false,
      isActive : false
    }
  },
  components : {
    'nav-bar' : NavBar,
    'nav-bar-brand' : NavBarBrand
  },
  methods: {
    setAuthenticated : function (status){
      this.authenticated = status;
      console.log ("setAuthenticated : " + status);
    },
    logout(){
      this.authenticated = false;
    },
    showMenu(){
      this.isActive = !this.isActive
      console.log ("Emeting event : " + this.isActive )
      EventBus.$emit('showMenu', this.isActive);
    }
  },

  mounted () {
    if(!this.authenticated)
    {
      this.$router.replace({name : 'Login'});
    }
  }

}
</script>