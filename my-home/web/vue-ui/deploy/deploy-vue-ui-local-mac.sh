#!/usr/bin/env sh

# abort on errors
set -e

# build
npm run build-mac

pwd


# copy the dist folder to default document root
if [ -d /Library/WebServer/Documents/iot/my-home ]  ; then
 printf "clean my-home on deploy folder \n"
 echo "---------------------------- "
 sudo rm -rv /Library/WebServer/Documents/iot/my-home
fi

 echo " "
 printf "copy dist to deploy folder my-home \n"
 echo "---------------------------- "
 yes | sudo cp -rv dist /Library/WebServer/Documents/iot/my-home

 printf "deployment done to folder my-home \n"
 echo " "
 echo "launch $(tput setaf 6) http://localhost/iot/my-home $(tput sgr0) "
 echo "---------------------------- "