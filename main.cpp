#include "mainwindow.h"

#include <QApplication>
#include "logindlg.h"
#include "equipment.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDlg dlg;

    if(dlg.exec() == QDialog::Accepted){
        //读取配置文件，初始化设备列表
        equipment *eqm = new equipment();

        //展示页面
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}
