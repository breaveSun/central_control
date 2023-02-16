#ifndef CURTAINOPEN_H
#define CURTAINOPEN_H

#include <QWidget>

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

    void setId(int id);

    void setName(QString name);

    void setIcon(int icon);

    void setOpenIcon(int icon);

    void setCloseIcon(int icon);

    void hideAngle();
    void showAngle();

    void setDirection(QString direction);

    //外部类调用关闭窗帘
    void closeCurtain();

signals:
    void toThread();
private:
    //开启线程
    void startThread();
private slots:
    void startOpen();
    void startClose();
    void stopPressed();
    void stopClicked();
    //线程更新滑动条样式
    void threadUpdateSlider();
    //线程关闭提示
    void threadFinish();

private:
    int id_;
    Ui::curtainOpen *ui;
    titleIcon *pTitleIcon_;
    QThread *pThTest_;
    curtainThread *pCurtainThread_;
    bool movingOpen_;
    bool movingClose_;
};

#endif // CURTAINOPEN_H
