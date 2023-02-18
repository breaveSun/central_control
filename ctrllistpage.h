#ifndef CTRLLISTPAGE_H
#define CTRLLISTPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class ctrlListPage;
}
class ctrlListItem;
class ctrlListPage : public QWidget
{
    Q_OBJECT

public:
    explicit ctrlListPage(QWidget *parent = nullptr);
    ~ctrlListPage();

    //设置页面组件数据
    void setData(int houseId_,int spaceId,int roomId);

signals:
    void goBackSignal(enum PageBack pb,int houseId,int spaceId,int roomId);
    void goDetailSignal(enum PageBack pb,int houseId,int spaceId,int roomId);

private slots:
    void goBackSlot();
    void goLightDetailSlot(enum PageBack pb,int houseId,int spaceId,int roomId);
    void goCurtainDetailSlot(enum PageBack pb,int houseId,int spaceId,int roomId);

private:
    Ui::ctrlListPage *ui;
    roomStruct pRoomData_;
    QVector<lightingStruct> lightings_;
    QVector<curtainStruct> curtains_;
    int houseId_;
    int spaceId_;
    int roomId_;

    ctrlListItem* pLightCtrl_;
    ctrlListItem* pCurtainCtrl_;

};

#endif // CTRLLISTPAGE_H
