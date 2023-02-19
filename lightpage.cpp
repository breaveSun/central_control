#include "lightpage.h"
#include "equipment.h"
#include "ui_lightpage.h"
#include "btntwoslider.h"
#include "common.h"
#include "icon.h"

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
}

lightPage::~lightPage()
{
    delete ui;
}

void lightPage::setData(int houseId,int spaceId,int roomId)
{
    houseId_ = houseId;
    spaceId_ = spaceId;
    roomId_ = roomId;
    roomStruct room = equipment::getRoom(houseId,spaceId,roomId);
    lightings_ = room.lighting;
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
        lightingStruct lighting = lightings_[i];
        light->setData(lighting);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());

}

void lightPage::goBackSlot()
{
    emit goBackSignal(PB_GO_CTRLLIST_PAGR,houseId_,spaceId_,roomId_);
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
