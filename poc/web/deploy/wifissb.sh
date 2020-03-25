#!/bin/bash
printf "clean wifis on deploy folder \n"
echo "---------------------------- "
rm -rv /Library/WebServer/Documents/iot/wifissb

echo " "
printf "copy wifis to deploy folder \n"
echo "---------------------------- "
cp -rv ../wifissb /Library/WebServer/Documents/iot/wifissb