#include "equipment.h"

#include <fstream>
#include <iostream>
#include "json/json.h"
#include "space.h"
#include "light.h"
#include "curtain.h"
#include <QMessageBox>
#include <errno.h>
equipment::equipment()
{
}

bool equipment::init()
{
    Json::Value root;
    Json::Reader reader;
    std::ifstream jsonFile("source/equipmentconf.json");//一定要运行目录
    if(!jsonFile.is_open()){
        QMessageBox::critical(nullptr,"启动失败","未找到配置文件");
        return false;
    }
    if(!reader.parse(jsonFile,root,true)){
        perror("read json err");
        QMessageBox::critical(nullptr,"启动失败","读取配置文件失败");
        return false;
    }
    int space_size = root.size();
    for(int i(0);i<space_size;i++){
        //设置空间数据
        QString name = QString::fromStdString(root[i]["name"].asString());
        QString id = QString::fromStdString(root[i]["id"].asString());
        spaces.append(new space(name,id));
        //解析灯数据
        Json::Value lights=root[i]["equipment"]["light"];
        for(unsigned int j(0);j<lights.size();j++){
            Light* l = new Light();
            QString lightName = QString::fromStdString(lights[j]["name"].asString());
            QString id = QString::fromStdString(lights[j]["id"].asString());
            int es = lights[j]["status"].asInt();
            int bn = lights[j]["brightness"].asInt();
            int ct = lights[j]["color_temp"].asInt();
            int c = lights[j]["color"].asInt();
            l->setId(id);
            l->setName(name);
            l->setSwitchStatus(es);
            l->setBrightness(bn);
            l->setColorTemp(ct);
            l->setColor(c);
            spaces[i]->addLight(l);
        }

        //解析窗帘数据
        Json::Value curtain=root[i]["equipment"]["curtain"];
        for(unsigned int j(0);j<curtain.size();j++){
            Curtain* ctn = new Curtain();
            QString ctnName = QString::fromStdString(curtain[j]["name"].asString());
            QString id = QString::fromStdString(curtain[j]["id"].asString());
            int es = curtain[j]["status"].asInt();
            int sa = curtain[j]["shading_area"].asInt();

            ctn->setId(id);
            ctn->setName(name);
            ctn->setSwitchStatus(es);
            ctn->setShadingArea(sa);
            spaces[i]->addCurtain(ctn);
        }

    }
    return true;

}
