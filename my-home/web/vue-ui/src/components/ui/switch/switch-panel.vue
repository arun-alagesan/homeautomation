<template>
   <div >
       <div style="display:flex; flex-flow: row wrap; justify-content:space-evenly; ">
           <div style="padding:10px">
            <button style="width:120px;height:40px;" value="Swipe" @click="SetButtonType('swipe-switch')"> Swipe </button>
           </div>
           <div style="padding:10px">
            <button style="width:120px;height:40px;" value="Toggle" @click="SetButtonType('toggle-switch')" > Toggle </button>
           </div>
       </div>
       
        <div class="switch-panel">
            
                 <component  v-for="item in this.switches" :key="item.id"  :is="item.type" :controldata="item"   />
            
        </div>
        
    </div>
</template>

<script >
    import swipe from "@/components/ui/switch/switch-wifi-swipe.vue";
    import Toggle from "@/components/ui/switch/switch-wifi-toggle.vue";

    export default {
        
        name : 'SwitchPanel',

        data(){
            return{
                switchType : 'swipe-switch',
                switches : [
                    { id: '0', name:'Hall Light', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '1', name:'Bedroom Fan', icon:'power-off', state:0, type:'toggle-switch'},
                    { id: '2', name:'Hall Fan', icon:'power-off', state:1, type:'swipe-switch'},
                    { id: '3', name:'Outdoor Light', icon:'power-off', state:1, type:'toggle-switch'},
                    { id: '4', name:'Bedroom Fan', icon:'power-off', state:0, type:'swipe-switch'},
                    { id: '5', name:'Bathroom Light', icon:'power-off', state:1, type:'toggle-switch'},
                    { id: '6', name:'Kitchen Light', icon:'power-off', state:0, type:'toggle-switch'}
                ]
            }
        },

        created (){
            console.log("SwitchPanel - Created")
        },

        components:{
            'swipe-switch' : swipe,
            'toggle-switch' : Toggle
        },
        
        methods:{
            SetButtonType : function(e){
                console.log(e);
                this.switchType = e;
                this.switches.every(item => item.type = e);
            }
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