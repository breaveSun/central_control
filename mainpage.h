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
    void goLightSignal(PageBack pb);
    void goCurtainSignal(PageBack pb);

private slots:
    void goLightSlot();
    void goCurtainSlot();

private:
    Ui::mainPage *ui;
};

#endif // MAINPAGE_H
