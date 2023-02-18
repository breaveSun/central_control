#include "mainwindow.h"
#include "equipment.h"
#include <QApplication>
#include <QFile>
#include <LoadQss.h>
#include <QFontDatabase>
#include <QMessageBox>
#include <QVariant>


int main(int argc, char *argv[])
{
    //虚拟键盘调用
//    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QApplication a(argc, argv);

    //qss加载
    LoadQss::loadQss(":/style.qss");

    bool data = equipment::init();
    if(!data){
        QMessageBox::warning(NULL,"提示","配置文件加载失败",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    }

    MainWindow w;

    //展示页面
    w.show();

    return a.exec();

}
