<template>
    <div class="toggle"> 
        <div class="control" :class="{on : checked}">
            <input type="checkbox" name="control-state" id="" data-value='all' :checked="checked" @change="controlChanged($event)" />
                    
            <div class="control-name">{{name}}</div>

            <div class="control-switch" >
                <div class="control-icon center">
                    <i class="fa fa-power-off"> </i>
                </div>
            </div>
            
            <div class="control-state-display" :class="{on : checked}" >{{ checked == 1 ? " On " : " Off "}}</div>
        </div>
    </div>
</template>
<script>
export default {

    name : "Toggle",

    props :[
        'controldata'
    ],

    data(){
        return{
            name : this.controldata.name,
            checked : this.controldata.state
        }
    },

    created(){
        const msg = `Toggle Switch - ${this.name} created state - ${this.checked}`;
        console.log(msg)
    },

    methods:{
        controlChanged (e){
            this.checked = !this.checked;
            const msg = `Control name : " ${this.name} state : ${ this.checked} `;
            console.log (msg);
        }
    }    
}
</script>
<style lang="scss" scoped>

 
.toggle{
    border:0px solid green;
    margin :.25em;
    background-color: #292929;
    width: 10em;
    padding:.75em;
    border-radius: .5em;

     color : #ff0000;
                text-shadow : 0 0 15px #FF0800,
                              0 0 30px #FF0800;
    
    .on
    {
        color : #00FF00;
        text-shadow : 0 0 15px #00FF08,
                      0 0 30px #00FF08;
     }

    .control{
        border:0px solid blue;
        text-align: center; 
    
        position: relative;

        input[type=checkbox]{
            -webkit-appearance: none;
            position:absolute;
            z-index:999;
            width:100%;
            height:100%;
            top:0;
            left:0;
            margin: 0;
            padding: 0;

            &:focus{
                outline: none;
            }

            &:checked ~ .control-switch{

                .control-icon{
                    box-shadow : 0 0 0 rgba(0,0,0,1),
                    inset 0 -2px 5px rgba(0,0,0,1),
                    inset 0 1px 1px rgba(255,255,255,.1),
                    0 0 0 2px #000,
                    0 0 0 5px #00ff08,
                    0 0 0 5.5px #00ff08;
                }

            }

        }

        .control-name
        {
            border:0px solid red;
            color : white;
            padding: .25em; 
        }

        .control-state-display{
            padding: .25em; 
            font-size: 2em;
            line-height: 1em;
            text-transform: uppercase;
            letter-spacing: .25em;
            margin-top :1em;
        }

        .control-switch{
            border:0px solid orange;
            height: 7rem;
            padding: .25em;

            .control-icon{
                background:#1b1b1b;
                border-radius: 50%;
                padding:.75em;
                font-size : 2em;

                box-shadow : 0 3px 4px rgba(0,0,0,1),
                 inset 0 -2px 5px rgba(0,0,0,1),
                 inset 0 2px 2px rgba(255,255,255,.5),
                 0 0 0 2px #000,
                 0 0 0 5px #FF0000,
                 0 0 0 5.5px #FF0000;

            }
            .center{
                position: absolute;
                top:50%;
                left: 50%;
                transform: translate(-50%,-50%);
            }
       
        }
    }

}

</style>