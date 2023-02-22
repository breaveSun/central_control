#include "btntwoslider.h"
#include "ui_btntwoslider.h"
#include "titleicon.h"
#include "common.h"
#include "equipment.h"
#include <iostream>
#include <qdebug.h>

btnTwoSlider::btnTwoSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnTwoSlider)
{
    ui->setupUi(this);
    ui->lightListSwitch->setTextOn("");
    ui->lightListSwitch->setTextOff("");
    ui->lightListSwitch->setBgColorOn(QColor("#D2AA74"));
    ui->lightListSwitch->setBgColorOff(QColor("#353638"));
    connect(ui->lightListSwitch, SIGNAL(statusChanged(qint16,bool)), SLOT(statusChanged(qint16,bool)));

    ui->lightSet->setVisible(false);
    ui->lightNumSlider->setTitle("亮度");
    ui->lightNumSlider->setUnit("%");
    connect(ui->lightNumSlider, SIGNAL(sliderReleased()), SLOT(brightnessValueChanged()));
    ui->temNumSlider->setTitle("色温");
    ui->temNumSlider->setUnit("K");
    connect(ui->temNumSlider, SIGNAL(sliderReleased()), SLOT(colorTemperatureValueChanged()));

    pColorTextPreFix_ = new QLabel;
    pColorTextPreFix_->setObjectName("colorTextPreFix");
    pColorTextPreFix_->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Expanding);
    pColorTextPreFix_->setText("#");
    pLayoutInfoComing_ = new QVBoxLayout(ui->rgbEdit);
    pLayoutInfoComing_->addWidget(pColorTextPreFix_);
    ui->rgbEdit->setAlignment( Qt::AlignVCenter);
    ui->rgbEdit->setStyleSheet("#rgbEdit{padding-left:18px;background-color: rgb(53,54,56);}#colorTextPreFix{background-color: rgb(53,54,56);}");
    connect(ui->rgbEdit,SIGNAL(textChanged),this,SIGNAL(textChanged));


    ui->rSlider_2->setRange(0,255);
    ui->rSlider_2->setTitle("R");
    ui->gSlider_2->setRange(0,255);
    ui->gSlider_2->setTitle("G");
    ui->bSlider_2->setRange(0,255);
    ui->bSlider_2->setTitle("B");
    connect(ui->rSlider_2, SIGNAL(sliderReleased()), SLOT(rgbValueChanged()));
    connect(ui->gSlider_2, SIGNAL(sliderReleased()), SLOT(rgbValueChanged()));
    connect(ui->bSlider_2, SIGNAL(sliderReleased()), SLOT(rgbValueChanged()));

    //    pColorTextPreFix_->setStyleSheet("background-color:#EB4D3C;color:#FFFFFF;");

}

btnTwoSlider::~btnTwoSlider()
{
    delete ui;
}
void btnTwoSlider::setData(lightingStruct lighting){
    lighting_ = lighting;
    setName(lighting.name);
    setIcon(icon::getIcon(lighting.icon));


    lightingFuncStruct func = lighting.function;

    //亮度
    if(func.dimming==0){

    } else{

        ui->lightNumSlider->setNum(equipment::getDeviceValue(lighting_.dimming_absolute_feedback));
    }

    //色温
    if(func.color_temperature==0){

    }else{
        int min = lighting_.min_color_temperature.toInt();
        int max = lighting_.max_color_temperature.toInt();
        ui->temNumSlider->setRange(min,max);
        ui->temNumSlider->setNum(equipment::getDeviceValue(lighting_.color_temperature_feedback));
    }

    //颜色
    if(func.hue==0){
        hideColor();
    } else {
        showColor();
        //todo::默认值应该在读取数据的时候确认
        QString hueValue = equipment::getDeviceValue(lighting_.hue_feedback);
        ui->rgbEdit->setText(hueValue);
        txtSetColor(hueValue);
    }

    //根据开关设置样式
    bool switchStatus = equipment::getDeviceValue(lighting_.switch_feedback)=="1"?true:false;
    ui->lightListSwitch->blockSignals(true);
    ui->lightListSwitch->setChecked(switchStatus);
    ui->lightListSwitch->blockSignals(false);
    //灯光控制项展开和关闭
    ui->lightSet->setVisible(switchStatus);
    ui->lightFrame->setFixedHeight(ui->lightFrame->sizeHint().height());
    setFixedHeight(sizeHint().height());
    //修改背景色
    if (switchStatus){
        setStyleSheet("background-color:rgb(34,34,34);");
    } else {
        setStyleSheet("background-color:rgb(23,23,23);");
    }
}
void btnTwoSlider::setName(QString name){
    ui->lightTitle->setText(name);
}

void btnTwoSlider::setIcon(int icon){
    ui->lightTitle->setIcon(icon);
}

void btnTwoSlider::txtSetColor(QString color){
    ui->preColorBox->setStyleSheet("background-color:#"+color+";");
    //字符串拆分 两两为一组16进制 转10进制赋值给rgb
    int red,green,blue;
    toRGB(red,green,blue,color.toStdString());
    ui->rSlider_2->setNum(red);
    ui->gSlider_2->setNum(green);
    ui->bSlider_2->setNum(blue);
}

void btnTwoSlider::setSwitch(bool s,bool block){
    if(block){
        ui->lightListSwitch->blockSignals(true);
    }
    ui->lightListSwitch->setChecked(s);
    if(block){
        ui->lightListSwitch->blockSignals(false);
    }
}

void btnTwoSlider::setBrightness(QString num){
    ui->lightNumSlider->setNum(num);
}

void btnTwoSlider::setColorTemperature(QString num){
    ui->temNumSlider->setNum(num);
}

void btnTwoSlider::setColor(QString color){
    ui->rgbEdit->setText(color);
    ui->preColorBox->setStyleSheet("background-color:#"+color+";");
    //字符串拆分 两两为一组16进制 转10进制赋值给rgb
    int red,green,blue;
    toRGB(red,green,blue,color.toStdString());
    ui->rSlider_2->setNum(red);
    ui->gSlider_2->setNum(green);
    ui->bSlider_2->setNum(blue);
}

void btnTwoSlider::shutOff(bool block){
    if(block){
        ui->lightListSwitch->blockSignals(true);
    }
    ui->lightListSwitch->setChecked(false);
    if(block){
        ui->lightListSwitch->blockSignals(false);
    }
}

void btnTwoSlider::hideColor(){
    ui->colorCon->setVisible(false);
}

void btnTwoSlider::showColor(){
    ui->colorCon->setVisible(true);
}

QString btnTwoSlider::getGroupId(FUNCTION_TYPE ft){
    switch (ft) {
    case FT_SWITCH:
        return lighting_.switch_feedback;
        break;
    case FT_BRIGHTNESS:
        return lighting_.dimming_absolute_feedback;
        break;
    case FT_COLOR_TEMPERATURE:
        return lighting_.color_temperature_feedback;
        break;
    case FT_HUE:
        return lighting_.hue_feedback;
        break;
    default:
        return "";
        break;
    }
}

void btnTwoSlider::statusChanged(qint16 id,bool checked)
{
    //灯光控制项展开和关闭
    ui->lightSet->setVisible(checked);
    ui->lightFrame->setFixedHeight(ui->lightFrame->sizeHint().height());
    setFixedHeight(sizeHint().height());
    //修改背景色
    if (checked){
        setStyleSheet("background-color:rgb(34,34,34);");
    } else {
        setStyleSheet("background-color:rgb(23,23,23);");
    }

    //发送请求
    QVariantMap lightMap;
    lightMap["group_id"] = lighting_.Switch;
    lightMap["switch"] = checked?"1":"0";
    QVariantList data;
    data.append(lightMap);
    QString jsonStr = Common::ListToString(data);
    equipment::lightControl(jsonStr);


    emit lightSwitch();
}

void btnTwoSlider::rgbValueChanged(){
    int r = ui->rSlider_2->value();
    int g = ui->gSlider_2->value();
    int b = ui->bSlider_2->value();
    QString rgbString = QString::fromStdString(toHex(r)+toHex(g)+toHex(b));
    ui->preColorBox->setStyleSheet("background-color:#"+rgbString+";");
    ui->rgbEdit->setText(rgbString);
    //发送请求
    QVariantMap lightMap;
    lightMap["group_id"] = lighting_.hue;
    lightMap["hue"] = rgbString;
    QVariantList data;
    data.append(lightMap);
    QString jsonStr = Common::ListToString(data);
    equipment::lightControl(jsonStr);

}
void btnTwoSlider::brightnessValueChanged(){
    int value = ui->lightNumSlider->getNum();
    //发送请求
    QVariantMap lightMap;
    lightMap["group_id"] = lighting_.dimming_absolute;
    lightMap["brightness"] = QString::number(value);
    QVariantList data;
    data.append(lightMap);
    QString jsonStr = Common::ListToString(data);
    equipment::lightControl(jsonStr);
}

void btnTwoSlider::colorTemperatureValueChanged(){
    int value = ui->temNumSlider->getNum();
    //发送请求
    QVariantMap lightMap;
    lightMap["group_id"] = lighting_.color_temperature;
    lightMap["color_temperature"] = QString::number(value);
    QVariantList data;
    data.append(lightMap);
    QString jsonStr = Common::ListToString(data);
    equipment::lightControl(jsonStr);
}

std::string btnTwoSlider::toHex(int num)
{
    if(num == 0)
        return "00";

    std::string res = "";
    std::string hex[16] = {"0", "1", "2", "3", "4", "5", "6", "7",
                      "8", "9", "a", "b", "c", "d", "e", "f"};

    unsigned int num2 = num;//无论正负，全部转换成无符号整型
    while(num2)
    {
        res = hex[num2 % 16] + res;//取余即是最低位
        num2 /= 16;
    }
    if(res.size()==1){
        res = "0"+res;
    }
    return res;
}
//网上扒来的高效率实现
long btnTwoSlider::hextonum(std::string str) {
    char in[1024] = { 0 };
    strcpy(in, str.c_str());
    // 用指针循环字符串
    char* pin = in;
    // 以累加方式获得输出结果
    long out = 0;
    while (*pin != 0) {
        // 针对每一个输入字符，依次移位out到高一级(4位对应一个bit)
        out <<= 4;
        // 对这个字符进行位运算，并且结果加到out变量的低位上。
        out += (*pin < 'A') ? *pin & 0xF : (*pin & 0x7) + 9;
        pin++;
    }
    return out;
}
//#ffffff转rgb(255,255,255)
void btnTwoSlider::toRGB(int &red,int &green,int &blue,std::string color16){
    //字符串转整型
    long num = hextonum(color16);
    //16进制色彩表示中，两个数字一个完整的色彩部件（red，green，blue）
    //2进位存储表达中，8个字节位表达一个16进制整数
    //移位16个字节位，并执行&操作，可以得出red部件的数值
//    int a = num >> 16;
    red = num >> 16 & 0xFF;
    //移位8个字节位，并执行&操作，可以得出green部件的数值
    green = num >> 8 & 0xFF;
    //低位8个字节执行&操作，可以得出blue部件的数值
    blue = num & 0xFF;

    //如果要得出每个部件数值的浮点表达，执行除法即可
//    float redFloat = red/(255.0);

//    qDebug()<<color16.c_str()<<" --> R:"<<red<<" G:"<<green<<" B:"<<blue;

    return;
}

