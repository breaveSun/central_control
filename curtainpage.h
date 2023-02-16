#ifndef CURTAINPAGE_H
#define CURTAINPAGE_H

#include <QWidget>
#include "common.h"
class curtainOpen;
namespace Ui {
class curtainPage;
}

class curtainPage : public QWidget
{
    Q_OBJECT

public:
    explicit curtainPage(QWidget *parent = nullptr);
    ~curtainPage();

    //设置页面组件数据
    void setData(int houseId,int spaceId,int roomId);

signals:
    void goBackSignal(PageBack pb,int buildId_,int spaceId,int roomId);

private slots:
    void goBackSlot();
    void closeAllSlot();

private:
    Ui::curtainPage *ui;
    QVector<curtainOpen *> curtainWidgetList_;
//    QVariantMap* pRoomData_;
    int houseId_;
    int spaceId_;
    int roomId_;
};

#endif // CURTAINPAGE_H
