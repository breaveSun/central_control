#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "common.h"

namespace Ui {
class homePage;
}

class homePage : public QWidget
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = nullptr);
    ~homePage();

signals:
    void goLightSignal(PageBack pb);

private slots:
    void goLightSlot();

private:
    Ui::homePage *ui;
};

#endif // HOMEPAGE_H
