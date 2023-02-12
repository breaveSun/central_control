#include "myslider.h"
#include "ui_myslider.h"
#include <qdebug.h>

mySlider::mySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mySlider)
{
    ui->setupUi(this);
    ui->hSlider->setRange(min_,max_);
    connect(ui->hSlider,&QSlider::sliderMoved,this,&mySlider::move);
}

mySlider::mySlider(QWidget *parent,int min,int max) :
    QWidget(parent),
    ui(new Ui::mySlider),
    min_(min),max_(max)
{
    ui->setupUi(this);
    ui->hSlider->setRange(min_,max_);
    connect(ui->hSlider,&QSlider::sliderMoved,this,&mySlider::move);
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
    if(n<0 || n>100){
        n = 0;
        num = "0";
    }
    ui->sliderNum->setText(num);
    ui->hSlider->setValue(n);
}

void mySlider::setUnit(QString unit){
    ui->sliderUnit->setText(unit);
}

void mySlider::setRange(int min,int max){
    ui->hSlider->setRange(min,max);
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
void mySlider::move(int value){
    ui->sliderNum->setText(QString::number(value));
    //todo::调用控制接口
}
