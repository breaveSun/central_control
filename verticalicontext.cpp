#include "verticalicontext.h"
#include "ui_verticalicontext.h"
#include "common.h"

verticalIconText::verticalIconText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verticalIconText)
{
    ui->setupUi(this);
    connect(ui->txt, SIGNAL(released()), SLOT(btnReleasedSlot()));
    connect(ui->icon, SIGNAL(released()), SLOT(btnReleasedSlot()));
    connect(ui->txt, SIGNAL(pressed()), SLOT(btnPressedSlot()));
    connect(ui->icon, SIGNAL(pressed()), SLOT(btnPressedSlot()));
    connect(ui->txt, SIGNAL(clicked()), SLOT(btnClickedSlot()));
    connect(ui->icon, SIGNAL(clicked()), SLOT(btnClickedSlot()));
}

verticalIconText::~verticalIconText()
{
    delete ui;
}

void verticalIconText::setTxt(QString txt){
    ui->txt->setText(txt);
}

void verticalIconText::setIcon(int icon){
    Common::setButtonIcon(ui->icon,icon);
}

void verticalIconText::setIconColor(QString color){
    setStyleSheet("#icon{color:"+color+"}");
}
void verticalIconText::btnPressedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnPressed();
}
void verticalIconText::btnClickedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnClicked();
}
void verticalIconText::btnReleasedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnReleased();
}

