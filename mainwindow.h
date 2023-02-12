#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class equipment;
class lightPage;
class mainPage;
class curtainPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //设置数据
    void setData();

//    btnTwoSlider *titleBtnShow1;
//    btnTwoSlider *titleBtnShow2;
private slots:
    //页面跳转
    void switchPage(PageBack pb);

private:
    //数据
    equipment *pEqm_;
    lightPage *pLightPage_;
    mainPage *pMainPage_;
    curtainPage *pCurtainPage_;

    Ui::MainWindow *ui;
private slots:
//    void changeStyleSlot();
};
#endif // MAINWINDOW_H
