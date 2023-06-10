#include "vicontxt.h"
#include "ui_vicontxt.h"

vIconTxt::vIconTxt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vIconTxt)
{
    ui->setupUi(this);

    pTxt_ = new QLabel;
    pTxt_->setObjectName("txt");
    pTxt_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    pTxt_->setAlignment(Qt::AlignHCenter);

    pIcon_ = new QLabel;
    pIcon_->setObjectName("icon");
    pIcon_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    pIcon_->setAlignment(Qt::AlignHCenter);

    QVBoxLayout* pLayoutInfoComing_ = new QVBoxLayout(ui->vIconTxtBtn);
    pLayoutInfoComing_->setMargin(5);
    pLayoutInfoComing_->addWidget(pIcon_);
    pLayoutInfoComing_->addWidget(pTxt_);

    connect(ui->vIconTxtBtn, SIGNAL(released()),this, SLOT(btnPressedSlot()));

}

vIconTxt::~vIconTxt()
{
    delete ui;
}

void vIconTxt::setId(QString id){
    id_ = id;
}

void vIconTxt::setTxt(QString txt){
    pTxt_->setText(txt);
}

void vIconTxt::setIcon(int icon){
    Common::setLabelIcon(pIcon_,icon);
}

void vIconTxt::setIconColor(QString color){
    setStyleSheet("#icon{color:"+color+";}");
}

/*
void vIconTxt::setTxtColor(QString color){
    setStyleSheet("#txt{color:"+color+";}");
}

void vIconTxt::setBGColor(QString color){
    ui->vIconTxtBtn->setStyleSheet("background-color:"+color+";");
}
*/
void vIconTxt::setTwoColor(QString color,QString bgColor){
    setStyleSheet("*{background-color:"+bgColor+";}#icon,#txt{color:"+color+";}");
}

void vIconTxt::setWidth(int width){
    ui->vIconTxtBtn->setFixedWidth(width);
}

void vIconTxt::setHeight(int height){
    ui->vIconTxtBtn->setFixedHeight(height);

}

void vIconTxt::btnPressedSlot(){
    emit btnPressed(id_);
}
