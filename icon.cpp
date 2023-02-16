#include "icon.h"
#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QDebug>
QMap<QString,int> icon::iconMap = QMap<QString,int>();

icon::icon()
{

}
QMap<QString,int> icon::getMap(){
    if(iconMap.size()==0){
        init();
    }
    return iconMap;
}
int icon::getIcon(QString name){
    if(iconMap.size()==0){
        init();
    }
    if(iconMap.find(name)!=iconMap.end()){
        return iconMap[name];
    }
    return 0;
}
void icon::init(){
    QFile file(":/resource/iconfont.json");	//创建QFile对象，并指定json文件路径
    //打开json文件并判断（不成功则返回0）
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"json file load err";
        return;
    }
    //将文件内容读取到数组中
    QByteArray data(file.readAll());
    file.close();	//关闭文件
    QJsonParseError jError;	//创建QJsonParseError对象
    //使用QJsonDocument的fromJson函数读取json串，并将QJsonParseError对象传入获取错误值
    QJsonDocument jDoc = QJsonDocument::fromJson(data, &jError);
    //判断QJsonParseError对象获取的error是否包含错误，包含则返回0
    if(jError.error != QJsonParseError::NoError)
    {
        qDebug()<<"json err";
        return;
    }
    if(!jDoc.isObject()){
        qDebug()<<"json format err";
        return;
    }
    QVariantMap map = jDoc.toVariant().toMap();
    QVariantList list = map["glyphs"].toList();
    for (int i=0;i<list.size();i++){
        QVariantMap iconVM = list[i].toMap();
        QString key = iconVM["name"].toString();
        int value = iconVM["unicode_decimal"].toInt();
        iconMap[key] = value;
    }
}
