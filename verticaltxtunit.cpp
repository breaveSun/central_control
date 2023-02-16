#include "verticaltxtunit.h"
#include "ui_verticaltxtunit.h"

verticalTxtUnit::verticalTxtUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verticalTxtUnit)
{
    ui->setupUi(this);
}

verticalTxtUnit::~verticalTxtUnit()
{
    delete ui;
}

void verticalTxtUnit::setTitle(QString title){
    ui->title->setText(title);
}

void verticalTxtUnit::setNum(QString num){
    ui->num->setText(num);
}

void verticalTxtUnit::setUnit(QString unit){
    ui->unit->setText(unit);
}

void verticalTxtUnit::setUnitVisiable(bool vis){
    ui->unit->setVisible(vis);
    ui->num->setAlignment(Qt::AlignHCenter);
}
