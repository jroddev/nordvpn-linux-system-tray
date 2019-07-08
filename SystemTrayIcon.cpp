#include "SystemTrayIcon.h"


SystemTrayIcon::SystemTrayIcon(int width, int height, std::string imagePath): iconImage{width, height}
{
    iconImage.load(imagePath.c_str());
    icon.addPixmap(iconImage);
}

const QIcon& SystemTrayIcon::getIcon() const {
    return icon;
}
