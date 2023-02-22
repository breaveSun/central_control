#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "equipment.h"
#include "curtainpage.h"
#include "mainpage.h"
#include "lightpage.h"
#include "equipment.h"
#include "common.h"
#include "ctrllistpage.h"
#include "homepage.h"
#include "serverpushthread.h"
#include "wsclient.h"
#include "messagecenter.h"

#include <QPushButton>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <qfile.h>
#include <qdebug.h>
#include <QSettings>
#include <QThread>

class LightParam {
public:
    QString lightName;
    QString lightIcon;
    bool status;
    QString brightness;
    QString colorTem;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //隐藏默认页面头部样式
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    //隐藏鼠标光标
//    QApplication::setOverrideCursor(Qt::BlankCursor);


//    pMainPage_ = new mainPage;
    pHomePage_ = new homePage;
    pCtrlListPage_ = new ctrlListPage;
    pLightPage_ = new lightPage;
    pCurtainPage_ = new curtainPage;
    pMessageCenter_ = new messageCenter;
    startWS(Common::getHostMacAddress());

//    ui->stackedWidget->addWidget(pMainPage_);
    ui->stackedWidget->addWidget(pHomePage_);
    ui->stackedWidget->addWidget(pCtrlListPage_);
    ui->stackedWidget->addWidget(pLightPage_);
    ui->stackedWidget->addWidget(pCurtainPage_);
    ui->stackedWidget->addWidget(pMessageCenter_);

    //主页去其他页面连接
    connect(pHomePage_, SIGNAL(goPage(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));

    //进入设备控制列表 > 详情页
    connect(pCtrlListPage_, SIGNAL(goDetailSignal(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));

    //从设备控制列表返回 > 主页
    connect(pCtrlListPage_, SIGNAL(goBackSignal(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));

    //从设备控制详情页返回 > 设备控制列表
    connect(pLightPage_, SIGNAL(goBackSignal(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));
    connect(pCurtainPage_, SIGNAL(goBackSignal(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));

    //消息列表返回主页
    connect(pMessageCenter_, SIGNAL(goBackSignal(PageBack,int,int,int)), this,SLOT(switchPage(PageBack,int,int,int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchPage(enum PageBack pb,int houseId,int spaceId,int roomId){
//    QPushButton *button = qobject_cast<QPushButton*>(sender());
    switch (pb) {
    case PB_GO_MAIN:
//        ui->stackedWidget->setCurrentWidget(pMainPage_);
        break;
    case PB_GO_HOME:
        pHomePage_->setData(houseId,spaceId);
        ui->stackedWidget->setCurrentWidget(pHomePage_);
        break;
    case PB_GO_LIGHT_PAGE:
        qDebug()<<"PB_GO_LIGHT_PAGE:"<<roomId;
        pLightPage_->setData(houseId,spaceId,roomId);
        ui->stackedWidget->setCurrentWidget(pLightPage_);
        break;
    case PB_GO_CURTAIN_PAGE:
        qDebug()<<"PB_GO_CURTAIN_PAGE:"<<roomId;
        pCurtainPage_->setData(houseId,spaceId,roomId);
        ui->stackedWidget->setCurrentWidget(pCurtainPage_);
        break;
    case PB_GO_CTRLLIST_PAGR:
        qDebug()<<"PB_GO_CTRLLIST_PAGR:"<<roomId;
        pCtrlListPage_->setData(houseId,spaceId,roomId);
        ui->stackedWidget->setCurrentWidget(pCtrlListPage_);
        break;
    case PB_GO_MESSAGE_CENTER:
        qDebug()<<"PB_GO_MESSAGE_CENTER:"<<roomId;
        ui->stackedWidget->setCurrentWidget(pMessageCenter_);
        break;

    default:
        return;
    }
}

void MainWindow::startWS(QString mac){
    //创建长链接
    pWSClient_ = new wsClient(this);

    QString ADRESS_STR="//192.168.2.6:8888";
    pWSClient_->ConnectTo("ws:"+ADRESS_STR+"/socket.io/"+mac);
    connect(pWSClient_,SIGNAL(notices(deviceDataStruct)),pHomePage_,SLOT(acceptPush(deviceDataStruct)));
    connect(pWSClient_,SIGNAL(notices(deviceDataStruct)),pLightPage_,SLOT(acceptPush(deviceDataStruct)));
    connect(pWSClient_,SIGNAL(notices(deviceDataStruct)),pCurtainPage_,SLOT(acceptPush(deviceDataStruct)));
    connect(pWSClient_,SIGNAL(notices(messageStruct)),pMessageCenter_,SLOT(acceptPush(messageStruct)));
}
