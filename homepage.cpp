#include "homepage.h"
#include "ui_homepage.h"

homePage::homePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homePage)
{
    ui->setupUi(this);
    connect(ui->lightCntlr,&QPushButton::clicked,this,&homePage::goLightSlot);
}

homePage::~homePage()
{
    delete ui;
}

void homePage::goLightSlot(){
    emit goLightSignal(PB_GO_LIGHT_PAGE);
}
