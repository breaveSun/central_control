#include "verticalicontextbk.h"
#include "ui_verticalicontextbk.h"
#include "verticalicontext.h"

verticalicontextBK::verticalicontextBK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verticalicontextBK)
{
    ui->setupUi(this);
    widget = new verticalIconText(this);
    ui->verticalicontextBKFrame->layout()->addWidget(widget);
    connect(widget, SIGNAL(btnPressed()),this, SLOT(btnPressedSlot()));
    connect(widget, SIGNAL(btnClicked()),this, SLOT(btnClickedSlot()));
}

verticalicontextBK::~verticalicontextBK()
{
    delete ui;
}

void verticalicontextBK::setId(QString id){
    id_ = id;
}

void verticalicontextBK::setTxt(QString txt){
    widget->setTxt(txt);
}

void verticalicontextBK::setIcon(int icon){
    widget->setIcon(icon);
}

void verticalicontextBK::setBKColor(QString color){
    setStyleSheet("*{background-color:"+color+";}");
}

void verticalicontextBK::setColor(QString color){
    setStyleSheet("#icon,#txt{color:"+color+";}");
}

void verticalicontextBK::setTwoColor(QString color,QString bgColor){
    setStyleSheet("*{background-color:"+bgColor+";}#icon,#txt{color:"+color+";}");
}

void verticalicontextBK::btnPressedSlot(){
    emit btnPressed(id_);
}

void verticalicontextBK::btnClickedSlot(){
    emit btnClicked(id_);
}
