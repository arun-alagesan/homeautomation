import Vue from "vue";
import Vuex from "vuex";

Vue.use(Vuex);

export default new Vuex.Store({
  state: {
    appTitle : `My Smart Home`,
    appLogoUri : "",
    appLogoBase64 : "",
    authenticated : false,
    verison: process.env.VUE_APP_VERSION,
    navBarItems : [
        {id :"1", name : "Home", iconname : "power" ,url: "/home"},
        {id :"2", name : "Services", iconname : "power" ,url: "#"},
        {id :"3", name : "Our Team", iconname : "power" ,url: "#"},
        {id :"4", name : "Contact us", iconname : "power" ,url: "/about"},
        {id :"5", name : "Portfolio", iconname : "power" ,url: "#"},
        {id :"6", name : "Log In", iconname : "power" ,url: "/login"},
    ],
  },
  mutations: {},
  actions: {},
  modules: {}
});
