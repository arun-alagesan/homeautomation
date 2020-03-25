<template>
    <div class="log-in-form">
       <!-- <avatar> 
        </avatar>-->
        <div class="form-input">
            <label>Enter your login name or email address</label>
            <input type=text id='login' placeholder='Enter your login name or email address' v-model="input.username" />
        </div>
        <div class="form-input">
            <label>Enter your password</label>
            <input type=password id='secret' placeholder='Enter your secret word(s)' v-model="input.secret">
        </div>
        <div class="form-input">
            <button value='login' v-on:click="doLogin()"> Enter </button>
            <button value='clear'> Clear </button>
        </div>
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
            doLogin(){

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
                    }
                }
                else{
                    alert("You have not entered either your username or secret word(s) ");
                }

            }
        }

    };
             

    
</script>