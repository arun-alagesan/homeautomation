# homeautomation

## Dev branch
![vue-ui CI builds](https://github.com/arun-alagesan/homeautomation/workflows/CI%20builds/badge.svg?branch=dev&event=push)

![vue-ui Dev builds Deploy](https://github.com/arun-alagesan/homeautomation/workflows/vue-ui%20Dev%20builds%20Deploy/badge.svg?branch=dev&event=push)

Demo for vue-ui for the #my-home# project
https://arun-alagesan.github.io/my-home-vue-ui


#### Developement process :

>1. Always checkout a new branch from dev for any improvement or feature work and avoid direct commits to dev as much as possible
>
>2. Create a Pull request to dev branch from the feature branch
>
>3. CI build will kick in and wait for it to complete. Fix any error or build failure 
>
>4. Review and merge the pull request
>
>5. CD job will kick in to build the push the dist folder to demo repo /my-home-vue-ui


## Motivation 
I am living in a 2 story house with a over head tank on top of the second storey. During summner the ground water goes below 60 ft and the water delivery is reduces. It usually take around 20 to 30 minutes to fill up the tank. In contrast during the winter or rainy days the water tank fills up quickly in less than 10 or 8 minutes.   

Now it had become hard for me to do the timing math and turn off the water pump before the water overflows the tank. I had to run up and down to top storey to watch tank filling up and to turn off the water pump. You know Water is so presicous that too a ground water is so so precious, I dont want to do the mistake of spoiling the water.

I looked for a water level monitors that can alert on near filling up situation with the buzzer.. Installing that with running down the power cable from the top of the water tank to the point near the water pump seems to be a not a viable solution.

On thinking very deep on this a spark hit me

>**"_You are genius, you write advance programs on computer and a gadget freak, have all means of connected devices in most advance platform, build application your whole life time for work, What have to done for you? Why not write your own program and command your computer to work for you. You call yourself a Software architect, solving most complex business problems with computer programs.. Whats stopping you to solve your own problem_"**

I needed a device runnning on low energy to constantly measure the water level in the tank and trigger a notification.
Then I searched the internet seeking a similar soul who have had the same problem and how the soul dealt the problem.

Then from the rabit hole I got to know the capablities of the ESP8266 module which carries a Wireless stack on the chip. Programming was compatile with the Ardiuno platform with mostly c++ 

Vola, I shoved up my sleaves and got in to the action and got dirty, burnt my fingers, pulled up my hair when the first prototype was working.

Poor me I looked around to find no one around to see my prototype success.


## System Design

I put accross all my thought of connecting the dots of the Idea

![System Design](https://raw.githubusercontent.com/arun-alagesan/homeautomation/master/docs/resources/Sytem%20Design.png)




  
  

