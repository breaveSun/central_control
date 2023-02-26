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
    Common::setButtonIcon(ui->slipLeft,icon::getIcon("slip_left"));
    Common::setButtonIcon(ui->slipRight,icon::getIcon("slip_right"));

    connect(ui->slipLeft,&QPushButton::clicked,this,&roomCard::slipLeft);
    connect(ui->slipRight,&QPushButton::clicked,this,&roomCard::slipRight);
    connect(ui->checkDevice,SIGNAL(btnPressed()),this,SLOT(checkDevice()));
    connect(ui->oneClickClose,SIGNAL(btnPressed()),this,SLOT(onClickClose()));

    connect(ui->scrollArea->horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));

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
    setScenes(room.scenes,room.current_scene);
    int deviceNum = 0;
    int enabledNum = 0;

    for (int i=0;i<room_.lights.size();i++){
        deviceNum = deviceNum+1;

        if(equipment::getDeviceValue(room_.lights[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }
    }
    for (int i=0;i<room_.curtains.size();i++){
        deviceNum = deviceNum+1;
        if(equipment::getDeviceValue(room_.curtains[i].switch_feedback) == "1"){
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
    int deviceNum = 0;
    int enabledNum = 0;

    for (int i=0;i<room_.lights.size();i++){
        deviceNum = deviceNum+1;

        if(equipment::getDeviceValue(room_.lights[i].switch_feedback) == "1"){
            enabledNum = enabledNum + 1;
        }
    }
    for (int i=0;i<room_.curtains.size();i++){
        deviceNum = deviceNum+1;
        if(equipment::getDeviceValue(room_.curtains[i].switch_feedback) == "1"){
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

void roomCard::setScenes(QVector<roomSceneStruct> scenes,QString current_scene){

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

        roomSceneStruct sceneM = scenes[i];
        vit->setId(sceneM.id);
        //名称
        vit->setTxt(sceneM.name);
        //icon
        vit->setIcon(icon::getIcon(sceneM.icon));

        if(current_scene == sceneM.id){
            vit->setTwoColor("#FFFFFF","#D2AA74");
        }else{
            vit->setTwoColor("#BCBCBC","#353638");
        }
        connect(vit,SIGNAL(btnPressed(QString)),this,SLOT(changeScene(QString)));
    }
    ui->scrollAreaWidgetContents->setFixedWidth(ui->scrollAreaWidgetContents->sizeHint().width());
    if(scenesSize<5){
        ui->slipLeft->setStyleSheet("color:#353638");
        ui->slipRight->setStyleSheet("color:#353638");
    }else {
        ui->slipLeft->setStyleSheet("color:#BCBCBC");
        ui->slipRight->setStyleSheet("color:#353638");
    }
}

void roomCard::slipLeft(){
    int offsetx = ui->scrollArea->width()-30;
    QScrollBar *scrollBarx = ui->scrollArea->horizontalScrollBar();
    scrollBarx->setValue(scrollBarx->value()+offsetx);
}

void roomCard::slipRight(){
    int offsetx = ui->scrollArea->width()-30;

    QScrollBar *scrollBarx = ui->scrollArea->horizontalScrollBar();
    scrollBarx->setValue(scrollBarx->value()-offsetx);
}

void roomCard::checkDevice(){
    emit goPage(PB_GO_CTRLLIST_PAGR,room_.build_id,room_.space_id,room_.id);
}


void roomCard::onClickClose(){
    //关闭所有灯
    QVariantList lightData;
    for (int i=0;i<room_.lights.size();i++){
        QVariantMap lightMap;
        lightMap["group_id"] = room_.lights[i].Switch;
        lightMap["switch"] = "0";

        lightData.append(lightMap);
    }
    QString jsonStr = Common::ListToString(lightData);
    equipment::lightControl(jsonStr);
    //关闭所有窗帘
    QVariantList curtainData;
    for (int i=0;i<room_.curtains.size();i++){
        QVariantMap curtainMap;
        curtainMap["group_id"] = room_.curtains[i].Switch;
        curtainMap["switch"] = "0";

        curtainData.append(curtainMap);
    }
    jsonStr = Common::ListToString(curtainData);
    equipment::curtainControl(jsonStr);
    //设置已经开启设备数量
    ui->enabledNum->setText("0");
}


void roomCard::changeScene(QString id){
    //发送切换模式指令
    if(id!=room_.current_scene){
        equipment::changeScene(room_.id,id);
    }
}

void roomCard::sliderChanged(int value){
    int end = ui->scrollAreaWidgetContents->size().width()-ui->scrollArea->width();
    if(value == 0){
        ui->slipLeft->setStyleSheet("color:#BCBCBC");
        ui->slipRight->setStyleSheet("color:#353638");
    } else if (value == end){
        ui->slipLeft->setStyleSheet("color:#353638");
        ui->slipRight->setStyleSheet("color:#BCBCBC");
    } else {
        ui->slipLeft->setStyleSheet("color:#BCBCBC");
        ui->slipRight->setStyleSheet("color:#BCBCBC");
    }
}
