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

signals:
    void goBackSignal(PageBack);

private slots:
    void goBackSlot();
    void closeAllSlot();
    void ligthSwitch();

private:
    Ui::lightPage *ui;
    btnTwoSlider *titleBtnShow1;
    btnTwoSlider *titleBtnShow2;
};

#endif // LIGHTPAGE_H
