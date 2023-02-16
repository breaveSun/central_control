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
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));//虚拟键盘调用
    QApplication a(argc, argv);

    //qss加载
    LoadQss::loadQss(":/style.qss");

    MainWindow w;

    //展示页面
    w.show();

    return a.exec();

}
