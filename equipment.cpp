#include "equipment.h"

#include <fstream>
#include <iostream>
#include <QVariantList>
#include <QFile>
#include <QJsonParseError>
#include <QJsonArray>
#include <QDebug>
#include <QMessageBox>
#include <errno.h>

QVariantList equipment::houses_ = QVariantList();
equipment::equipment()
{
}

QVariantList equipment::getEquipment(){
    if (houses_.size() == 0){
        init();
    }
    return houses_;
}

QVariantMap equipment::getRoom(int houseId,int spaceId,int roomId){
    QVariantList houses = getEquipment();
    QVariantList spaces;
    for(int i = 0; i < houses.size(); ++i) {
        QVariantMap houseMap = houses[i].toMap();
        int id = houseMap["id"].toInt();
        if (houseId == id){
            spaces = houseMap["spaces"].toList();
        }
    }
    QVariantList rooms;
    for(int i = 0; i < spaces.size(); ++i) {
        QVariantMap spaceMap = spaces[i].toMap();
        int id = spaceMap["id"].toInt();
        if (spaceId == id){
            rooms = spaceMap["rooms"].toList();
        }
    }
    QVariantMap room;
    for(int i = 0; i < rooms.size(); ++i) {
        room = rooms[i].toMap();
        int id = room["id"].toInt();
        if (roomId == id){
            break;
        }
    }
    return room;
}

bool equipment::init()
{
    QFile file(":/resource/config.json");	//创建QFile对象，并指定json文件路径
    //打开json文件并判断（不成功则返回0）
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"json file load err";
        return 0;
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
        return false;
    }
    if(!jDoc.isArray()){
        qDebug()<<"json format err";
        return false;
    }

    //获取QJsonObject，并读取Json串中各类型的值
    QJsonArray jArray = jDoc.array();
    //将QJsonArray转QVariantList
    QVariantList list = jArray.toVariantList();

    if(list.size()<=0){
        qDebug()<<"no json data";
        return false;
    }
    houses_ = list;
    return true;
}
