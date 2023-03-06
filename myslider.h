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
    explicit mySlider(QWidget *parent,int min,int max);
    ~mySlider();
    void setTitle(QString title);
    void setNum(QString num);
    void setUnit(QString unit);
    void setRange(int min,int max);
    void setPageStep(int step);
    void setTitleWidth(int titleWidth = 30,int numWidth = 30);

    int getNum();
    int max();
    int min();
signals:
    void sliderMoved(int value);
    void sliderReleased();
    void sliderPressed();


private slots:
    void move(int value);
    void released();
    void pressed();
private:
    Ui::mySlider *ui;
    int min_ = 0;
    int max_ = 100;
    int step_ = 1;
};

#endif // MYSLIDER_H
