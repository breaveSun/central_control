#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class lightPage;
class mainPage;
class curtainPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


//    btnTwoSlider *titleBtnShow1;
//    btnTwoSlider *titleBtnShow2;
private slots:
    //页面跳转
    void switchPage(PageBack pb,int index);

private:
    lightPage *pLightPage_;
    mainPage *pMainPage_;
    curtainPage *pCurtainPage_;

    Ui::MainWindow *ui;
private slots:
//    void changeStyleSlot();
};
#endif // MAINWINDOW_H
