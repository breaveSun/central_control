#ifndef MESSAGECENTERITEM_H
#define MESSAGECENTERITEM_H

#include <QWidget>
#include <common.h>
#include <QVBoxLayout>

namespace Ui {
class messageCenterItem;
}

class titleIcon;
class messageCenterItem : public QWidget
{
    Q_OBJECT

public:
    explicit messageCenterItem(QWidget *parent = nullptr);
    ~messageCenterItem();

    void setData(messageStruct curtain);

    //未读变已读
    void read();

private:
    messageStruct message_;
    Ui::messageCenterItem *ui;
    QLabel* pRedPoint_;
    QLabel* pRedPointBrother_;
    QVBoxLayout* pLayoutInfoComing_;
};

#endif // MESSAGECENTERITEM_H
