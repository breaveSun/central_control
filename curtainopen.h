#ifndef CURTAINOPEN_H
#define CURTAINOPEN_H

//#include <QWidget>
#include "common.h"

namespace Ui {
class curtainOpen;
}

class titleIcon;
class QThread;
class curtainThread;
class curtainOpen : public QWidget
{
    Q_OBJECT

public:
    explicit curtainOpen(QWidget *parent = nullptr);
    ~curtainOpen();

    void setData(curtainStruct curtain);

    void setId(int id);

    void setName(QString name);

    void setIcon(int icon);

    void setOpenIcon(int icon);

    void setCloseIcon(int icon);

    void hideAngle();
    void showAngle();

    void setDirection(QString direction);

    //外部类调用关闭窗帘(页面关闭，发送请求在外部类)
    void closeCurtain();

//signals:
//    void toThread();
//private:
//    //开启线程
//    void startThread();
private slots:
    void startOpen();
    void startClose();
    void stopPressed();
    void openCloseSliderReleased();
    void angleSliderReleased();

private:
    int id_;
    curtainStruct curtain_;
    Ui::curtainOpen *ui;
    titleIcon *pTitleIcon_;
    QThread *pThTest_;
    curtainThread *pCurtainThread_;
    bool movingOpen_;
    bool movingClose_;
};

#endif // CURTAINOPEN_H
