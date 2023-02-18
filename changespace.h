#ifndef CHANGESPACE_H
#define CHANGESPACE_H

#include <QWidget>

namespace Ui {
class changeSpace;
}
class labelBtn;
struct houseStruct;
struct spaceStruct;
class changeSpace : public QWidget
{
    Q_OBJECT

public:
    explicit changeSpace(QWidget *parent = nullptr);
    ~changeSpace();

    void setData(QVector<houseStruct>* house,int houseId,int spaceId);

    bool event(QEvent* event);
signals:
    void changeSpaceHide();
    void updateRooms(int houseId,int spaceId);

private slots:
    void btnHouseSlot(int houseId);
    void btnSpaceSlot(int spaceId);

private:
    void setSpaceData(QVector<spaceStruct> spaces,int spaceId);

private:
    Ui::changeSpace *ui;
    QVector<labelBtn *> houseBtnList_;
    QVector<labelBtn *> spaceBtnList_;
    QVector<houseStruct>* houses_;
    int houseId_;
    int spaceId_;
};

#endif // CHANGESPACE_H
