#include "rgbslider.h"
#include "ui_rgbslider.h"
#include <qdebug.h>

rgbSlider::rgbSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rgbSlider)
{
    ui->setupUi(this);
    connect(ui->sliderLine,&QSlider::sliderMoved,this,&rgbSlider::move);
    connect(ui->sliderLine,&QSlider::sliderReleased,this,&rgbSlider::released);
    connect(ui->sliderLine,&QSlider::sliderPressed,this,&rgbSlider::pressed);
}

rgbSlider::rgbSlider(QWidget *parent,int min,int max) :
    QWidget(parent),
    ui(new Ui::rgbSlider),
    min_(min),max_(max)
{
    ui->setupUi(this);
    ui->sliderLine->setRange(min_,max_);
    connect(ui->sliderLine,&QSlider::sliderMoved,this,&rgbSlider::move);
    connect(ui->sliderLine,&QSlider::sliderReleased,this,&rgbSlider::released);
    connect(ui->sliderLine,&QSlider::sliderPressed,this,&rgbSlider::pressed);
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

void rgbSlider::setTitleWidth(int width){
    ui->rgbNum->setFixedWidth(width);
}

int rgbSlider::max(){
    return max_;
}

void rgbSlider::move(int position){
    ui->rgbNum->setText(QString::number(position));
    emit sliderMoved(position);
}

void rgbSlider::released(){
    int value = ui->sliderLine->value();
    ui->rgbNum->setText(QString::number(value));
    emit sliderReleased();
}

void rgbSlider::pressed(){
    int value = ui->sliderLine->value();
    ui->rgbNum->setText(QString::number(value));
    emit sliderPressed();
}

