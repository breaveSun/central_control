#include "lightpage.h"
#include "equipment.h"
#include "ui_lightpage.h"
#include "btntwoslider.h"
#include "common.h"
#include "icon.h"
#include "fingerboard.h"
#include "mylineedit.h"

#include <qdebug.h>
#include <qlayout.h>
lightPage::lightPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightPage)
{
    ui->setupUi(this);
    ui->title->setTitle("照明控制");
    ui->title->addBackBtn();
    ui->title->addListBtn("一键关灯");
    connect(ui->title,SIGNAL(backClick()),this,SLOT(goBackSlot()));
    connect(ui->title,SIGNAL(listClick()),this,SLOT(closeAllSlot()));

    pBoard_ = new fingerboard;
    pBoard_->initFocusWidget(this);
    pBoard_->setGeometry(0,600,600,324);
//    pBoard_->show();
}

lightPage::~lightPage()
{
    delete ui;
}

void lightPage::setData(int houseId,int spaceId,int roomId)
{
    room_ = equipment::getRoom(houseId,spaceId,roomId);
    lightings_ = room_.lights;
    int lightSize = lightings_.size();
    int lightWidgetSize = lightWidgetList_.size();

    if(lightWidgetSize<lightSize){
        while(lightSize>lightWidgetSize){
            btnTwoSlider* bts = new btnTwoSlider(this);
            lightWidgetList_.append(bts);
            ui->scrollAreaWidgetContents->layout()->addWidget(bts);
            connect(bts, SIGNAL(lightSwitch()), this,SLOT(ligthSwitch()));
            lightWidgetSize++;
        }
    }

    if(lightSize<lightWidgetSize){
        int removeNum = lightWidgetSize-lightSize;
        while(lightWidgetSize>lightSize){
            ui->scrollAreaWidgetContents->layout()->removeWidget(lightWidgetList_[lightWidgetSize-1]);
            lightWidgetSize--;
        }
        lightWidgetList_.remove(lightSize-1,removeNum);
    }

    for (int i=0;i<lightSize;i++) {
        btnTwoSlider* light = lightWidgetList_[i];
        //qDebug()<<connect(light,SIGNAL(colorTxtMouseReleased()),this,SLOT(colorTxtMouseReleased()));
        connect(light,SIGNAL(colorTxtMouseReleased()),this,SLOT(colorTxtMouseReleased()));
        connect(light,SIGNAL(focusOut()),this,SLOT(focusOut()));
        lightingStruct lighting = lightings_[i];
        light->setData(lighting);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());

    qDebug()<<"room_.build_id:"<<room_.build_id
    <<"room_.space_id:"<<room_.space_id
    <<"room_.id:"<<room_.id;
}

void lightPage::goBackSlot()
{
    emit goBackSignal(PB_GO_CTRLLIST_PAGR,room_.build_id,room_.space_id,room_.id);
}

void lightPage::closeAllSlot()
{
    for (int i=0;i<lightWidgetList_.size();i++) {
        lightWidgetList_[i]->shutOff(true);
    }
    //发送请求
    QVariantList data;
    for (int i=0;i<lightings_.size();i++){
        QVariantMap lightMap;
        lightMap["group_id"] = lightings_[i].Switch;
        lightMap["switch"] = "0";

        data.append(lightMap);
    }
    QString jsonStr = Common::ListToString(data);
    equipment::lightControl(jsonStr);
}

void lightPage::ligthSwitch()
{
   ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}


void lightPage::acceptPush(deviceDataStruct data){
    qDebug()<<__FUNCTION__;

    qDebug()<<"key:"<<data.groupId
           <<"value:"<<data.value
            <<"deviceType:"<<data.deviceType
            <<"functionType:"<<data.functionType
           <<"build_id:"<<data.houseId
          <<"spaceId:"<<data.spaceId
         <<"roomId:"<<data.roomId
    <<"room_.build_id:"<<room_.build_id
    <<"room_.space_id:"<<room_.space_id
    <<"room_.id:"<<room_.id;
    if (data.deviceType == DT_LIGHT
            && room_.build_id == data.houseId
            && room_.space_id == data.spaceId
            && room_.id == data.roomId){
        for (int i=0;i<lightWidgetList_.size();i++) {
            btnTwoSlider* light = lightWidgetList_[i];
            if(light->getGroupId(data.functionType) == data.groupId){
                switch (data.functionType) {
                case FT_SWITCH:
                    light->setSwitch(data.value == "1",true);
                    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());

                case FT_BRIGHTNESS:
                    //约定亮度=0不改变样式
                    if(data.value == 0) return;
                    qDebug()<<"FT_BRIGHTNESS"<<data.value;
                    light->setBrightness(data.value);
                    break;
                case FT_COLOR_TEMPERATURE:
                    qDebug()<<"FT_COLOR_TEMPERATURE"<<data.value;
                    light->setColorTemperature(data.value);
                    break;
                case FT_HUE:
                    light->setColor(data.value);
                    break;
                default:
                    break;
                }
                break;
            }
        }
    }
}


void lightPage::colorTxtMouseReleased(){
    pBoard_->setGeometry(0,750,600,324);
//    btnTwoSlider* light = qobject_cast<btnTwoSlider *>(sender());
//    light->setFocusIn();
}

void lightPage::focusOut(){
    qDebug()<<__FUNCTION__;
//    pBoard_->hide();
}
