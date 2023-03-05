#include "pagehead.h"
#include "ui_pagehead.h"

pageHead::pageHead(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageHead)
{
    ui->setupUi(this);
    pTitleHLayout = new QHBoxLayout(ui->pageTitle);
    pTitleHLayout->setMargin(0);
    //添加返回按钮
    pBackBtn_ = new QPushButton;
    pBackBtn_->setObjectName("backBtn");
    pBackBtn_->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    //给返回按钮设置图标
    Common::setButtonIcon(pBackBtn_,icon::getIcon("return"),20);
    connect(pBackBtn_,SIGNAL(pressed()),this,SIGNAL(backClick()));


    //添加列表按钮
    pListBtn_ = new QPushButton;
    pListBtn_->setObjectName("listBtn");
    pListBtn_->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    connect(pListBtn_,SIGNAL(pressed()),this,SIGNAL(listClick()));


    pTitleHLayout->addWidget(pBackBtn_);
    pTitleHLayout->addItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Fixed));
    pTitleHLayout->addWidget(pListBtn_);
    pBackBtn_->hide();
    pListBtn_->hide();

}
void pageHead::setTitle(QString name){
    ui->pageTitle->setText(name);
}

void pageHead::addBackBtn(){
    pBackBtn_->show();

}

void pageHead::addListBtn(QString txt){
    pListBtn_->setText(txt);
    pListBtn_->show();
}
pageHead::~pageHead()
{
    delete ui;
}
