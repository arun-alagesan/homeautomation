#!/bin/bash
printf "clean wifis on deploy folder \n"
echo "---------------------------- "
rm -rv /Library/WebServer/Documents/iot/wifis

echo " "
printf "copy wifis to deploy folder \n"
echo "---------------------------- "
cp -rv ../wifis /Library/WebServer/Documents/iot/wifis

