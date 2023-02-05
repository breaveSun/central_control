#include "btntwoslider.h"
#include "ui_btntwoslider.h"

btnTwoSlider::btnTwoSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::btnTwoSlider)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(false);
    ui->widget->hide();
    connect(ui->radioButton,&QRadioButton::toggled,[=](){
        if (ui->radioButton->isChecked()){
            ui->widget->show();
        } else {
            ui->widget->hide();
        }
    });

    this->brightness = new mySlider;
    this->brightness->setTitle("亮度");
    this->brightness->setNum("30");
    this->brightness->setUnit("%");
    this->colorTem = new mySlider;
    this->colorTem->setTitle("色温");
    this->colorTem->setNum("50");
    this->colorTem->setUnit("%");
    ui->sliderLayout->addWidget(this->brightness);
    ui->sliderLayout->addWidget(this->colorTem);

}

btnTwoSlider::~btnTwoSlider()
{
    delete ui;
}

void btnTwoSlider::setName(QString name){
    ui->label->setText(name);
}
void btnTwoSlider::setbkColor(QString color){
    ui->widget->setStyleSheet("background-color:"+color+";");
}
void btnTwoSlider::reSize(int width,int height){
    ui->widget->setGeometry(0,0,width,height);

}
