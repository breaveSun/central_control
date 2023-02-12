#ifndef COMMON_H
#define COMMON_H
#include <QString>
#include <iostream>
#include <qdebug.h>
#include <QFont>
#include <QFontDatabase>

enum  EquipmentSwitch {
    ES_LOST_CONTACT,  //断开连接
    ES_ON,//开启
    ES_OFF//关闭
};

enum PageBack {
    PB_GO_HOME,
    PB_GO_LIGHT_PAGE,
    PB_GO_CURTAIN_PAGE
};
class Common{
public:
    static QFont loadIcon(int size){
        //加入字体，并获取字体ID
        int fontId = QFontDatabase::addApplicationFont(":/resource/iconfont.ttf");
        //获取字体名称
        QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont iconFont = QFont(fontName);
        iconFont.setPixelSize(size);
        return iconFont;
    }
};

#endif // COMMON_H
