#include "roomcard.h"
#include "ui_roomcard.h"
#include "icon.h"
#include "common.h"
#include "verticaltxtunit.h"
#include "verticalicontextbk.h"
#include "equipment.h"
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

void roomCard::setData(roomStruct room){
    room_ = room;
    setName(room_.name);
    setIcon(icon::getIcon(room_.icon));
    setParams(room.params);
    setScenes(room.scene);
    int deviceNum = 0;
    int enabledNum = 0;

    for (int i=0;i<room_.lighting.size();i++){
        deviceNum = deviceNum+1;

        if(equipment::getDeviceValue(room_.lighting[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }
    }
    for (int i=0;i<room_.curtain.size();i++){
        deviceNum = deviceNum+1;
        if(equipment::getDeviceValue(room_.curtain[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }

    }
    ui->deviceNum->setText(QString::number(deviceNum));
    ui->enabledNum->setText(QString::number(enabledNum));

}

void roomCard::setEnableDeviceNum(QString num){
    ui->enabledNum->setText(num);
}

void roomCard::updateEnableDeviceNum(){
    qDebug()<<__FUNCTION__;
    int deviceNum = 0;
    int enabledNum = 0;

    for (int i=0;i<room_.lighting.size();i++){
        deviceNum = deviceNum+1;

        if(equipment::getDeviceValue(room_.lighting[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }
    }
    for (int i=0;i<room_.curtain.size();i++){
        deviceNum = deviceNum+1;
        if(equipment::getDeviceValue(room_.curtain[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }

    }
    ui->deviceNum->setText(QString::number(deviceNum));
    ui->enabledNum->setText(QString::number(enabledNum));
}

int roomCard::getRoomId(){
    return room_.id;
}

void roomCard::setParams(QVector<roomParamStruct> params){
    int paramsSize = params.size();
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
        roomParamStruct paramM = params.value(i);
        //名称
        vtu->setTitle(paramM.title);
        //单位
        QString unit = paramM.unit;
        if (unit.isEmpty()){
            vtu->setUnitVisiable(false);
        }else{
            vtu->setUnit(unit);
        }
        //值
        vtu->setNum(paramM.value);
    }
}

void roomCard::setScenes(QVector<roomSceneStruct> scenes){

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
        roomSceneStruct sceneM = scenes[i];
        //名称
        vit->setTxt(sceneM.name);
        //icon
        vit->setIcon(icon::getIcon(sceneM.icon));
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
    emit goPage(PB_GO_CTRLLIST_PAGR,room_.build_id,room_.space_id,room_.id);
}

void roomCard::editScene(){
//    emit goPage(PB_GO_CTRLLIST_PAGR,room_.build_id,room_.space_id,room_.id);
}

void roomCard::onClickClose(){
    //关闭所有灯
    QVariantList lightData;
    for (int i=0;i<room_.lighting.size();i++){
        QVariantMap lightMap;
        lightMap["group_id"] = room_.lighting[i].Switch;
        lightMap["switch"] = "0";

        lightData.append(lightMap);
    }
    QString jsonStr = Common::ListToString(lightData);
    equipment::lightControl(jsonStr);
    //关闭所有窗帘
    QVariantList curtainData;
    for (int i=0;i<room_.curtain.size();i++){
        QVariantMap curtainMap;
        curtainMap["group_id"] = room_.curtain[i].Switch;
        curtainMap["switch"] = "0";

        curtainData.append(curtainMap);
    }
    jsonStr = Common::ListToString(curtainData);
    equipment::curtainControl(jsonStr);
    //设置已经开启设备数量
    ui->enabledNum->setText("0");
}
