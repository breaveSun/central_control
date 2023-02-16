#ifndef VERTICALTXTUNIT_H
#define VERTICALTXTUNIT_H

#include <QWidget>

namespace Ui {
class verticalTxtUnit;
}

class verticalTxtUnit : public QWidget
{
    Q_OBJECT

public:
    explicit verticalTxtUnit(QWidget *parent = nullptr);
    ~verticalTxtUnit();


    void setTitle(QString title);
    void setNum(QString num);
    void setUnit(QString unit);
    void setUnitVisiable(bool vis);
private:
    Ui::verticalTxtUnit *ui;
};

#endif // VERTICALTXTUNIT_H
