#include "NordNpnSystemTrayIconHandler.h"

#include <QtWidgets/QApplication>
#include <QtCore/QDebug>

NordVpnSystemTrayIconHandler::NordVpnSystemTrayIconHandler():
    connectedIcon(32,32, ICON_DIRECTORY + "/nordvpn-icon-connected.png"),
    disconnectedIcon(32,32, ICON_DIRECTORY + "/nordvpn-icon-disconnected.png") {
    bool error = false;

    trayIcon = std::make_unique<QSystemTrayIcon>(disconnectedIcon.getIcon());
    if (!trayIcon->isSystemTrayAvailable()){
        qDebug() << "System Tray Unavailable";
        error = true;
    }

    if (connectedIcon.getIcon().isNull()){
        qDebug() << "Could not find nordvpn-icon-connected.png in " << ICON_DIRECTORY.c_str();
        error = true;
    }

    if (disconnectedIcon.getIcon().isNull()){
        qDebug() << "Could not find nordvpn-icon-disconnected.png in " << ICON_DIRECTORY.c_str();
        error = true;
    }

    if (error == true) {
        qDebug() << "One or more errors occured on startup";
        QApplication::exit(1);
    } else {
        trayIcon->setVisible(true);
    }
}


void NordVpnSystemTrayIconHandler::update() {
    QProcess process;
    process.start("nordvpn status");
    process.waitForFinished();
    auto status = QString{process.readAllStandardOutput()};
    const auto newConnectionState = status.contains("Connected");
    if (connected != newConnectionState){
        qDebug() << "NordVPN status changed: " << connected << " -> " << newConnectionState;
        connected = newConnectionState;
        if (connected){
            trayIcon->setIcon(connectedIcon.getIcon());
        } else {
            trayIcon->setIcon(disconnectedIcon.getIcon());
        }
    }


}
