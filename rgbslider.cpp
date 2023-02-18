#include "rgbslider.h"
#include "ui_rgbslider.h"
#include <qdebug.h>

rgbSlider::rgbSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rgbSlider)
{
    ui->setupUi(this);
    connect(ui->sliderLine,&QSlider::sliderMoved,this,&rgbSlider::move);
}

rgbSlider::rgbSlider(QWidget *parent,int min,int max) :
    QWidget(parent),
    ui(new Ui::rgbSlider),
    min_(min),max_(max)
{
    ui->setupUi(this);
    ui->sliderLine->setRange(min_,max_);
    connect(ui->sliderLine,&QSlider::valueChanged,this,&rgbSlider::move);
}

rgbSlider::~rgbSlider()
{
    delete ui;
}
int rgbSlider::value(){
    return ui->sliderLine->value();
}

void rgbSlider::setTitle(QString title){
    ui->rgbName->setText(title);
}

void rgbSlider::setNum(int num){
    QString n =QString::number(num);
    if(num<min_ || num>max_){
        n = QString::number(min_);
        num = min_;
    }
    ui->rgbNum->setText(n);
    ui->sliderLine->setValue(num);
}

void rgbSlider::setRange(int min,int max){
    min_ = min;
    max_ = max;
    ui->sliderLine->setRange(min,max);
}

void rgbSlider::move(int value){
    ui->rgbNum->setText(QString::number(value));
    emit valueChanged();
}

