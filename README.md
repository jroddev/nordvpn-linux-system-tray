
# NordVPN Status Tray Icon

_**This project was not created by NordVPN**_

![Example](/icon-in-action.png)

A small service that displays the nordvpn connection status in the system tray.  
The icon will display blue when connected and red in any other state.

## Requirements
- NordVPN CLI (https://nordvpn.com/download/linux/)
- qt5
- Desktop Environment (tested with KDE Plasma)

## Installation
- ./install.sh

------
Icons are stored in /usr/share/pixmaps/  
Executable is stored in /usr/sbin/  
Auto start-up is done via user based systemd  

------


## Uninstall
- ./uninstall.sh

