#include "mainpage.h"
#include "ui_mainpage.h"

mainPage::mainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainPage)
{
    ui->setupUi(this);
    connect(ui->lightCntlr,&QPushButton::clicked,this,&mainPage::goLightSlot);
    connect(ui->curtainCntlr,&QPushButton::clicked,this,&mainPage::goCurtainSlot);
    connect(ui->lightCntlr2,&QPushButton::clicked,this,&mainPage::goLightSlot2);
    connect(ui->curtainCntlr2,&QPushButton::clicked,this,&mainPage::goCurtainSlot2);
}

mainPage::~mainPage()
{
    delete ui;
}

void mainPage::goLightSlot(){
    emit goLightSignal(PB_GO_LIGHT_PAGE,1);
}
void mainPage::goCurtainSlot(){
    emit goCurtainSignal(PB_GO_CURTAIN_PAGE,1);
}

void mainPage::goLightSlot2(){
    emit goLightSignal(PB_GO_LIGHT_PAGE,2);
}
void mainPage::goCurtainSlot2(){
    emit goCurtainSignal(PB_GO_CURTAIN_PAGE,2);
}

