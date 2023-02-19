#include "curtainopen.h"
#include "ui_curtainopen.h"
#include "curtainThread.h"
#include "icon.h"
#include <qdebug.h>
#include <unistd.h>
#include <QThread>


curtainOpen::curtainOpen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::curtainOpen),
    pThTest_(nullptr),
    pCurtainThread_(nullptr)
{
    ui->setupUi(this);
    ui->curtainFrame->setStyleSheet("background-color:#222222;");
    ui->open->setTxt("打开");
    ui->stop->setTxt("停止");
    ui->close->setTxt("关闭");
    ui->stop->setIcon(icon::getIcon("pause"));
    ui->openCloseSlider->setTitle("开合度");
    ui->openCloseSlider->setUnit("%");
    ui->angleSlider->setTitle("角度");
    ui->angleSlider->setUnit("°");
    connect(ui->open, SIGNAL(btnPressed()), this, SLOT(startOpen()));
    connect(ui->close, SIGNAL(btnPressed()), this, SLOT(startClose()));
    connect(ui->stop, SIGNAL(btnPressed()), this, SLOT(stopPressed()));
    connect(ui->openCloseSlider,SIGNAL(sliderReleased()),this,SLOT(openCloseSliderReleased()));
    connect(ui->angleSlider,SIGNAL(sliderReleased()),this,SLOT(angleSliderReleased()));

    movingOpen_ = false;
    movingClose_ = false;
}

curtainOpen::~curtainOpen()
{
    qDebug() <<id_<< "start destroy widget";

    if(pThTest_)
    {
        pCurtainThread_->stop();
    }
    qDebug() <<id_<< "end destroy widget";
    delete ui;
}

void curtainOpen::setData(curtainStruct curtain){
    curtain_ = curtain;
    setName(curtain_.name);
    setIcon(icon::getIcon(curtain_.icon));

    //开关
    if(curtain_.function.Switch==0){
    } else {
        if(curtain_.Switch == "0"){
            ui->open->setIconColor("#BCBCBC");
            ui->stop->setIconColor("#BCBCBC");
            ui->close->setIconColor("#D2AA74");
            ui->openCloseSlider->setNum("0");
        }else{
            ui->open->setIconColor("#D2AA74");
            ui->stop->setIconColor("#BCBCBC");
            ui->close->setIconColor("#BCBCBC");
            ui->openCloseSlider->setNum("100");
        }
    }
    //位置
    if(curtain_.function.position==0){
        ui->openCloseSlider->hide();
    }else {
        ui->openCloseSlider->show();
        ui->openCloseSlider->setNum(curtain_.position_value);
    }
    //角度
    if(curtain_.function.angle==0){
        hideAngle();
    } else {
        showAngle();
        ui->angleSlider->setNum(curtain_.position_value);
    }

    //窗帘方向
    setDirection(curtain_.direction);
}

void curtainOpen::setId(int id){
    id_ = id;
}
void curtainOpen::setName(QString name){
    ui->curtainTitle->setText(name);
}

void curtainOpen::setIcon(int icon){
    ui->curtainTitle->setIcon(icon);
}
void curtainOpen::setOpenIcon(int icon){
    ui->open->setIcon(icon);
}

void curtainOpen::setCloseIcon(int icon){
    ui->close->setIcon(icon);
}

void curtainOpen::hideAngle(){
    ui->angleSlider->setVisible(false);
}
void curtainOpen::showAngle(){
    ui->angleSlider->setVisible(true);
}

void curtainOpen::setDirection(QString direction){
    if(direction.compare("vertical")){
        ui->open->setIcon(icon::getIcon("上下展开"));
        ui->close->setIcon(icon::getIcon("ver_close"));
    } else {
        ui->open->setIcon(icon::getIcon("hor_open"));
        ui->close->setIcon(icon::getIcon("hor_close"));
    }
}
void curtainOpen::closeCurtain(){
    ui->open->setIconColor("#BCBCBC");
    ui->stop->setIconColor("#BCBCBC");
    ui->close->setIconColor("#D2AA74");
    ui->openCloseSlider->setNum("0");
}

void curtainOpen::startOpen(){
    ui->open->setIconColor("#D2AA74");
    ui->stop->setIconColor("#BCBCBC");
    ui->close->setIconColor("#BCBCBC");
    ui->openCloseSlider->setNum("100");

    //发送请求
    QVariantMap curtainMap;
    curtainMap["group_id"] = curtain_.Switch;
    curtainMap["switch"] = "1";
    QVariantList data;
    data.append(curtainMap);
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}
void curtainOpen::startClose(){
    ui->open->setIconColor("#BCBCBC");
    ui->stop->setIconColor("#BCBCBC");
    ui->close->setIconColor("#D2AA74");
    ui->openCloseSlider->setNum("0");
    //发送请求
    QVariantMap curtainMap;
    curtainMap["group_id"] = curtain_.Switch;
    curtainMap["switch"] = "0";
    QVariantList data;
    data.append(curtainMap);
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}

void curtainOpen::stopPressed(){
    ui->stop->setIconColor("#D2AA74");
    ui->open->setIconColor("#BCBCBC");
    ui->close->setIconColor("#BCBCBC");

    //发送请求
    QVariantMap curtainMap;
    curtainMap["group_id"] = curtain_.stop;
    curtainMap["stop"] = "1";
    QVariantList data;
    data.append(curtainMap);
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}

void curtainOpen::openCloseSliderReleased(){
    int value = ui->openCloseSlider->getNum();
    //发送请求
    QVariantMap curtainMap;
    curtainMap["group_id"] = curtain_.position;
    curtainMap["oc_degree"] = QString::number(value);
    QVariantList data;
    data.append(curtainMap);
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}

void curtainOpen::angleSliderReleased(){
    int value = ui->angleSlider->getNum();
    //发送请求
    QVariantMap curtainMap;
    curtainMap["group_id"] = curtain_.position;
    curtainMap["angle"] = QString::number(value);
    QVariantList data;
    data.append(curtainMap);
    QString jsonStr = Common::ListToString(data);
    equipment::curtainControl(jsonStr);
}

