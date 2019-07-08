#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <string>
#include <QtGui/QIcon>

class SystemTrayIcon
{
private:
    QPixmap iconImage;
    QIcon icon;

public:
    SystemTrayIcon(int width, int height, std::string imagePath);
    const QIcon& getIcon() const;
};

#endif // SYSTEMTRAYICON_H
