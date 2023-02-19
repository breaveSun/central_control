#ifndef LIGHTPAGE_H
#define LIGHTPAGE_H

#include <QWidget>
#include "common.h"
class btnTwoSlider;
namespace Ui {
class lightPage;
}
struct lightingStruct;
class lightPage : public QWidget
{
    Q_OBJECT

public:
    explicit lightPage(QWidget *parent = nullptr);
    ~lightPage();

    //设置页面组件数据
    void setData(int houseId,int spaceId,int roomId);


signals:
    void goBackSignal(PageBack pb,int houseId,int spaceId,int roomId);

private slots:
    void goBackSlot();
    void closeAllSlot();
    void ligthSwitch();
    //接收服务器推送
    void acceptPush(deviceDataStruct data);

private:
    Ui::lightPage *ui;
    QVector<btnTwoSlider *> lightWidgetList_;
    QVector<lightingStruct> lightings_;
    roomStruct room_;
//    int houseId_;
//    int spaceId_;
//    int roomId_;
};

#endif // LIGHTPAGE_H
