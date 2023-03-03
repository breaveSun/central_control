#include "listbtn.h"
#include "ui_listbtn.h"
#include <QHBoxLayout>
#include <QSpacerItem>
#include "titleicon.h"

listBtn::listBtn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listBtn)
{
    ui->setupUi(this);
    ui->listBtnItem->setFixedHeight(70);
    pGoPage_ = new QLabel;
    pGoPage_->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    Common::setLabelIcon(pGoPage_,icon::getIcon("more"),20);

    pTitle_ = new titleIcon;
    pTitle_->setObjectName("listItem");
    pTitle_->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    QHBoxLayout* pLayoutInfoComing_ = new QHBoxLayout(ui->listBtnItem);
    pLayoutInfoComing_->setMargin(0);
    pLayoutInfoComing_->addWidget(pTitle_);
    pLayoutInfoComing_->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Fixed));
    pLayoutInfoComing_->addWidget(pGoPage_);

    connect(ui->listBtnItem, SIGNAL(pressed()), this, SIGNAL(btnClick()));

}

void listBtn::setName(QString name){
    pTitle_->setText(name);
}

void listBtn::setIcon(int icon){
    pTitle_->setIcon(icon);
}

listBtn::~listBtn()
{
    delete ui;
}
