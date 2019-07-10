#!/bin/bash

USER_SYSTEMD_DIR=~/.config/systemd/user

echo "disabling service"
systemctl --user stop nordvpn-system-tray.service
systemctl --user disable nordvpn-system-tray.service
systemctl --user daemon-reload

echo "removing nordvpn-system-tray service"
rm $USER_SYSTEMD_DIR/nordvpn-system-tray.service
sudo rm /usr/sbin/nordvpn-system-tray

echo "removing icons from /usr/share/pixmaps"
sudo rm /usr/share/pixmaps/nordvpn-icon-connected.png
sudo rm /usr/share/pixmaps/nordvpn-icon-disconnected.png

