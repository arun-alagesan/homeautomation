<template>
    <div class="log-in-form">
        <!-- <avatar> 
        </avatar>-->
        <h2> Login </h2>
        <form @submit.prevent="">
            <div class="input-box">
                <input type="text" required="" v-model="input.username">
                <label> User Name </label>
            </div>
            <div class="input-box">
                <input type="password" required ="" v-model="input.secret">
                <label> Secret Word </label>
            </div>
            <input type="submit" value="Submit" v-on:click="doLogin" />
        </form>
    </div>
</template>

<script type="ts">    
    export default {
        name:'login',
       
        data () {
            return{
                input: {
                    username : "",
                    secret : ""
                }
            }
        },
        methods: {
            doLogin(event){
                event.preventDefault;
                if(this.input.username != "" && this.input.secret !="")
                {
                    if (this.input.username == 'arun' && this.input.secret == 'danger123')
                    {
                        this.$emit('setAuthenticated' , 'true');
                        this.$parent.authenticated = true;
                        this.$router.replace({ name :"Home"});
                    }
                    else
                    {
                        alert("You have entered a wrong credentials");
                        event.preventDefault;
                    }
                }
                else{
                    alert("You have not entered either your username or secret word(s) ");
                }

            }
        }

    };
</script>

<style lang="scss" scoped>
    .log-in-form{
        position: absolute;
        top : 50%;
        left : 50%;
        transform : translate(-50%,-50%);
        width: 400px;
        background : rgba(0,0,0,.8);
        box-sizing: border-box;
        box-shadow: 0 15px 25px rgba(241, 163,73,.5);
        border-radius: 10px;
        padding :40px;
        z-index: 1;

        h2{
            margin : 0 0 30px;
            padding: 0;
            color : rgb(241, 163,73);
            text-align-last: center;
        }

        .input-box{
            position: relative;
            

            input{
                color : #fff;
                width : 100%;
                font-size: 16px;
                padding: 10px 0;
                border: none;
                outline: none;
                background : transparent;
                border-bottom: 1px solid #fff;
                margin-bottom: 30px;
                letter-spacing: 1px;
                
                &:focus ~ label,
                &:valid ~ label
                {
                    top:-18px;
                    left:0;
                    color :rgb(241, 163,73);
                    font-size:12px;
                }

            }
            label{
                position: absolute;
                top:0;
                left:0;
                padding: 10px 0;
                font-size: 16px;
                color: #fff;
                pointer-events: none;
                transition: .5s;
                
            }

        }
        input[type=submit]{
            background: transparent;
            border : none;
            outline : none;
            background :rgb(241, 163,73);
            color : #fff;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
            font-size: 16px;
        }

    }
</style>