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

    int getNum();
    int max();
    int min();
signals:
    void valueChanged();


private slots:
    void move(int value);
private:
    Ui::mySlider *ui;
    int min_ = 0;
    int max_ = 100;
};

#endif // MYSLIDER_H
