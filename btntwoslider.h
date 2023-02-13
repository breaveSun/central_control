#ifndef BTNTWOSLIDER_H
#define BTNTWOSLIDER_H
#include "myslider.h"
#include <QWidget>

namespace Ui {
class btnTwoSlider;
}
class titleIcon;

class btnTwoSlider : public QWidget
{
    Q_OBJECT

public:
    explicit btnTwoSlider(QWidget *parent = nullptr);
    ~btnTwoSlider();
    void setName(QString name);
    void setIcon(QString icon);
    //通过输入框修改颜色
    void setColor(QString color);
    //关闭
    void shutOff();
    //隐藏颜色配置
    void hideColor();
    //显示颜色配置
    void showColor();

    mySlider *brightness;
    mySlider *colorTem;
signals:
    void lightSwitch();
private:
    //10进制转16进制
    std::string toHex(int num);
    //字符串转数字
    long hextonum(std::string str);
    //16进制转字符串
    void toRGB(int &red,int &green,int &blue,std::string color16);

private:
    Ui::btnTwoSlider *ui;

private slots:
    void statusChanged(qint16 id,bool checked);
    void rgbValueChanged();

};

#endif // BTNTWOSLIDER_H
