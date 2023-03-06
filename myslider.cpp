#include "myslider.h"
#include "ui_myslider.h"
#include <qdebug.h>
#include <QtCore/qmath.h>

mySlider::mySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mySlider)
{
    ui->setupUi(this);
    ui->hSlider->setRange(min_,max_);
    ui->sliderTitle->setFixedWidth(30);
    connect(ui->hSlider,&QSlider::sliderMoved,this,&mySlider::move);
    connect(ui->hSlider,&QSlider::sliderReleased,this,&mySlider::released);
    connect(ui->hSlider,&QSlider::sliderPressed,this,&mySlider::pressed);
}

mySlider::mySlider(QWidget *parent,int min,int max) :
    QWidget(parent),
    ui(new Ui::mySlider),
    min_(min),max_(max)
{
    ui->setupUi(this);
    ui->hSlider->setRange(min_,max_);
    connect(ui->hSlider,&QSlider::sliderMoved,this,&mySlider::move);
    connect(ui->hSlider,&QSlider::sliderReleased,this,&mySlider::released);
    connect(ui->hSlider,&QSlider::sliderPressed,this,&mySlider::pressed);
}

mySlider::~mySlider()
{
    delete ui;
}

void mySlider::setTitle(QString title){
    ui->sliderTitle->setText(title);
}

void mySlider::setNum(QString num){
    int n =num.toInt();
    if(n<min_ || n>max_){
        n = min_;
        num = QString::number(min_);
    }
    ui->sliderNum->setText(num);
    ui->hSlider->setValue(n);
}

void mySlider::setUnit(QString unit){
    ui->sliderUnit->setText(unit);
}

void mySlider::setRange(int min,int max){
    min_ = min;
    max_ = max;
    ui->hSlider->setRange(min,max);
}

void mySlider::setPageStep(int step){
    step_ = step;
//    ui->hSlider->setTickInterval(step);
//    ui->hSlider->setPageStep(step);
}


void mySlider::setTitleWidth(int titleWidth,int numWidth){
    ui->sliderTitle->setFixedWidth(titleWidth);
    ui->sliderNum->setFixedWidth(numWidth);
}

int mySlider::getNum(){
    return ui->hSlider->value();
}

int mySlider::max(){
    return max_;
}
int mySlider::min(){
    return min_;
}
void mySlider::move(int position){
    ui->sliderNum->setText(QString::number(position));
    emit sliderMoved(position);
}

void mySlider::released(){
    int value = ui->hSlider->value();
    if(step_>1){
        int rem = value%step_;
        if(rem>(step_/2)){
            value = (value/step_+1)*step_;
        } else {
            value = (value/step_)*step_;
        }
        ui->hSlider->setValue(value);
    }
    ui->sliderNum->setText(QString::number(value));
    emit sliderReleased();
}

void mySlider::pressed(){
    int value = ui->hSlider->value();
    ui->sliderNum->setText(QString::number(value));
    emit sliderPressed();
}
