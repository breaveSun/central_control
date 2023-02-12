#include "titleicon.h"
#include "ui_titleicon.h"
#include "common.h"
#include <qdebug.h>

titleIcon::titleIcon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::titleIcon)
{
    ui->setupUi(this);
}

titleIcon::~titleIcon()
{
    delete ui;
}

void titleIcon::setText(QString name){
    ui->titleName->setText(name);
}
void titleIcon::setIcon(QString icon){
    ui->titleIcone->setStyleSheet("font-family: iconfont");
    ui->titleIcone->setFont(Common::loadIcon(30));
    ui->titleIcone->setText(icon);
}