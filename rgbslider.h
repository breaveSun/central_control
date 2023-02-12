#ifndef RGBSLIDER_H
#define RGBSLIDER_H

#include <QWidget>

namespace Ui {
class rgbSlider;
}

class rgbSlider : public QWidget
{
    Q_OBJECT

public:
    explicit rgbSlider(QWidget *parent = nullptr);
    explicit rgbSlider(QWidget *parent, int min, int max);
    ~rgbSlider();
    int value();
    void setTitle(QString title);
    void setNum(int num);
    void setRange(int min, int max);
signals:
    void valueChanged();
private slots:
    void move(int value);

private:
    Ui::rgbSlider *ui;
    int min_ = 0;
    int max_ = 100;
};

#endif // RGBSLIDER_H
