#include "mainwindow.h"
#include "equipment.h"

#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <qfile.h>
#include <qdebug.h>
#include <QSettings>
#include <LoadQss.h>
#include <lightpage.h>
#include <mainpage.h>
#include <curtainpage.h>


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
    ui->setupUi(this);

    pLightPage_ = new lightPage;
    pMainPage_ = new mainPage;
    pCurtainPage_ = new curtainPage;
    ui->stackedWidget->addWidget(pMainPage_);
    ui->stackedWidget->addWidget(pLightPage_);
    ui->stackedWidget->addWidget(pCurtainPage_);
    connect(pMainPage_, SIGNAL(goLightSignal(PageBack)), this,SLOT(switchPage(PageBack)));
    connect(pMainPage_, SIGNAL(goCurtainSignal(PageBack)), this,SLOT(switchPage(PageBack)));
    connect(pLightPage_, SIGNAL(goBackSignal(PageBack)), this,SLOT(switchPage(PageBack)));
    connect(pCurtainPage_, SIGNAL(goBackSignal(PageBack)), this,SLOT(switchPage(PageBack)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::switchPage(PageBack pb){
//    QPushButton *button = qobject_cast<QPushButton*>(sender());
    switch (pb) {
    case PB_GO_HOME:
        ui->stackedWidget->setCurrentWidget(pMainPage_);
        break;
    case PB_GO_LIGHT_PAGE:
        ui->stackedWidget->setCurrentWidget(pLightPage_);
        break;
    case PB_GO_CURTAIN_PAGE:
        ui->stackedWidget->setCurrentWidget(pCurtainPage_);
        break;
    default:
        return;
    }
}

void MainWindow::setData(){
    pEqm_ = new equipment();
    if(!pEqm_->init()){
        QMessageBox::critical(nullptr,"启动失败","配置文件初始化失败");
        return;
    }
}

//void MainWindow::changeStyle()
//{
//    QString path = ":/style.qss";
//    QFile file(path);

//    if ( file.open(QFile::ReadOnly) )
//    {
//        qDebug() << "open file success!";
//        QString qss = QLatin1String(file.readAll());
//        this->setStyleSheet(qss);
//        file.close();
//    }else{
//        qDebug() << "open file err!";
//    }
//}

//void MainWindow::changeStyleSlot()
//{
//    qDebug() << "changeStyleSlot";
//    LoadQss::loadQss(":/style1.qss");
//}
