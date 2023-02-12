#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <LoadQss.h>
#include <QFontDatabase>
//#include <QMessageBox>
//#include "logindlg.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qss加载
    LoadQss::loadQss(":/style.qss");

    MainWindow w;

    //读取配置文件，初始化设备列表
    w.setData();
    //展示页面
    w.show();

    return a.exec();

}
