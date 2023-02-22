#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class homePage;
}
class roomCard;
class changeSpace;
struct spaceStruct;
class homePage : public QWidget
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = nullptr);
    ~homePage();

    //设置页面组件数据
    void setData(int houseId,int spaceId);

signals:
    void goPage(PageBack pb, int houseId,int spaceId,int roomId);

private slots:
    void spacesChange(bool clicked);
    void spaceChangeWidgetHide();
    void updateRooms(int houseId,int spaceId);
    void closeAllDevices(bool checked);
    void messageList(bool checked);
    //接收服务器推送
    void acceptPush(deviceDataStruct data);
private:
    Ui::homePage *ui;
    changeSpace* pChangeSpace_;
    QVector<roomCard *> roomCardWidgetList_;
    spaceStruct spaceData_;
    QVector<houseStruct>* houseData_;
    int houseId_ = 0;
    int spaceId_ = 0;
};

#endif // HOMEPAGE_H
