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
class serverPushThread;
class wsClient;
class messageCenter;
class QProcess;
class printer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
//    void closeEvent(QCloseEvent* event);

private slots:
    //页面跳转
    void switchPage(enum PageBack pb,int houseId,int soaceId,int roomId);
    void startWS(QString uid);
private:
    homePage *pHomePage_;
    lightPage *pLightPage_;
    mainPage *pMainPage_;
    curtainPage *pCurtainPage_;
    ctrlListPage *pCtrlListPage_;
    messageCenter *pMessageCenter_;

    wsClient *pWSClient_;

    Ui::MainWindow *ui;


    QProcess *pCaller_;
    printer *pPrinter_;
signals:
    void startThreadWork();
private slots:
//    void changeStyleSlot();
};
#endif // MAINWINDOW_H
