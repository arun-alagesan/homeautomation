<template>
    <div class="swipe"> 
        <div class="control">
            <div class="control-name">{{name}}</div>

            <div class="control-switch" :class="{on : checked}"><div class="control-icon center"><i class="fa fa-3x fa-power-off"> </i></div></div>
            
            <div class="control-state"><input type="checkbox" name="control-state" id="" data-value='all' :checked="checked" @change="controlChanged($event)" /></div>
        </div>
    </div>
</template>
<script>
export default {
    name : 'Swipe',
    props:[
        'controldata' 
    ],
    data(){

        return{
            name : this.controldata.name,
            checked : this.controldata.state
        }

    },
    methods:{
        controlChanged : function(e){
            this.checked = !this.checked;
            console.log ("Control name : " + this.name + " state :" + this.checked );
        }
    },
    created() {
        console.log("Swipe Switch created for :" + this.name);
    },
}
</script>
<style lang="scss" scoped>
.swipe{
    border:0px solid green;
    margin :.25em;
    background-color: #292929;
    width: 10em;
    padding:.75em;
    border-radius: .5em;

    .control{
    border:0px solid blue;
    text-align: center; 
    color:black; 
    
        .control-name
        {
            border:0px solid red;
            color : white;
            padding: .25em; 
        }

        .on{
                color: orange;
        }

        .control-switch{
            border:0px solid orange;
            position: relative;
            height: 7rem;
            padding: .25em;

            .control-icon{
                background-color: #666;
                border-radius: 50%;
                padding:.75em;
            }
            .center{
                position: absolute;
                top:50%;
                left: 50%;
                transform: translate(-50%,-50%);
            }
       
        }

        .control-state{
            border:0px solid red;
            color:red;
            padding : .25em;
            margin: 0;

            input[type=checkbox]{
                color:red;
                padding :.25em;
                border: 0px solid greenyellow;
                -webkit-appearance: none;
                position: relative;
                width: 100%;
                height: 40px;
                padding :0;
                margin: 0;
                border-radius: 20px;
                background: linear-gradient(0deg,#333,#000);
                outline: none;
                box-shadow: 0 0 0 4px #353535, 
                            0 0 0 5px #3e3e3e,
                            inset 0 0 10px  rgba(0,0,0,1),
                            0 5px 20px rgba(0,0,0,.5),
                            inset 0 0 15px rgba(0,0,0,.2);

            
                &:before{
                    content: '';
                    position: absolute;
                    top :0;
                    left: 0;
                    width: 80%;
                    height: 40px;
                    border-radius: 20px;
                    background : linear-gradient(0deg, #000, #6b6b6b);
                    box-shadow: 0 0 0 1px #232323;
                    transform: scale(.96,.98);
                    transition: .25s;
                    
                }
                &:after{
                    content: '';
                    position: absolute;
                    top :calc(50% - 2px);
                    left: 60%;
                    width: 4px;
                    height: 4px;
                    border-radius: 50%;
                    background : linear-gradient(0deg,#6b6b6b,#000);
                    transition: .25s;
                }  


                &:checked{
                    background: linear-gradient(0deg,orange,orange);
                    box-shadow: 0 0 2px orange,
                                0 0 0 4px #353535, 
                                0 0 0 5px #3e3e3e,
                                inset 0 0 10px  rgba(0,0,0,1),
                                0 5px 20px rgba(0,0,0,.5),
                                inset 0 0 15px rgba(0,0,0,.2);

                    &:after{
                        left: 80%;
                        background : linear-gradient(0deg, orange, orange);
                    }

                    &:before{
                        left : 20%;
                    }
                }

            }
        }
       
    }
}
</style>