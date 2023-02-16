#include "verticalicontextbk.h"
#include "ui_verticalicontextbk.h"
#include "verticalicontext.h"

verticalicontextBK::verticalicontextBK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verticalicontextBK)
{
    ui->setupUi(this);
    widget = new verticalIconText(this);
    ui->frame->layout()->addWidget(widget);
    connect(widget, SIGNAL(btnPressed()),this, SLOT(btnPressedSlot()));
    connect(widget, SIGNAL(btnClicked()),this, SLOT(btnClickedSlot()));
}

verticalicontextBK::~verticalicontextBK()
{
    delete ui;
}

void verticalicontextBK::setTxt(QString txt){
    widget->setTxt(txt);
}

void verticalicontextBK::setIcon(int icon){
    widget->setIcon(icon);
}

void verticalicontextBK::setBKColor(QString color){
    ui->frame->setStyleSheet("background-color:"+color+";");
}

void verticalicontextBK::setColor(QString color){
    ui->frame->setStyleSheet("color:"+color+";");
}

void verticalicontextBK::btnPressedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnPressed();
}

void verticalicontextBK::btnClickedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnClicked();
}
