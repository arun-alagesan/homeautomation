<template>
    <nav  class="" v-bind:class="{active : show}"  >
        <ul>
            <nav-bar-item v-for="item in this.$store.state.navBarItems" :key="item.id"  :item="item" >  </nav-bar-item>
        </ul>            
    </nav>
</template>

<script lang="ts">
    import NavBarItem from "@/components/ui/nav-bar/nav-bar-item.vue";
    import NavBarBrand from "@/components/ui/nav-bar/nav-bar-brand.vue";
    import {EventBus} from "../../../events/events";
  
    export default {

        name : "NavBar",
        data() {
                return {
                show : false,
                authenticated : false,
                isActive : false
                }
            },

        components: {
        'nav-bar-item' : NavBarItem
        },
        methods:{
            showMenuPanel : function(data : boolean){
             alert('hi' + data);
             this.isActive = data;
            }
        },
        mounted(){

            this.authenticated = true;
            console.log ('created', this);

            /* EventBus.$on('showMenu', (datavalue) =>  {
                console.log( "Event received : " + datavalue);
                this.showNav = datavalue;
                //showMenu('Arun');
                }); */

            //this.showMenu(true);
                

        }

    }
</script>
<style lang="scss" scoped>

    nav{
        float :right;

        ul{
            margin:0;
            padding: 0;
            display: flex;
        }


        @media (max-width: 768px){

            width: 100%;
            text-align: center;

            ul {
                
                display: none;
                position: relative;
                width: 100%;

                
            }

            &.active{
                ul{
                    display: block;
                    width: 100%;
                }
            }
        }
    }


    /* #nav-bar {
        border : 1px solid red;
        background-color : orange;
        padding: 1em;
        margin: 0;
        text-align: left;
        display: flex;
        flex-flow: row wrap;
    }
    */
</style>