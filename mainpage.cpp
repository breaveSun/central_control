#include "mainpage.h"
#include "ui_mainpage.h"

mainPage::mainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainPage)
{
    ui->setupUi(this);
    connect(ui->lightCntlr,&QPushButton::clicked,this,&mainPage::goLightSlot);
    connect(ui->curtainCntlr,&QPushButton::clicked,this,&mainPage::goCurtainSlot);
}

mainPage::~mainPage()
{
    delete ui;
}

void mainPage::goLightSlot(){
    emit goLightSignal(PB_GO_LIGHT_PAGE);
}
void mainPage::goCurtainSlot(){
    emit goCurtainSignal(PB_GO_CURTAIN_PAGE);
}

