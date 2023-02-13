#ifndef LIGHTPAGE_H
#define LIGHTPAGE_H

#include <QWidget>
#include "common.h"
class btnTwoSlider;
namespace Ui {
class lightPage;
}

class lightPage : public QWidget
{
    Q_OBJECT

public:
    explicit lightPage(QWidget *parent = nullptr);
    ~lightPage();

    //设置页面组件数据
    void setData(int buildId_,int spaceId,int roomId);


signals:
    void goBackSignal(PageBack pb,int index);

private slots:
    void goBackSlot();
    void closeAllSlot();
    void ligthSwitch();

private:
    Ui::lightPage *ui;
    QVector<btnTwoSlider *> lightWidgetList_;
    QVariantMap* pRoomData_;
};

#endif // LIGHTPAGE_H
