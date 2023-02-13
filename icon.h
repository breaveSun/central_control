#ifndef ICON_H
#define ICON_H
#include <QMap>

class icon
{
public:
    icon();
    static QMap<QString,QString> getMap();
    static QString getIcon(QString name);
private:
    static void init();
    static QMap<QString,QString> iconMap;
};

#endif // ICON_H
