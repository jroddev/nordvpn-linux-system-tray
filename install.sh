#!/bin/bash

echo "Generating make files with qmake" 
qmake
echo "Build nordvpn-linux-system-tray application"
make
cp nordvpn-system-tray /usr/sbin/
cp nordvpn-system-tray.service /usr/lib/systemd/system/

echo "Create init file for service"
SERVICE_CONF_DIR=/usr/lib/systemd/system/nordvpn-system-tray.service.d/
mkdir -p $SERVICE_CONF_DIR
SERVICE_INIT_FILE=$SERVICE_CONF_DIR/init.sh
echo "export XAUTHORITY=$XAUTHORITY" > $SERVICE_INIT_FILE
chmod 755 $SERVICE_INIT_FILE

echo "copying icons to /usr/share/pixmaps"
cp nordvpn-icon-connected.png /usr/share/pixmaps/
cp nordvpn-icon-disconnected.png /usr/share/pixmaps/

systemctl daemon-reload
systemctl start nordvpn-system-tray.service
systemctl enable nordvpn-system-tray.service