#ifndef BTNTWOSLIDER_H
#define BTNTWOSLIDER_H
#include "myslider.h"
#include <common.h>

namespace Ui {
class btnTwoSlider;
}
class titleIcon;

typedef struct lightContrl{
    QString Switch;
    QString switch_value;
    QString brightness;
    QString brightness_value;
    QString hue;
    QString hue_value;
    QString color_temperature;
    QString color_temperature_value;
    QString group_id;
}lightContrl;
Q_DECLARE_METATYPE(lightContrl)

class btnTwoSlider : public QWidget
{
    Q_OBJECT

public:
    explicit btnTwoSlider(QWidget *parent = nullptr);
    ~btnTwoSlider();

    void setData(lightingStruct lighting);

    void setName(QString name);

    void setIcon(int icon);

    //通过输入框修改颜色
    void setColor(QString color);

    //关闭
    void shutOff(bool block=false);

    //隐藏颜色配置
    void hideColor();

    //显示颜色配置
    void showColor();


//    mySlider *brightness;
//    mySlider *colorTem;
signals:
    void lightSwitch();
private:
    //初始化默认的light struct
    void initLightContrl(lightContrl &initStruct);
    //10进制转16进制
    std::string toHex(int num);
    //字符串转数字
    long hextonum(std::string str);
    //16进制转字符串
    void toRGB(int &red,int &green,int &blue,std::string color16);


private:
    Ui::btnTwoSlider *ui;
    lightingStruct lighting_;

private slots:
    void statusChanged(qint16 id,bool checked);
    void rgbValueChanged();
    void brightnessValueChanged();
    void colorTemperatureValueChanged();

};

#endif // BTNTWOSLIDER_H
