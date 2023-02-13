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
    void goLightSignal(PageBack pb,int index);
    void goCurtainSignal(PageBack pb,int index);

private slots:
    void goLightSlot();
    void goCurtainSlot();
    void goLightSlot2();
    void goCurtainSlot2();

private:
    Ui::mainPage *ui;
};

#endif // MAINPAGE_H
