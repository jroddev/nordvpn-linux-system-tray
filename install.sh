#!/bin/bash

USER_SYSTEMD_DIR=~/.config/systemd/user
mkdir -p $USER_SYSTEMD_DIR

echo "Stopping any existing nordvpn-system-tray service"
systemctl --user stop nordvpn-system-tray.service

echo "Generating make files with qmake" 
qmake
echo "Build nordvpn-linux-system-tray application"
make


echo "copying icons to /usr/share/pixmaps"
sudo cp nordvpn-icon-connected.png /usr/share/pixmaps/
sudo cp nordvpn-icon-disconnected.png /usr/share/pixmaps/
echo "installing application to /usr/sbin/"
sudo cp nordvpn-system-tray /usr/sbin/

echo "installing service to $USER_SYSTEMD_DIR/"
cp nordvpn-system-tray.service $USER_SYSTEMD_DIR/
echo "Starting nordvpn-system-tray service"
systemctl --user daemon-reload
systemctl --user enable nordvpn-system-tray.service
systemctl --user start nordvpn-system-tray.service