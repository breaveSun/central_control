#ifndef MESSAGECENTER_H
#define MESSAGECENTER_H

#include <QWidget>
#include "common.h"
namespace Ui {
class messageCenter;
}

class messageCenterItem;
class messageCenter : public QWidget
{
    Q_OBJECT

public:
    explicit messageCenter(QWidget *parent = nullptr);
    ~messageCenter();


signals:
    void goBackSignal(PageBack pb,int buildId_,int spaceId,int roomId);

private slots:

    void goBackSlot();

    void messageRead();

    //接收服务器推送
    void acceptPush(messageStruct message);

private:
    void getMessage();

    void show();

    //保存数据到文件
    void saveData();

private:
    bool newMessage_;
    Ui::messageCenter *ui;
    QVector<messageStruct> messages_;
    QVector<int> ids_;
    QVector<messageCenterItem*> messageWidgetList;
};

#endif // MESSAGECENTER_H
