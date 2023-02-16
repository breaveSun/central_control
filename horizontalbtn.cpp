#include "horizontalbtn.h"
#include "ui_horizontalbtn.h"
#include "common.h"
#include "icon.h"

horizontalBtn::horizontalBtn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::horizontalBtn)
{
    ui->setupUi(this);
    connect(ui->horTxt, SIGNAL(pressed()), SLOT(btnPressedSlot()));
    connect(ui->horIcon, SIGNAL(pressed()), SLOT(btnPressedSlot()));
    connect(ui->horTxt, SIGNAL(clicked()), SLOT(btnClickedSlot()));
    connect(ui->horIcon, SIGNAL(clicked()), SLOT(btnClickedSlot()));
}

horizontalBtn::~horizontalBtn()
{
    delete ui;
}

void horizontalBtn::setTxt(QString txt){
    ui->horTxt->setText(txt);
}

void horizontalBtn::setIcon(QString icon){
    Common::setButtonIcon(ui->horIcon,icon::getIcon(icon),12);
}

void horizontalBtn::setBkColor(QString color){
    setStyleSheet("background-color:"+color+";");
}
void horizontalBtn::btnPressedSlot(){
    emit btnPressed();
}
void horizontalBtn::btnClickedSlot(){
    emit btnClicked();
}
