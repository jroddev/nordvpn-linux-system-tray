#ifndef NORDVPNSYSTEMTRAYICON_H
#define NORDVPNSYSTEMTRAYICON_H

#include <memory>
#include <string>

#include <QtWidgets/QMenu>
#include <QtWidgets/QSystemTrayIcon>
#include <QProcess>

#include "SystemTrayIcon.h"

class NordVpnSystemTrayIconHandler
{
private:
    const std::string ICON_DIRECTORY = "/usr/share/pixmaps";
    std::unique_ptr<QMenu> contextMenu;
    std::unique_ptr<QSystemTrayIcon> trayIcon;
    SystemTrayIcon connectedIcon;
    SystemTrayIcon disconnectedIcon;
    bool connected = false;

public:
    NordVpnSystemTrayIconHandler();
    void update();
};

#endif // NORDVPNSYSTEMTRAYICON_H
