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

void lightPage::setData(int buildId_,int spaceId,int roomId)
{
    QVariantMap room = equipment::getRoom(buildId_,spaceId,roomId);
    QVariantList lightings = room["lighting"].toList();
    int lightSize = lightings.size();
    int lightWidgetSize = lightWidgetList_.size();

    if(lightWidgetSize<lightSize){
        while(lightSize>lightWidgetSize){
            btnTwoSlider* bts = new btnTwoSlider(this);
            lightWidgetList_.append(bts);
            qDebug()<<"lightWidgetList_.append()";
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
        btnTwoSlider * light = lightWidgetList_[i];
        QVariantMap lighting = lightings[i].toMap();
        //名称
        light->setName(lighting["name"].toString());
        //icon
        QString icon = icon::getIcon(lighting["icon"].toString());
        light->setIcon(icon);

        QVariantMap func = lighting["function"].toMap();
        //亮度
        if(func["dimming"].toInt()==0){}
        //色温
        if(func["color_temperature"].toInt()==0){}
        //颜色
        if(func["hue"].toInt()==0){
            light->hideColor();
        } else {
            light->showColor();
        }
    }
}

void lightPage::goBackSlot()
{
    emit goBackSignal(PB_GO_HOME,0);
}

void lightPage::closeAllSlot()
{
    for (int i=0;i<lightWidgetList_.size();i++) {
        lightWidgetList_[i]->shutOff();
    }
}

void lightPage::ligthSwitch()
{
   ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}
