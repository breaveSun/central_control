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
    void setData(int buildId_,int spaceId,int roomId);

signals:
    void goBackSignal(PageBack pb,int index);

private slots:
    void goBackSlot();
    void closeAllSlot();

private:
    Ui::curtainPage *ui;
    QVector<curtainOpen *> curtainWidgetList_;
    QVariantMap* pRoomData_;
};

#endif // CURTAINPAGE_H
