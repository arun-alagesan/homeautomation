import Vue from "vue";
import Vuex from "vuex";

Vue.use(Vuex);

export default new Vuex.Store({
  state: {
    appTitle : "My Smart Home",
    appLogoUri : "",
    appLogoBase64 : "",
    navBarItems : [
        {id :"1", name : "Home", iconname : "power" ,url: "/home"},
        {id :"2", name : "Our Services", iconname : "power" ,url: "/about"},
        {id :"3", name : "Contact us", iconname : "power" ,url: "/login"},
        {id :"4", name : "Menu One", iconname : "power" ,url: "#"},
        {id :"5", name : "Favourets", iconname : "power" ,url: "#"},
        {id :"6", name : "Log In", iconname : "power" ,url: "#"},
    ],
  },
  mutations: {},
  actions: {},
  modules: {}
});
