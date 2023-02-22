#include "lightpage.h"
#include "equipment.h"
#include "ui_lightpage.h"
#include "btntwoslider.h"
#include "common.h"
#include "icon.h"
#include "fingerboard.h"

#include <qdebug.h>
#include <qlayout.h>
lightPage::lightPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightPage)
{
    ui->setupUi(this);
    //给返回按钮设置图标
    Common::setButtonIcon(ui->lightBack,icon::getIcon("return"));
    connect(ui->lightBack,&QPushButton::clicked,this,&lightPage::goBackSlot);
    connect(ui->closeAll,&QPushButton::clicked,this,&lightPage::closeAllSlot);
    pBoard_ = nullptr;
}

lightPage::~lightPage()
{
    delete ui;
}

void lightPage::setData(int houseId,int spaceId,int roomId)
{
    room_ = equipment::getRoom(houseId,spaceId,roomId);
    lightings_ = room_.lighting;
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
        qDebug()<<connect(light,SIGNAL(focusIn()),this,SLOT(focusIn()));
        connect(light,SIGNAL(focusIn()),this,SLOT(focusIn()));
        connect(light,SIGNAL(focusOut()),this,SLOT(focusOut()));
        lightingStruct lighting = lightings_[i];
        light->setData(lighting);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
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
         <<"roomId:"<<data.roomId;

    if (data.functionType == FT_SWITCH
            && room_.build_id == data.houseId
            && room_.space_id == data.spaceId
            && room_.id == data.roomId){
        for (int i=0;i<lightWidgetList_.size();i++) {
            btnTwoSlider* light = lightWidgetList_[i];
            QString brightness;
            QString colorTemperature;
            QString hue;
            if(light->getGroupId(data.functionType) == data.groupId){
                switch (data.functionType) {
                case FT_SWITCH:
                    light->setSwitch(data.value == "1",true);
                case FT_BRIGHTNESS:
                    light->setBrightness(data.value);
                    break;
                case FT_COLOR_TEMPERATURE:
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


void lightPage::focusIn(){
    qDebug()<<__FUNCTION__;
    if(pBoard_ == nullptr){
        pBoard_ = new fingerboard(ui->lightScrollArea);
        int boardHeight = pBoard_->size().height();
        int boardWidth = pBoard_->size().width();
        int boardX = ui->lightScrollArea->pos().x();
        int boardY = this->size().height()-boardHeight;
        qDebug()<<pBoard_->size();
        qDebug()<<this->size();
        qDebug()<<boardX<<","<<boardY<<","<<boardWidth<<","<<boardHeight;
        pBoard_->setGeometry(boardX,600,600,324);
        pBoard_->show();
    }
}

void lightPage::focusOut(){
    qDebug()<<__FUNCTION__;
}
