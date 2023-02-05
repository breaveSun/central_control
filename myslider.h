#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>

namespace Ui {
class mySlider;
}

class mySlider : public QWidget
{
    Q_OBJECT

public:
    explicit mySlider(QWidget *parent = nullptr);
    ~mySlider();
    void setTitle(QString title);
    void setNum(QString num);
    void setUnit(QString unit);
    void move(int value);
private:
    Ui::mySlider *ui;
};

#endif // MYSLIDER_H
