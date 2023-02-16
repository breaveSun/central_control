#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class homePage;
}
class roomCard;

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
private:
    Ui::homePage *ui;
    QWidget* pSpacesChange_;
    QVector<roomCard *> roomCardWidgetList_;
    QVariantMap spaceData_;
    int houseId_;
    int spaceId_;
};

#endif // HOMEPAGE_H
