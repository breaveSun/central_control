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

signals:
    void goBackSignal(PageBack);

private slots:
    void goBackSlot();
    void closeAllSlot();

private:
    Ui::curtainPage *ui;
    curtainOpen *open1;
    curtainOpen *open2;
};

#endif // CURTAINPAGE_H
