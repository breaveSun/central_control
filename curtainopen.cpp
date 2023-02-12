#include "curtainopen.h"
#include "ui_curtainopen.h"
#include "curtainThread.h"
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
    ui->stop->setTxt("暂停");
    ui->close->setTxt("关闭");
    ui->stop->setIcon(QChar(0xe603));
    ui->openCloseSlider->setTitle("开合度");
    ui->openCloseSlider->setUnit("%");
    ui->angleSlider->setTitle("角度");
    ui->angleSlider->setUnit("°");
//    ui->open->setIconColor("#D2AA74");
    connect(ui->open, SIGNAL(btnPressed()), this, SLOT(startOpen()));
    connect(ui->close, SIGNAL(btnPressed()), this, SLOT(startClose()));
    connect(ui->stop, SIGNAL(btnPressed()), this, SLOT(stopPressed()));
    connect(ui->stop, SIGNAL(btnClicked()), this, SLOT(stopClicked()));

    movingOpen_ = false;
    movingClose_ = false;
}

curtainOpen::~curtainOpen()
{
    qDebug() <<id_<< "start destroy widget";

    if(pThTest_)
    {
//        pThTest_->quit();
        pCurtainThread_->stop();
    }
//    pThTest_->wait();
    qDebug() <<id_<< "end destroy widget";
    delete ui;
}
void curtainOpen::setId(int id){
    id_ = id;
}
void curtainOpen::setName(QString name){
    ui->curtainTitle->setText(name);
}

void curtainOpen::setOpenIcon(QChar icon){
    ui->open->setIcon(icon);
}

void curtainOpen::setCloseIcon(QChar icon){
    ui->close->setIcon(icon);
}

void curtainOpen::hideAngle(){
    ui->angleSlider->setVisible(false);
    ui->curtainFrame->setFixedHeight(ui->curtainFrame->sizeHint().height());
    setFixedHeight(sizeHint().height());
}

void curtainOpen::closeCurtain(){
    qDebug()<<id_<<__FUNCTION__<<movingOpen_<<movingClose_;
    if(movingClose_){
        return;
    }

    //关闭按钮开启样式 - 关闭动作开始
    ui->close->setIconColor("#D2AA74");
    movingClose_ = true;

    if (movingOpen_){
        //打开按钮恢复默认样式 打开动作停止
        ui->open->setIconColor("#FFFFFF");
        movingOpen_ = false;
        return;
    }
    //开启进程
    startThread();
    //开启事件
    emit toThread();
}

void curtainOpen::startThread(){
    qDebug()<<id_<<__FUNCTION__;
    if(pThTest_){
        qDebug()<<id_<<"pThTest_"<<(pThTest_== nullptr);
        qDebug()<<id_<<"pCurtainThread_"<<(pCurtainThread_== nullptr);
        return;
    }
    pThTest_ = new QThread;
    pCurtainThread_ = new curtainThread;
    pCurtainThread_->moveToThread(pThTest_);
    qDebug()<<id_<<"moveToThread;";
    connect(pThTest_, &QThread::finished, this, &curtainOpen::threadFinish);
    connect(pThTest_,&QThread::finished,pThTest_,&QObject::deleteLater);
    connect(pThTest_, &QThread::finished, pCurtainThread_, &QObject::deleteLater);
    connect(this,&curtainOpen::toThread,pCurtainThread_,&curtainThread::Func);
    connect(pCurtainThread_,SIGNAL(once()),this,SLOT(threadUpdateSlider()));
    pThTest_->start();
    qDebug()<<id_<<"pThTest_->start();";
}

void curtainOpen::startOpen(){
    qDebug()<<id_<<__FUNCTION__<<movingOpen_<<movingClose_;

    if(movingOpen_){
        return;
    }

    //打开按钮开启样式 - 打开动作开始
    ui->open->setIconColor("#D2AA74");
    movingOpen_ = true;
    if (movingClose_){
        //关闭按钮恢复默认样式 关闭动作停止
        ui->close->setIconColor("#FFFFFF");
        movingClose_ = false;
        return;
    }
    //开启进程
    startThread();
    //开启事件
    emit toThread();
}
void curtainOpen::startClose(){
    closeCurtain();
    /*qDebug()<<id_<<__FUNCTION__<<movingOpen_<<movingClose_;
    if(movingClose_){
        return;
    }

    //关闭按钮开启样式 - 关闭动作开始
    ui->close->setIconColor("#D2AA74");
    movingClose_ = true;

    if (movingOpen_){
        //打开按钮恢复默认样式 打开动作停止
        ui->open->setIconColor("#FFFFFF");
        movingOpen_ = false;
        return;
    }
    //开启进程
    startThread();
    //开启事件
    emit toThread();*/
}

void curtainOpen::stopPressed(){
    ui->stop->setIconColor("#D2AA74");
    pCurtainThread_->stop();
    movingOpen_ = false;
    movingClose_ = false;
    ui->open->setIconColor("#FFFFFF");
    ui->close->setIconColor("#FFFFFF");
}

void curtainOpen::stopClicked(){
    ui->stop->setIconColor("#FFFFFF");
}

void curtainOpen::threadUpdateSlider(){
    qDebug()<<id_<<"threadUpdateSlider"<<movingOpen_<<movingClose_;
    //确定当前是开启还是关闭
    if(movingOpen_){
        int num = ui->openCloseSlider->getNum();
        int max = ui->openCloseSlider->max();
        qDebug()<<id_<<"movingOpen_"<<num<<max;
        if (num<max){
            num++;
            ui->openCloseSlider->setNum(QString::number(num));
        } else {
            //开启结束
            pCurtainThread_->stop();
            movingOpen_ = false;
            ui->open->setIconColor("#FFFFFF");
        }
    }

    if(movingClose_){
        int num = ui->openCloseSlider->getNum();
        int min = ui->openCloseSlider->min();
        qDebug()<<id_<<"movingClose_"<<num<<min;
        if (num>min){
            num--;
            ui->openCloseSlider->setNum(QString::number(num));
        } else {
            qDebug()<<id_<<"movingClose_   stop";
            //关闭结束
            pCurtainThread_->stop();
            movingClose_ = false;
            ui->close->setIconColor("#FFFFFF");
        }
    }
}

void curtainOpen::threadFinish(){
    qDebug()<<id_<<__FUNCTION__;
}

