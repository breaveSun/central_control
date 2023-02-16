#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class mainPage;
}

class mainPage : public QWidget
{
    Q_OBJECT

public:
    explicit mainPage(QWidget *parent = nullptr);
    ~mainPage();

signals:
    void goCtrlListSignal(enum PageBack pb,int houseId,int spaceId,int roomId);
    void goHomeSignal(enum PageBack pb,int houseId,int spaceId,int roomId);

private slots:
    void goCtrlListSlot();
    void goHomeSlot();

private:
    Ui::mainPage *ui;
};

#endif // MAINPAGE_H
