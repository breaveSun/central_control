#include "mainwindow.h"
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


#ifndef DEBUG
//    Json::Value root;
//    Json::Reader reader;
//    std::ifstream jsonFile("source/light.json");//一定要运行目录
//    if(!reader.parse(jsonFile,root,true)){
//        std::cout<<"read err"<<std::endl;
//        return;
//    }
//    int space_size = root.size();
//    for(int i(0);i<space_size;i++){

//    }
//    Json::Value arrayValue = root;
//    Json::Value my_encoding = root["my-encoding"];
//    std::cout<<"read result:"<<my_encoding<<std::endl;

#else
    std::string str = "{\"content\": \"Hello JsonCpp\"}";

    Json::Reader reader;
    Json::Value root;
    if (reader.parse(str, root)){
    //           std::cout << root["content"].asString() << std::endl;
        std::cout << root.get("content", "UTF-32" ).asString() << std::endl;
        QMessageBox::information(NULL, "Title", QString::fromStdString(root.get("content", "UTF-32" ).asString()),QMessageBox::Yes);
    }
#endif
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button == ui->lightCntlr){
        ui->stackedWidget->setCurrentWidget(ui->lightPage);
    }
    if (button == ui->lightBack){
        ui->stackedWidget->setCurrentWidget(ui->mainPage);
    }
}
