#!/bin/bash

echo "Generating make files with qmake" 
qmake
echo "Build nordvpn-linux-system-tray application"
make

echo "copying icons to /usr/share/pixmaps"
cp nordvpn-icon-connected.png /usr/share/pixmaps/
cp nordvpn-icon-disconnected.png /usr/share/pixmaps/

