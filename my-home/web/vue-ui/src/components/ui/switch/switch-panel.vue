<template>
    <div class="switch-panel">
        <component  v-for="item in this.switches" :key="item.id"  :is="item.type" :controldata="item"   />
    </div>
</template>

<script lang="ts">
    import swipe from "@/components/ui/switch/switch-wifi-swipe.vue";

    export default {
        
        name : 'SwitchPanel',

        data(){
            return{
                switchType : 'swipe-switch',
                switches : [
                    { id: '0', name:'Light 1', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '1', name:'Light 2', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '2', name:'Light 3', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '3', name:'Light 4', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '4', name:'Light 5', icon:'power-off', state:0, type:'swipe-switch'}
                ]
            }
        },

        created (){
            console.log("SwitchPanel - Created")
        },

        components:{
            'swipe-switch' : swipe
        }

    }
</script>

<style lang="scss" scoped>
    .switch-panel{
        margin:0em;
        padding:0em; 
        border:0px solid red;
        display: flex;
        flex-flow: row wrap;
        justify-content:space-evenly;
    }
</style>