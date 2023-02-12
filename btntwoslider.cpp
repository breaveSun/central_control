#include "btntwoslider.h"
#include "ui_btntwoslider.h"
#include "titleicon.h"
#include "common.h"
#include <iostream>
#include <qdebug.h>

btnTwoSlider::btnTwoSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnTwoSlider)
{
    ui->setupUi(this);
    ui->lightListSwitch->setChecked(false);
    ui->lightListSwitch->setTextOn("");
    ui->lightListSwitch->setTextOff("");
    ui->lightListSwitch->setBgColorOn(QColor("#D2AA74"));
    ui->lightListSwitch->setBgColorOff(QColor("#353638"));
    ui->lightSet->setVisible(false);

    connect(ui->lightListSwitch, SIGNAL(statusChanged(qint16,bool)), SLOT(statusChanged(qint16,bool)));

    ui->rSlider_2->setRange(0,255);
    ui->rSlider_2->setTitle("R");
    ui->gSlider_2->setRange(0,255);
    ui->gSlider_2->setTitle("G");
    ui->bSlider_2->setRange(0,255);
    ui->bSlider_2->setTitle("B");
    connect(ui->rSlider_2, SIGNAL(valueChanged()), SLOT(rgbValueChanged()));
    connect(ui->gSlider_2, SIGNAL(valueChanged()), SLOT(rgbValueChanged()));
    connect(ui->bSlider_2, SIGNAL(valueChanged()), SLOT(rgbValueChanged()));

    ui->rgbEdit->setStyleSheet("padding-left:10px;background-color: rgb(53,54,56);");

}

btnTwoSlider::~btnTwoSlider()
{
    delete ui;
}

void btnTwoSlider::setName(QString name){
    ui->lightTitle->setText(name);
}
void btnTwoSlider::setIcon(QString icon){
    ui->lightTitle->setIcon(icon);
}
void btnTwoSlider::setColor(QString color){
    ui->preColorBox->setStyleSheet("background-color:#"+color+";");
    //字符串拆分 两两为一组16进制 转10进制赋值给rgb
    int red,green,blue;
    toRGB(red,green,blue,color.toStdString());
    ui->rSlider_2->setNum(red);
    ui->gSlider_2->setNum(green);
    ui->bSlider_2->setNum(blue);
}

//void btnTwoSlider::reSize(int width,int height){
//    ui->lightSet->setGeometry(0,0,width,height);
//}
void btnTwoSlider::shutOff(){
    ui->lightListSwitch->setChecked(false);
}

void btnTwoSlider::statusChanged(qint16 id,bool checked)
{
    //灯光控制项展开和关闭
    ui->lightSet->setVisible(checked);
    ui->lightFrame->setFixedHeight(ui->lightFrame->sizeHint().height());
    setFixedHeight(sizeHint().height());
    //修改背景色 //todo::样式不对
    if (checked){
        setStyleSheet("background-color:rgb(34,34,34);");
    } else {
        setStyleSheet("background-color:rgb(23,23,23);");
    }


//    setStyleSheet("QWidget#lightSet{background-color:red;border-radius: 0px;}QWidget#widget{background-color:yellow;border-radius: 0px;}");
    emit lightSwitch();
}

void btnTwoSlider::rgbValueChanged(){
    int r = ui->rSlider_2->value();
    int g = ui->gSlider_2->value();
    int b = ui->bSlider_2->value();
    QString rgbString = QString::fromStdString(toHex(r)+toHex(g)+toHex(b));
    ui->preColorBox->setStyleSheet("background-color:#"+rgbString+";");
    ui->rgbEdit->setText(rgbString);
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
    int a = num >> 16;
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

