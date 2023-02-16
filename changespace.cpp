#include "changespace.h"
#include "ui_changespace.h"

changeSpace::changeSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeSpace)
{
    ui->setupUi(this);
}

changeSpace::~changeSpace()
{
    delete ui;
}
