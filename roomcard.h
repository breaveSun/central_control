#ifndef ROOMCARD_H
#define ROOMCARD_H

#include <QWidget>
#include "common.h"

namespace Ui {
class roomCard;
}
class verticalTxtUnit;
class verticalicontextBK;
class roomCard : public QWidget
{
    Q_OBJECT

public:
    explicit roomCard(QWidget *parent = nullptr);
    ~roomCard();

    void setName(QString name);

    void setIcon(int icon);

    void setData(int houseId,int spaceId,int roomId);

    void setParams(QVariantList params);

    void setScenes(QVariantList scenes);
signals:
    void goPage(PageBack pb, int houseId,int spaceId,int roomId);

private slots:
    void slipLeft();
    void slipRight();
    void checkDevice();
    void editScene();
    void onClickClose();

private:
    Ui::roomCard *ui;
    QVector<verticalTxtUnit *> paramsWidgetList_;
    QVector<verticalicontextBK *> scenesWidgetList_;
    int houseId_;
    int spaceId_;
    int roomId_;
};

#endif // ROOMCARD_H
