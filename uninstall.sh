#!/bin/bash

echo "disabling service"
systemctl stop nordvpn-system-tray.service
systemctl disable nordvpn-system-tray.service
systemctl daemon-reload

echo "removing nordvpn-system-tray service"
rm /usr/sbin/nordvpn-system-tray
rm /usr/lib/systemd/system/nordvpn-system-tray.service
rm -rf /usr/lib/systemd/system/nordvpn-system-tray.service.d

echo "removing icons from /usr/share/pixmaps"
rm /usr/share/pixmaps/nordvpn-icon-connected.png
rm /usr/share/pixmaps/nordvpn-icon-disconnected.png

