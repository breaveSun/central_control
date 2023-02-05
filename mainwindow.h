#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btntwoslider.h"
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class equipment;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //页面跳转
    void switchPage();
    //设置数据
    void setData();

    btnTwoSlider *titleBtnShow1;
    btnTwoSlider *titleBtnShow2;

private:
    //数据
    equipment *pEqm_;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
