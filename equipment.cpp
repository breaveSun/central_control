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
#include <httpserver.h>

QString ADRESS_STR="//192.168.2.2:8888";
QVector<houseStruct> equipment::houses_ = {};
QMap<QString,deviceDataStruct> equipment::deviceDataStructs_ = {};
equipment::equipment()
{
}

QVector<houseStruct>* equipment::getEquipment(){
    if (houses_.size() == 0){
        init();
    }
    return &houses_;
}

roomStruct equipment::getRoom(int houseId,int spaceId,int roomId){
    QVector<spaceStruct> spaces;
    for(int i = 0; i < houses_.size(); ++i) {
        houseStruct houseMap = houses_[i];
        int id = houseMap.id;
        if (houseId == id){
            spaces = houseMap.spaces;
        }
    }
    QVector<roomStruct> rooms;
    for(int i = 0; i < spaces.size(); ++i) {
        spaceStruct spaceMap = spaces[i];
        int id = spaceMap.id;
        if (spaceId == id){
            rooms = spaceMap.rooms;
        }
    }
    roomStruct room;
    for(int i = 0; i < rooms.size(); ++i) {
        room = rooms[i];
        int id = room.id;
        if (roomId == id){
            break;
        }
    }
    return room;
}

spaceStruct equipment::getSpace(int houseId,int spaceId){
    QVector<houseStruct>* houses = getEquipment();
    QVector<spaceStruct> spaces;
    for(int i = 0; i < houses->size(); i++) {
        houseStruct* houseMap = houses[i].data();
        int id = houseMap->id;
        if (houseId == id){
            spaces = houseMap->spaces;
            break;
        }
    }
    spaceStruct spaceMap;
    for(int i = 0; i < spaces.size(); i++) {
        spaceMap = spaces[i];
        int id = spaceMap.id;
        if (spaceId == id){
            break;
        }
    }

    return spaceMap;
}

void equipment::getHouseSpaceName(int &houseId,int &spaceId,QString &houseName,QString &spaceName){
    QVector<houseStruct>* houses = getEquipment();
    QVector<spaceStruct>* spaces = nullptr;
    for(int i = 0; i < houses->size(); ++i) {
        houseStruct* houseMap = houses[i].data();
        int id = houseMap->id;
        if (houseId == 0){
            houseName = houseMap->name;
            houseId = id;
            spaces = &(houseMap->spaces);
            break;
        }
        if (houseId == id){
            houseName = houseMap->name;
            break;
        }
    }
    spaceStruct* spaceMap;
    for(int i = 0; i < spaces->size(); ++i) {
        spaceMap = spaces[i].data();
        int id = spaceMap->id;
        if (spaceId == 0){
            spaceName = spaceMap->name;
            spaceId = id;
            break;
        }
        if (spaceId == id){
            spaceName = spaceMap->name;
            break;
        }
    }

}

void equipment::lightControl(QString data){
    QString url = "http:"+ADRESS_STR+"/knx/light";//http后台地址url
    QString sendMsg = data;//http发送数据组包
    QString strMessage = "";//错误信息
    QString strResult = "";//http响应
    QString thod = "POST";//POST或GET
    qDebug()<<__FUNCTION__<<":"<<data;
    httpServer* httpS = new httpServer();
    httpS->postHttpRequest(url,data);
//    httpServer::SendAndGetText(url,thod,sendMsg,strMessage,strResult);
//    if(strMessage.isEmpty())///HTTP正常响应
//    {
//        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"接收数据 "<<strResult;
//    } else {
//        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"错误信息 "<<strMessage;
//    }
}

void equipment::curtainControl(QString data){
    QString url = "http:"+ADRESS_STR+"/knx/curtain/";//http后台地址url
    QString sendMsg = data;//http发送数据组包
    QString strMessage = "";//错误信息
    QString strResult = "";//http响应
    QString thod = "POST";//POST或GET
    qDebug()<<__FUNCTION__<<data;
    httpServer::SendAndGetText(url,thod,sendMsg,strMessage,strResult);
    if(strMessage.isEmpty())///HTTP正常响应
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"接收数据 "<<strResult;
    } else {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"错误信息 "<<strMessage;
    }
}

void equipment::changeScene(int roomId,QString sceneId){
    QString url = "http:"+ADRESS_STR+"/knx/rooms/"+QString::number(roomId)+"/scenes/"+sceneId;//http后台地址url
    QString sendMsg = "";//http发送数据组包
    QString strMessage = "";//错误信息
    QString strResult = "";//http响应
    QString thod = "PUT";//POST或GET
    httpServer::SendAndGetText(url,thod,sendMsg,strMessage,strResult);
    if(strMessage.isEmpty())///HTTP正常响应
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"接收数据 "<<strResult;
    } else {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"错误信息 "<<strMessage;
    }
}

QMap<QString,QString> equipment::getDeviceData(){
    ///调用示例
    QString url = "http:"+ADRESS_STR+"/knx/";//http后台地址url
    QString sendMsg = "";//http发送数据组包
    QString strMessage = "";//错误信息
    QString strResult = "";//http响应
    QString thod = "GET";//POST或GET
    httpServer::SendAndGetText(url,thod,sendMsg,strMessage,strResult);

    if(strMessage.isEmpty())///HTTP正常响应
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"接收数据 "<<strResult;
        QVariantMap data = Common::StringToVariantMap(strResult);
        if (data.find("data")!=data.end()){
            QVariantMap values= data["data"].toMap();
            QMap<QString,QString> deviceData;
            QVariantMap::iterator i;
            for(i = values.begin();i != values.end();i++){
                    QString key = QString::fromStdString(i.key().toStdString());
                    QString value = i.value().toString();
                    deviceData[key] = value;
            }
            return deviceData;
        }
    }
    else///HTTP通信异常
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"错误信息 "<<strMessage;
    }
    return QMap<QString,QString>{};
}

QVariantList equipment::getConfigData(){
    ///调用示例
    QString url = "http:"+ADRESS_STR+"/base/config";//http后台地址url
    QString sendMsg = "";//http发送数据组包
    QString strMessage = "";//错误信息
    QString strResult = "";//http响应
    QString thod = "GET";//POST或GET
    httpServer::SendAndGetText(url,thod,sendMsg,strMessage,strResult);

    if(strMessage.isEmpty())///HTTP正常响应
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"接收数据 "<<strResult;
        QVariantMap data = Common::StringToVariantMap(strResult);
        if (data.find("data")!=data.end()){
            QVariantList values= data["data"].toList();
            return values;
        }
    }
    else///HTTP通信异常
    {
        qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<"错误信息 "<<strMessage;
    }
    return QVariantList{};
}

bool equipment::init()
{
    QVariantList list;
    list = getConfigData();
    /*QFile file(":/resource/config.json");	//创建QFile对象，并指定json文件路径
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
    QVariantList list = jArray.toVariantList();*/

    if(list.size()<=0){
        qDebug()<<"no json data";
        return false;
    }

    QMap<QString,QString> deviceMap= getDeviceData();
    for(int i=0;i<list.size();i++){
        QVariantMap houseV = list[i].toMap();
        houseStruct houseS;

        if(houseV.find("id") != houseV.end()){
            houseS.id = houseV["id"].toInt();
        }

        if(houseV.find("name") != houseV.end()){
            houseS.name = houseV["name"].toString();
        }

        if(houseV.find("project_id") != houseV.end()){
            houseS.project_id = houseV["project_id"].toInt();
        }

        if(houseV.find("spaces") != houseV.end()){

            QVariantList spacesList = houseV["spaces"].toList();
            QVector<spaceStruct> spacesListS = {};

            for(int s=0;s<spacesList.size();s++){
                QVariantMap spaceV = spacesList[s].toMap();
                spaceStruct spaceS;

                if(spaceV.find("id") != spaceV.end()){
                    spaceS.id = spaceV["id"].toInt();
                }

                if(spaceV.find("name") != spaceV.end()){
                    spaceS.name = spaceV["name"].toString();
                }

                if(spaceV.find("project_id") != spaceV.end()){
                    spaceS.project_id = spaceV["project_id"].toInt();
                }

                if(spaceV.find("build_id") != spaceV.end()){
                    spaceS.build_id = spaceV["build_id"].toInt();
                }

                if(spaceV.find("rooms") != spaceV.end()){

                    QVariantList roomList = spaceV["rooms"].toList();
                    QVector<roomStruct> roomListS = {};
                    roomList.append(roomList[0]);
                    for(int r=0;r<roomList.size();r++){

                        QVariantMap roomV = roomList[r].toMap();
                        roomStruct roomS = {};

                        if(roomV.find("id") != roomV.end()){
                            roomS.id = roomV["id"].toInt();
                        }

                        if(roomV.find("name") != roomV.end()){
                            roomS.name = roomV["name"].toString();
                        }

                        if(roomV.find("project_id") != roomV.end()){
                            roomS.project_id = roomV["project_id"].toInt();
                        }

                        if(roomV.find("build_id") != roomV.end()){
                            roomS.build_id = roomV["build_id"].toInt();
                        }

                        if(roomV.find("space_id") != roomV.end()){
                            roomS.space_id = roomV["space_id"].toInt();
                        }

                        if(roomV.find("icon") != roomV.end()){
                            roomS.icon = roomV["icon"].toString();
                        }

                        if(roomV.find("current_scene") != roomV.end()){
                            roomS.current_scene = roomV["current_scene"].toString();
                        }

                        /*if(roomV.find("param") != roomV.end()){
                            QVariantList params = roomV["param"].toList();
                            QVector<roomParamStruct> roomParamList;
                            for(int p=0;p<params.size();p++){
                                QVariantMap roomParamV = params[p].toMap();
                                roomParamStruct roomParamS = {};

                                if(roomParamV.find("name") != roomParamV.end()){
                                    roomParamS.name = roomParamV["name"].toString();
                                }

                                if(roomParamV.find("title") != roomParamV.end()){
                                    roomParamS.title = roomParamV["title"].toString();
                                }

                                if(roomParamV.find("value") != roomParamV.end()){
                                    roomParamS.value = roomParamV["value"].toString();
                                }

                                if(roomParamV.find("unit") != roomParamV.end()){
                                    roomParamS.unit = roomParamV["unit"].toString();
                                }
                                roomParamList.push_back(roomParamS);
                            }

                            roomS.params = roomParamList;
                        }*/
                        QVector<roomParamStruct> roomParamList;
                            roomParamStruct roomParamS2 = {};
                            roomParamS2.name = "temp";
                            roomParamS2.title = "温度";
                            roomParamS2.value = "26";
                            roomParamS2.unit = "°C";
                            roomParamList.push_back(roomParamS2);
                            roomParamStruct roomParamS3 = {};
                            roomParamS3.name = "humidity";
                            roomParamS3.title = "湿度";
                            roomParamS3.value = "52";
                            roomParamS3.unit = "%rh";
                            roomParamList.push_back(roomParamS3);
                            roomParamStruct roomParamS1 = {};
                            roomParamS1.name = "CO₂";
                            roomParamS1.title = "CO₂";
                            roomParamS1.value = "560";
                            roomParamS1.unit = "ppm";
                            roomParamList.push_back(roomParamS1);
                            roomParamStruct roomParamS4 = {};
                            roomParamS4.name = "PM25";
                            roomParamS4.title = "PM2.5";
                            roomParamS4.value = "28";
                            roomParamS4.unit = "μg/m³";
                            roomParamList.push_back(roomParamS4);
                            roomParamStruct roomParamS5 = {};
                            roomParamS5.name = "air_quality";
                            roomParamS5.title = "空气质量";
                            roomParamS5.value = "优";
                            roomParamS5.unit = "";
                            roomParamList.push_back(roomParamS5);
                        roomS.params = roomParamList;


                        if(roomV.find("scenes") != roomV.end()){
                            QVariantMap scenesListV = roomV["scenes"].toMap();
                            QVariantList scenesListS;
                            if(scenesListV.find("default") != scenesListV.end()){
                                scenesListS = scenesListV["default"].toList();
                            }
                            if(scenesListV.find("custom") != scenesListV.end()){
                                QVariantList customScenes = scenesListV["custom"].toList();
                                for(int cs = 0;cs<customScenes.size();cs++){
                                    scenesListS.append(customScenes[cs]);
                                }
                            }


                            QVector<roomSceneStruct> roomSceneList;
                            for(int s=0;s<scenesListS.size();s++){
                                QVariantMap sceneV = scenesListS[s].toMap();
                                roomSceneStruct sceneS;

                                if(sceneV.find("id") != sceneV.end()){
                                    sceneS.id = sceneV["id"].toString();
                                }

                                if(sceneV.find("room_id") != sceneV.end()){
                                    sceneS.room_id = sceneV["room_id"].toInt();
                                }

                                if(sceneV.find("name") != sceneV.end()){
                                    sceneS.name = sceneV["name"].toString();
                                }

                                if(sceneV.find("icon") != sceneV.end()){
                                    sceneS.icon = sceneV["icon"].toString();
                                }

                                if(sceneV.find("type") != sceneV.end()){
                                    sceneS.type = sceneV["type"].toString();
                                }

                                if(sceneV.find("lights") != sceneV.end()){

                                    QVariantList sceneLightsV = sceneV["lights"].toList();
                                    QVector<roomSceneLightsStruct> sceneLightsS;

                                    for(int l=0;l<sceneLightsV.size();l++){
                                        QVariantMap roomSceneLightV = sceneLightsV[l].toMap();
                                        roomSceneLightsStruct roomSceneLightS;
                                        if(roomSceneLightV.find("id") != roomSceneLightV.end()){
                                            roomSceneLightS.id = roomSceneLightV["id"].toInt();
                                        }

                                        if(roomSceneLightV.find("brightness_value") != roomSceneLightV.end()){
                                            roomSceneLightS.brightness_value = roomSceneLightV["brightness_value"].toString();
                                        }

                                        if(roomSceneLightV.find("color_temperature_value") != roomSceneLightV.end()){
                                            roomSceneLightS.color_temperature_value = roomSceneLightV["color_temperature_value"].toString();
                                        }

                                        if(roomSceneLightV.find("hue_value") != roomSceneLightV.end()){
                                            roomSceneLightS.hue_value = roomSceneLightV["hue_value"].toString();
                                        }
                                        sceneLightsS.append(roomSceneLightS);
                                    }

                                    sceneS.lights = sceneLightsS;
                                }

                                if(sceneV.find("curtains") != sceneV.end()){

                                    QVariantList sceneCurtainsV = sceneV["curtains"].toList();
                                    QVector<roomSceneCurtainsStruct> sceneCurtainsS;

                                    for(int l=0;l<sceneCurtainsV.size();l++){
                                        QVariantMap roomSceneCurtainV = sceneCurtainsV[l].toMap();
                                        roomSceneCurtainsStruct roomSceneCurtainS;
                                        if(roomSceneCurtainV.find("id") != roomSceneCurtainV.end()){
                                            roomSceneCurtainS.id = roomSceneCurtainV["id"].toInt();
                                        }

                                        if(roomSceneCurtainV.find("angle_value") != roomSceneCurtainV.end()){
                                            roomSceneCurtainS.angle_value = roomSceneCurtainV["angle_value"].toString();
                                        }

                                        if(roomSceneCurtainV.find("oc_degree_value") != roomSceneCurtainV.end()){
                                            roomSceneCurtainS.oc_degree_value = roomSceneCurtainV["oc_degree_value"].toString();
                                        }

                                        sceneCurtainsS.append(roomSceneCurtainS);
                                    }

                                    sceneS.curtains = sceneCurtainsS;
                                }

                                roomSceneList.append(sceneS);
                            }

                            roomS.scenes = roomSceneList;
                        }


                        if(roomV.find("lights") != roomV.end()){

                            QVariantList lightingList = roomV["lights"].toList();
                            QVector<lightingStruct> lightingListS;

                            for(int l=0;l<lightingList.size();l++){

                                QVariantMap lightingV = lightingList[l].toMap();
                                lightingStruct lightingS;

                                if(lightingV.find("name") != lightingV.end()){
                                    lightingS.name = lightingV["name"].toString();
                                }

                                if(lightingV.find("id") != lightingV.end()){
                                    lightingS.id = lightingV["id"].toInt();
                                }

                                if(lightingV.find("project_id") != lightingV.end()){
                                    lightingS.project_id = lightingV["project_id"].toInt();
                                }

                                if(lightingV.find("build_id") != lightingV.end()){
                                    lightingS.build_id = lightingV["build_id"].toInt();
                                }

                                if(lightingV.find("space_id") != lightingV.end()){
                                    lightingS.space_id = lightingV["space_id"].toInt();
                                }

                                if(lightingV.find("room_id") != lightingV.end()){
                                    lightingS.room_id = lightingV["room_id"].toInt();
                                }

                                if(lightingV.find("icon") != lightingV.end()){
                                    lightingS.icon = lightingV["icon"].toString();
                                }

                                if(lightingV.find("function") != lightingV.end()){

                                    QVariantMap lightingFuncV = lightingV["function"].toMap();
                                    lightingFuncStruct lightingFuncS;

                                    if(lightingFuncV.find("switch") != lightingFuncV.end()){
                                        lightingFuncS.Switch = lightingFuncV["switch"].toInt();
                                    }

                                    if(lightingFuncV.find("dimming") != lightingFuncV.end()){
                                        lightingFuncS.dimming = lightingFuncV["dimming"].toInt();
                                    }


                                    if(lightingFuncV.find("hue") != lightingFuncV.end()){
                                        lightingFuncS.hue = lightingFuncV["hue"].toInt();
                                    }

                                    if(lightingFuncV.find("color_temperature") != lightingFuncV.end()){
                                        lightingFuncS.color_temperature = lightingFuncV["color_temperature"].toInt();
                                    }

                                    lightingS.function = lightingFuncS;
                                }


                                if(lightingV.find("switch") != lightingV.end()){
                                    lightingS.Switch = lightingV["switch"].toString();
                                }

                                if(lightingV.find("switch_feedback") != lightingV.end()){
                                    lightingS.switch_feedback = lightingV["switch_feedback"].toString();
                                    deviceDataStruct dds;
                                    dds.groupId = lightingS.switch_feedback;
                                    dds.houseId = lightingS.build_id;
                                    dds.spaceId = lightingS.space_id;
                                    dds.roomId = lightingS.room_id;
                                    dds.deviceType = DT_LIGHT;
                                    dds.functionType = FT_SWITCH;
                                    dds.value = "0";

                                    if (deviceMap.find(lightingS.switch_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[lightingS.switch_feedback];
                                    }
                                    deviceDataStructs_[lightingS.switch_feedback] = dds;

                                }

                                if(lightingV.find("dimming_relative") != lightingV.end()){
                                    lightingS.dimming_relative = lightingV["dimming_relative"].toString();
                                }

                                if(lightingV.find("dimming_absolute") != lightingV.end()){
                                    lightingS.dimming_absolute = lightingV["dimming_absolute"].toString();
                                }

                                if(lightingV.find("dimming_absolute_feedback") != lightingV.end()){
                                    lightingS.dimming_absolute_feedback = lightingV["dimming_absolute_feedback"].toString();

                                    deviceDataStruct dds;
                                    dds.groupId = lightingS.dimming_absolute_feedback;
                                    dds.houseId = lightingS.build_id;
                                    dds.spaceId = lightingS.space_id;
                                    dds.roomId = lightingS.room_id;
                                    dds.deviceType = DT_LIGHT;
                                    dds.functionType = FT_BRIGHTNESS;
                                    dds.value = "0";
                                    if (deviceMap.find(lightingS.dimming_absolute_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[lightingS.dimming_absolute_feedback];
                                    }
                                    deviceDataStructs_[lightingS.dimming_absolute_feedback] = dds;
                                }

                                if(lightingV.find("hue") != lightingV.end()){
                                    lightingS.hue = lightingV["hue"].toString();
                                }

                                if(lightingV.find("hue_feedback") != lightingV.end()){
                                    lightingS.hue_feedback = lightingV["hue_feedback"].toString();
                                    deviceDataStruct dds;
                                    dds.groupId = lightingS.hue_feedback;
                                    dds.houseId = lightingS.build_id;
                                    dds.spaceId = lightingS.space_id;
                                    dds.roomId = lightingS.room_id;
                                    dds.deviceType = DT_LIGHT;
                                    dds.functionType = FT_HUE;
                                    dds.value = "FFFFFF";
                                    if (deviceMap.find(lightingS.hue_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[lightingS.hue_feedback];
                                    }
                                    deviceDataStructs_[lightingS.hue_feedback] = dds;
                                }


                                if(lightingV.find("min_color_temperature") != lightingV.end()){
                                    lightingS.min_color_temperature = lightingV["min_color_temperature"].toString();
                                }

                                if(lightingV.find("max_color_temperature") != lightingV.end()){
                                    lightingS.max_color_temperature = lightingV["max_color_temperature"].toString();
                                }

                                if(lightingV.find("color_temperature") != lightingV.end()){
                                    lightingS.color_temperature = lightingV["color_temperature"].toString();
                                }

                                if(lightingV.find("color_temperature_feedback") != lightingV.end()){
                                    lightingS.color_temperature_feedback = lightingV["color_temperature_feedback"].toString();

                                    deviceDataStruct dds;
                                    dds.groupId = lightingS.color_temperature_feedback;
                                    dds.houseId = lightingS.build_id;
                                    dds.spaceId = lightingS.space_id;
                                    dds.roomId = lightingS.room_id;
                                    dds.deviceType = DT_LIGHT;
                                    dds.functionType = FT_HUE;
                                    dds.value = lightingS.min_color_temperature;
                                    if (deviceMap.find(lightingS.color_temperature_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[lightingS.color_temperature_feedback];
                                    }
                                    deviceDataStructs_[lightingS.color_temperature_feedback] = dds;
                                }

                                lightingListS.push_back(lightingS);

                            }

                            roomS.lights = lightingListS;



                        }

                        if(roomV.find("curtains") != roomV.end()){

                            QVariantList curtainListV = roomV["curtains"].toList();
                            QVector<curtainStruct> curtainListS;

                            for(int c=0;c<curtainListV.size();c++){

                                QVariantMap curtainV = curtainListV[c].toMap();
                                curtainStruct curtainS;

                                if(curtainV.find("name") != curtainV.end()){
                                    curtainS.name = curtainV["name"].toString();
                                }

                                if(curtainV.find("id") != curtainV.end()){
                                    curtainS.id = curtainV["id"].toInt();
                                }

                                if(curtainV.find("project_id") != curtainV.end()){
                                    curtainS.project_id = curtainV["project_id"].toInt();
                                }

                                if(curtainV.find("build_id") != curtainV.end()){
                                    curtainS.build_id = curtainV["build_id"].toInt();
                                }

                                if(curtainV.find("space_id") != curtainV.end()){
                                    curtainS.space_id = curtainV["space_id"].toInt();
                                }

                                if(curtainV.find("room_id") != curtainV.end()){
                                    curtainS.room_id = curtainV["room_id"].toInt();
                                }

                                if(curtainV.find("icon") != curtainV.end()){
                                    curtainS.icon = curtainV["icon"].toString();
                                }


                                if(curtainV.find("function") != curtainV.end()){

                                    QVariantMap functionV = curtainV["function"].toMap();
                                    curtainFuncStruct curtainFuncS;

                                    if(functionV.find("switch") != functionV.end()){
                                        curtainFuncS.Switch = functionV["switch"].toInt();
                                    }

                                    if(functionV.find("position") != functionV.end()){
                                        curtainFuncS.position = functionV["position"].toInt();
                                    }

                                    if(functionV.find("angle") != functionV.end()){
                                        curtainFuncS.angle = functionV["angle"].toInt();
                                    }

                                    curtainS.function = curtainFuncS;
                                }

                                if(curtainV.find("switch") != curtainV.end()){
                                    curtainS.Switch = curtainV["switch"].toString();
                                }

                                if(curtainV.find("switch_feedback") != curtainV.end()){
                                    curtainS.switch_feedback = curtainV["switch_feedback"].toString();

                                    deviceDataStruct dds;
                                    dds.groupId = curtainS.switch_feedback;
                                    dds.houseId = curtainS.build_id;
                                    dds.spaceId = curtainS.space_id;
                                    dds.roomId = curtainS.room_id;
                                    dds.deviceType = DT_CURTAIN;
                                    dds.functionType = FT_SWITCH;
                                    dds.value = "0";
                                    if (deviceMap.find(curtainS.switch_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[curtainS.switch_feedback];
                                    }
                                    deviceDataStructs_[curtainS.switch_feedback] = dds;
                                }

                                if(curtainV.find("position") != curtainV.end()){
                                    curtainS.position = curtainV["position"].toString();
                                }

                                if(curtainV.find("position_feedback") != curtainV.end()){
                                    curtainS.position_feedback = curtainV["position_feedback"].toString();

                                    deviceDataStruct dds;
                                    dds.groupId = curtainS.position_feedback;
                                    dds.houseId = curtainS.build_id;
                                    dds.spaceId = curtainS.space_id;
                                    dds.roomId = curtainS.room_id;
                                    dds.deviceType = DT_CURTAIN;
                                    dds.functionType = FT_OC_DEGREE;
                                    dds.value = "0";

                                    if (deviceMap.find(curtainS.position_feedback) != deviceMap.end()){
                                        dds.value = deviceMap[curtainS.position_feedback];
                                    }
                                    deviceDataStructs_[curtainS.position_feedback] = dds;
                                }

                                if(curtainV.find("stop") != curtainV.end()){
                                    curtainS.stop = curtainV["stop"].toString();
                                }

                                curtainListS.append(curtainS);
                            }
                            roomS.curtains = curtainListS;
                        }

                        roomListS.append(roomS);
                    }

                    spaceS.rooms = roomListS;
                }

                spacesListS.append(spaceS);

            }

            houseS.spaces = spacesListS;
        }
        houses_.append(houseS);
    }



    return true;
}

QString equipment::getDeviceValue(QString key){
    return deviceDataStructs_[key].value;
}

void equipment::setDeviceStruct(QString key,QString value){
    deviceDataStructs_[key].value = value;
}

deviceDataStruct equipment::getDeviceStruct(QString key){
    return deviceDataStructs_[key];
}
void equipment::setDeviceStruct(QString key,deviceDataStruct value){
    deviceDataStructs_.insert(key,value);

}

