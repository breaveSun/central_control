#ifndef ROOMCARD_H
#define ROOMCARD_H

#include <QWidget>
#include "common.h"

namespace Ui {
class roomCard;
}
class verticalTxtUnit;
class verticalicontextBK;
struct roomParamStruct;
struct roomSceneStruct;
class roomCard : public QWidget
{
    Q_OBJECT

public:
    explicit roomCard(QWidget *parent = nullptr);
    ~roomCard();

    void setName(QString name);

    void setIcon(int icon);

    void setData(roomStruct room);

    void setEnableDeviceNum(QString num);

    void updateEnableDeviceNum();

    int getRoomId();

private:
    void setParams(QVector<roomParamStruct> params);

    void setScenes(QVector<roomSceneStruct> scenes,QString current_scene);
signals:
    void goPage(PageBack pb, int houseId,int spaceId,int roomId);

private slots:
    void slipLeft();
    void slipRight();
    void checkDevice();
    void onClickClose();
    void changeScene(QString id);
    void sliderChanged(int value);

private:
    Ui::roomCard *ui;
    QVector<verticalTxtUnit *> paramsWidgetList_;
    QVector<verticalicontextBK *> scenesWidgetList_;
    roomStruct room_;
};

#endif // ROOMCARD_H
