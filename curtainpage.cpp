#include "curtainpage.h"
#include "ui_curtainpage.h"
#include "curtainopen.h"
#include "equipment.h"
#include "icon.h"

curtainPage::curtainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::curtainPage)
{
    ui->setupUi(this);
    //给返回按钮设置图标
    Common::setButtonIcon(ui->curtainBack,icon::getIcon("return"));
    connect(ui->curtainBack,&QPushButton::clicked,this,&curtainPage::goBackSlot);
    connect(ui->closeAll,&QPushButton::clicked,this,&curtainPage::closeAllSlot);


}


curtainPage::~curtainPage()
{
    delete ui;
}

void curtainPage::setData(int houseId,int spaceId,int roomId)
{
    room_ = equipment::getRoom(houseId,spaceId,roomId);
    curtains_ = room_.curtains;
    int curtainSize = curtains_.size();
    int curtainWidgetSize = curtainWidgetList_.size();

    if(curtainWidgetSize<curtainSize){
        while(curtainSize>curtainWidgetSize){
            curtainOpen* bts = new curtainOpen(this);
            curtainWidgetList_.append(bts);
            ui->scrollAreaWidgetContents->layout()->addWidget(bts);
            curtainWidgetSize++;
        }
    }

    if(curtainSize<curtainWidgetSize){
        int removeNum = curtainWidgetSize-curtainSize;
        while(curtainWidgetSize>curtainSize){
            ui->scrollAreaWidgetContents->layout()->removeWidget(curtainWidgetList_[curtainWidgetSize-1]);
            curtainWidgetSize--;
        }
        curtainWidgetList_.remove(curtainSize-1,removeNum);
    }

    for (int i=0;i<curtainSize;i++) {
        curtainOpen * curtain = curtainWidgetList_[i];
        curtainStruct curtainS = curtains_[i];
        curtain->setData(curtainS);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}

void curtainPage::goBackSlot()
{
    emit goBackSignal(PB_GO_CTRLLIST_PAGR,room_.build_id,room_.space_id,room_.id);
}

void curtainPage::closeAllSlot()
{
    for (int i=0;i<curtainWidgetList_.size();i++) {
        curtainWidgetList_[i]->closeCurtain();
    }

    //发送请求
    QVariantList data;
    for (int i=0;i<curtains_.size();i++){
        QVariantMap curtainMap;
        curtainMap["group_id"] = curtains_[i].Switch;
        curtainMap["switch"] = "0";

        data.append(curtainMap);
    }
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}


void curtainPage::acceptPush(deviceDataStruct data){
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
        for (int i=0;i<curtainWidgetList_.size();i++) {
            curtainOpen* curtain = curtainWidgetList_[i];
            QString brightness;
            QString colorTemperature;
            QString hue;
            if(curtain->getGroupId(data.functionType) == data.groupId){
                switch (data.functionType) {
                case FT_SWITCH:
                    curtain->setSwitch(data.value == "1");
                case FT_OC_DEGREE:
                    curtain->setOpenClose(data.value);
                case FT_ANGLE:
                    curtain->setAngle(data.value);
                    break;
                default:
                    break;
                }
                break;
            }
        }
    }
}
