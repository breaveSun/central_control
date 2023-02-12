#include "verticalicontext.h"
#include "ui_verticalicontext.h"
#include "common.h"

verticalIconText::verticalIconText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verticalIconText)
{
    ui->setupUi(this);

    connect(ui->txt, &QPushButton::toggled, this,&verticalIconText::btnToggleSlot);
    connect(ui->icon, &QPushButton::toggled, this,&verticalIconText::btnToggleSlot);

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

void verticalIconText::setIcon(QString icon){
    ui->icon->setStyleSheet("font-family: iconfont");
    ui->icon->setFont(Common::loadIcon(30));
    ui->icon->setText(icon);
}

void verticalIconText::setIconColor(QString color){
    setStyleSheet("#icon{color:"+color+"}");
}
void verticalIconText::btnToggleSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnToggle();
}
void verticalIconText::btnPressedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnPressed();
}
void verticalIconText::btnClickedSlot(){
//    qDebug()<<__FUNCTION__<<objectName();
    emit btnClicked();
}
