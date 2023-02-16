#include "roomcard.h"
#include "ui_roomcard.h"
#include "icon.h"
#include "common.h"
#include "verticaltxtunit.h"
#include "verticalicontextbk.h"
#include <QScrollBar>

roomCard::roomCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::roomCard)
{
    ui->setupUi(this);
    ui->oneClickClose->setIcon("power");
    ui->oneClickClose->setTxt("一键关闭");
    ui->deviceNum->setText("0");
    ui->enabledNum->setText("0");
    ui->checkDevice->setTxt("查看设备");
    ui->checkDevice->setIcon("rightwards");
    ui->editScene->setTxt("编辑场景");
    ui->editScene->setIcon("rightwards");
    Common::setButtonIcon(ui->slipLeft,icon::getIcon("slip_left"));
    Common::setButtonIcon(ui->slipRight,icon::getIcon("slip_right"));

    connect(ui->slipLeft,&QPushButton::clicked,this,&roomCard::slipLeft);
    connect(ui->slipRight,&QPushButton::clicked,this,&roomCard::slipRight);
    connect(ui->checkDevice,SIGNAL(btnPressed()),this,SLOT(checkDevice()));
    connect(ui->editScene,SIGNAL(btnPressed()),this,SLOT(editScene()));
    connect(ui->oneClickClose,SIGNAL(btnPressed()),this,SLOT(onClickClose()));

}

roomCard::~roomCard()
{
    delete ui;
}


void roomCard::setName(QString name){
    ui->roomTitle->setText(name);
}

void roomCard::setIcon(int icon){
    ui->roomTitle->setIcon(icon);
}

void roomCard::setData(int houseId,int spaceId,int roomId){
    houseId_ = houseId;
    spaceId_ = spaceId;
    roomId_ = roomId;
}

void roomCard::setParams(QVariantList params){
    int paramsSize = params.size();
    qDebug()<<"poaram:"<<paramsSize;
    int paramsWidgetSize = paramsWidgetList_.size();

    if(paramsWidgetSize<paramsSize){
        while(paramsSize>paramsWidgetSize){
            verticalTxtUnit* vtu = new verticalTxtUnit(ui->statusParam);
            paramsWidgetList_.append(vtu);
            ui->statusParam->layout()->addWidget(vtu);
            paramsWidgetSize++;
        }
    }

    if(paramsSize<paramsWidgetSize){
        int removeNum = paramsWidgetSize-paramsSize;
        while(paramsWidgetSize>paramsSize){
            ui->scrollAreaWidgetContents->layout()->removeWidget(paramsWidgetList_[paramsWidgetSize-1]);
            paramsWidgetSize--;
        }
        paramsWidgetList_.remove(paramsSize-1,removeNum);
    }

    for (int i=0;i<paramsSize;i++) {
        verticalTxtUnit * vtu = paramsWidgetList_[i];
        QVariantMap paramM = params[i].toMap();
        //名称
        vtu->setTitle(paramM["title"].toString());
        //单位
        QString unit = paramM["unit"].toString();
        if (unit.isEmpty()){
            vtu->setUnitVisiable(false);
        }else{
            vtu->setUnit(unit);
        }
        //值
        vtu->setNum(paramM["value"].toString());

        qDebug()<<"poaram:"<<i<<":"<<paramM["title"].toString()<<paramM["unit"].toString();
    }
}

void roomCard::setScenes(QVariantList scenes){

    int scenesSize = scenes.size();
    int scenesWidgetSize = scenesWidgetList_.size();

    if(scenesWidgetSize<scenesSize){
        while(scenesSize>scenesWidgetSize){
            verticalicontextBK* vitbk = new verticalicontextBK(ui->scrollAreaWidgetContents);
            scenesWidgetList_.append(vitbk);
            ui->scrollAreaWidgetContents->layout()->addWidget(vitbk);
            scenesWidgetSize++;
        }
    }

    if(scenesSize<scenesWidgetSize){
        int removeNum = scenesWidgetSize-scenesSize;
        while(scenesWidgetSize>scenesSize){
            ui->scrollAreaWidgetContents->layout()->removeWidget(scenesWidgetList_[scenesWidgetSize-1]);
            scenesWidgetSize--;
        }
        scenesWidgetList_.remove(scenesSize-1,removeNum);
    }

    for (int i=0;i<scenesSize;i++) {
        verticalicontextBK * vit = scenesWidgetList_[i];
        vit->setColor("#BCBCBC");
        vit->setBKColor("#353638");
        QVariantMap sceneM = scenes[i].toMap();
        //名称
        vit->setTxt(sceneM["name"].toString());
        //icon
        vit->setIcon(icon::getIcon(sceneM["icon"].toString()));
    }
    ui->scrollAreaWidgetContents->setFixedWidth(ui->scrollAreaWidgetContents->sizeHint().width());

}

void roomCard::slipLeft(){
    qDebug()<<ui->scrollArea->sizeHint().width()<<":"<<ui->scrollArea->width();
    int offsetx = ui->scrollArea->width()-30;

    QScrollBar *scrollBarx = ui->scrollArea->horizontalScrollBar();
    scrollBarx->setValue(scrollBarx->value()-offsetx);
}

void roomCard::slipRight(){
    qDebug()<<ui->scrollArea->sizeHint().width()<<":"<<ui->scrollArea->width();
    int offsetx = ui->scrollArea->width()-50;

    QScrollBar *scrollBarx = ui->scrollArea->horizontalScrollBar();
    scrollBarx->setValue(scrollBarx->value()+offsetx);
}

void roomCard::checkDevice(){
    emit goPage(PB_GO_CTRLLIST_PAGR,houseId_,spaceId_,roomId_);
}

void roomCard::editScene(){
//    emit goPage(PB_GO_CTRLLIST_PAGR,houseId_,spaceId_,roomId_);
}

void roomCard::onClickClose(){

}
