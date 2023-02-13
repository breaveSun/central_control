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

void curtainPage::setData(int buildId_,int spaceId,int roomId)
{
    QVariantMap room = equipment::getRoom(buildId_,spaceId,roomId);
    QVariantList curtains = room["curtain"].toList();
    qDebug()<<"curtains.size()"<<curtains.size();
    int curtainSize = curtains.size();
    int curtainWidgetSize = curtainWidgetList_.size();

    if(curtainWidgetSize<curtainSize){
        while(curtainSize>curtainWidgetSize){
            curtainOpen* bts = new curtainOpen(this);
            curtainWidgetList_.append(bts);
            qDebug()<<"curtainWidgetList_.append()";
            ui->scrollAreaWidgetContents->layout()->addWidget(bts);
//            connect(bts, SIGNAL(lightSwitch()), this,SLOT(ligthSwitch()));
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
        QVariantMap curtainM = curtains[i].toMap();
        //名称
        curtain->setName(curtainM["name"].toString());
        //icon
        QString icon = icon::getIcon(curtainM["icon"].toString());
        curtain->setIcon(icon);

        QVariantMap func = curtainM["function"].toMap();
        //开关
        if(func["switch"].toInt()==0){}
        //位置
        if(func["position"].toInt()==0){}
        //角度
        if(func["angle"].toInt()==0){
            curtain->hideAngle();
        } else {
            curtain->showAngle();
        }

        //窗帘方向
        QString direction = curtainM["direction"].toString();
        curtain->setDirection(direction);
    }
    ui->scrollAreaWidgetContents->setFixedHeight(ui->scrollAreaWidgetContents->sizeHint().height());
}

curtainPage::~curtainPage()
{
    delete ui;
}

void curtainPage::goBackSlot()
{
    emit goBackSignal(PB_GO_HOME,0);
}

void curtainPage::closeAllSlot()
{
    for (int i=0;i<curtainWidgetList_.size();i++) {
        curtainWidgetList_[i]->closeCurtain();
    }
}
