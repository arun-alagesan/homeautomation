<template>
  <div id="app">
    <nav-bar></nav-bar>
    <div id="nav">
      <router-link to="/">Home</router-link>
      <router-link to="/about"> | About</router-link>
      <router-link  v-if="authenticated" to="/Login" v-on:click.native="logout" replace> | Logout</router-link>
    </div>
    <router-view v-on:setAuthenticated = "setAuthenticated" />
  </div>
</template>

<style lang="scss">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

#nav {
  padding: 30px;

  a {
    font-weight: bold;
    color: #2c3e50;

    &.router-link-exact-active {
      color: #42b983;
    }
  }
}
</style>
<script>
import NavBar from "@/components/ui/nav-bar/nav-bar.vue"
import NavBarItem from "@/components/ui/nav-bar/nav-bar-item.vue"

export default {
  name : 'app',
  data() {
    return{
      authenticated : false /*,
      Items : [
                        {id :"1", name : "Item 1", iconname : "power" },
                        {id :"2", name : "Item 2", iconname : "power" },
                        {id :"3", name : "Item 3", iconname : "power" },
                        {id :"4", name : "Item 4", iconname : "power" },
                        {id :"5", name : "Item 5", iconname : "power" },
                        {id :"6", name : "Item 6", iconname : "power" }
                    ]*/
    }
  },
  components : {
    'nav-bar' : NavBar,
  },
  methods: {
    setAuthenticated : function (status){
      this.authenticated = status;
      console.log ("setAuthenticated : " + status);
    },
    logout(){
      this.authenticated = false;
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