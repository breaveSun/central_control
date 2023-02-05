#include "mainwindow.h"
#include "equipment.h"

#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <fstream>
#include <iostream>

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
    titleBtnShow1 = new btnTwoSlider;
    titleBtnShow2 = new btnTwoSlider;
    titleBtnShow1->setName("主吊灯");
    titleBtnShow2->setName("玄关灯");
    connect(ui->lightCntlr,&QPushButton::clicked,this,&MainWindow::switchPage);
    connect(ui->lightBack,&QPushButton::clicked,this,&MainWindow::switchPage);

    ui->lightLayout->addWidget(titleBtnShow1);
    ui->lightLayout->addWidget(titleBtnShow2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::switchPage(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button == ui->lightCntlr){
        ui->stackedWidget->setCurrentWidget(ui->lightPage);
    }
    if (button == ui->lightBack){
        ui->stackedWidget->setCurrentWidget(ui->mainPage);
    }
}

void MainWindow::setData(){
    pEqm_ = new equipment();
    if(!pEqm_->init()){
        QMessageBox::critical(nullptr,"启动失败","配置文件初始化失败");
        return;
    }
}
