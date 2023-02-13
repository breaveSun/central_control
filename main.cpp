#include "mainwindow.h"
#include "equipment.h"
#include <QApplication>
#include <QFile>
#include <LoadQss.h>
#include <QFontDatabase>
#include <QMessageBox>
//#include "logindlg.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qss加载
    LoadQss::loadQss(":/style.qss");

//    //数据
//    equipment *pEqm_ = new equipment();
//    if(!pEqm_->init()){
//        QMessageBox::critical(nullptr,"启动失败","配置文件初始化失败");
////        return;
//    }


    MainWindow w;

    //读取配置文件，初始化设备列表
//    w.setData();
    //展示页面
    w.show();

    return a.exec();

}
