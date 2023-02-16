#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class homePage;
class lightPage;
class mainPage;
class curtainPage;
class ctrlListPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //页面跳转
    void switchPage(enum PageBack pb,int houseId,int soaceId,int roomId);

private:
    homePage *pHomePage_;
    lightPage *pLightPage_;
    mainPage *pMainPage_;
    curtainPage *pCurtainPage_;
    ctrlListPage *pCtrlListPage_;

    Ui::MainWindow *ui;
private slots:
//    void changeStyleSlot();
};
#endif // MAINWINDOW_H
