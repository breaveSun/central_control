#ifndef ICON_H
#define ICON_H
#include <QMap>

class icon
{
public:
    icon();
    static QMap<QString,int> getMap();
    static int getIcon(QString name);
private:
    static void init();
    static QMap<QString,int> iconMap;
};

#endif // ICON_H
