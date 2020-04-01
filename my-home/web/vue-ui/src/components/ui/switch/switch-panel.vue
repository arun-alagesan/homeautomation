<template>
    <div class="switch-panel" >
    </div>
</template>

<script lang="ts">
    export default {
        
        name : 'SwitchPanel',

        created (){
            console.log("SwitchPanel - Created")
        }

    }
</script>

<style lang="scss" scoped>
    .switch-panel{
        margin:1em;
        padding :0; 
        border:1px solid red;
        display: flex;
        flex-flow: row wrap;
        justify-content:space-evenly;
    }
</style>