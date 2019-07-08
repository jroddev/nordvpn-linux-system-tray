#include <QtWidgets/QApplication>
#include <QtCore/QDebug>

#include <chrono>
#include <thread>

#include "NordNpnSystemTrayIconHandler.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);

    auto nordvpn = NordVpnSystemTrayIconHandler{};

    std::thread updateThread{[&nordvpn] {
        while(true){
            std::this_thread::sleep_for(std::chrono::seconds(2));
            nordvpn.update();
        }
    }};

    return app.exec();
}
