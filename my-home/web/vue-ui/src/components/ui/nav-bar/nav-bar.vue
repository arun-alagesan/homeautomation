<template>
    <nav  class="" v-bind:class="{active : showMe.isActive }"   >
        <!--
        data value set to isActive from the event : {{isActive}} <br/>
        data value set to show from the event : {{show}} <br/>
        Property set by the parent component {{showMe}} <br/>
        -->
        <ul>
            <nav-bar-item v-for="item in this.$store.state.navBarItems" :key="item.id"  :item="item" >  </nav-bar-item>
        </ul>            
    </nav>
</template>

<script>

import navBarItems from "@/components/ui/nav-bar/nav-bar-item.vue";
import { EventBus } from "@/events/events";

export default {
    
    name : 'NavBar',
    props:[
        'showMe' 
    ],

    data () {
        return {
            isActive : false,
            show : false
        }
    },
    methods : {
        showNavbarMenu : function (val){
            this.isActive = val;
            this.show = val;
            console.log("ShowNavBarMenu : isActive = " + this.isActive );
        }
    },
    created() {
        EventBus.$on("showMenu" , function (state) {
            console.log("event received - showMenu :" + state);
            this.isActive = state;
            this.show = state;
        } );
    },
    components : {
        'nav-bar-item' : navBarItems
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

</style>