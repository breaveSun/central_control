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
class QVBoxLayout;
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
    void txtSetColor(QString color);

    //灯的开关
    void setSwitch(bool s,bool block=false);

    //设置灯的亮度
    void setBrightness(QString num);

    //设置灯的色温
    void setColorTemperature(QString num);

    //设置灯的颜色
    void setColor(QString color);

    //关闭
    void shutOff(bool block=false);

    //隐藏颜色配置
    void hideColor();

    //显示颜色配置
    void showColor();

    //获取灯查询数据的groupId
    QString getGroupId(FUNCTION_TYPE ft);

    void setFocusIn();

    QString getName();
//    mySlider *brightness;
//    mySlider *colorTem;
signals:
    void lightSwitch();
    void colorTxtMouseReleased();
    void focusOut();
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
    QLabel* pColorTextPreFix_;
    QVBoxLayout* pLayoutInfoComing_;

private slots:
    void statusChanged(qint16 id,bool checked);
    void rgbValueChanged();
    void brightnessValueChanged();
    void colorTemperatureValueChanged();

    //颜色文本编辑
    void editingFinished();
//    void returnPressed();
    void textEdited(QString txt);

};

#endif // BTNTWOSLIDER_H
