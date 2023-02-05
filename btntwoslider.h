#ifndef BTNTWOSLIDER_H
#define BTNTWOSLIDER_H
#include "myslider.h"
#include <QWidget>

namespace Ui {
class btnTwoSlider;
}

class btnTwoSlider : public QWidget
{
    Q_OBJECT

public:
    explicit btnTwoSlider(QWidget *parent = nullptr);
    ~btnTwoSlider();
    void setName(QString name);
    void setbkColor(QString color);
    void reSize(int width,int height);

    mySlider *brightness;
    mySlider *colorTem;

private:
    Ui::btnTwoSlider *ui;
};

#endif // BTNTWOSLIDER_H
