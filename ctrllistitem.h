#ifndef CTRLLISTITEM_H
#define CTRLLISTITEM_H

#include <QWidget>
#include "common.h"

namespace Ui {
class ctrlListItem;
}

class ctrlListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ctrlListItem(QWidget *parent = nullptr);
    ~ctrlListItem();

    void setName(QString name);

    void setIcon(int icon);

    //设置右侧按钮被点击后要跳转的页面
    void setGoPageData(enum PageBack pb,int houseId,int soaceId,int roomId);

signals:
    void goDetailPageSignal(enum PageBack pb,int houseId,int soaceId,int roomId);

private slots:
    void goDetailPage();

private:
    Ui::ctrlListItem *ui;
    int roomId_;
    int spaceId_;
    int houseId_;
    enum PageBack pb_;

};

#endif // CTRLLISTITEM_H
