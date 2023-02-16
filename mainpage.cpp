#include "mainpage.h"
#include "ui_mainpage.h"

mainPage::mainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainPage)
{
    setAttribute(Qt::WA_TranslucentBackground,true); //设置背景透明
    ui->setupUi(this);
    connect(ui->ctrlList,&QPushButton::clicked,this,&mainPage::goCtrlListSlot);
    connect(ui->homepage,&QPushButton::clicked,this,&mainPage::goHomeSlot);
}

mainPage::~mainPage()
{
    delete ui;
}

void mainPage::goCtrlListSlot(){
    emit goCtrlListSignal(PB_GO_CTRLLIST_PAGR,1,1,1);
}

void mainPage::goHomeSlot(){
    emit goHomeSignal(PB_GO_HOME,1,1,1);
}
