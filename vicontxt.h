#ifndef VICONTXT_H
#define VICONTXT_H

#include <QWidget>
#include "common.h"

namespace Ui {
class vIconTxt;
}

class vIconTxt : public QWidget
{
    Q_OBJECT

public:
    explicit vIconTxt(QWidget *parent = nullptr);
    ~vIconTxt();
    void setId(QString id);
    void setTxt(QString txt);
    void setIcon(int icon);
    void setIconColor(QString color);
//    void setTxtColor(QString color);
//    void setBGColor(QString color);
    void setTwoColor(QString color,QString bgColor);

    void setWidth(int width=80);
    void setHeight(int height=80);


signals:
    void btnPressed(QString id);

private slots:
        void btnPressedSlot();

private:
    Ui::vIconTxt *ui;
    QLabel *pTxt_;
    QLabel *pIcon_;
    QString id_;
};

#endif // VICONTXT_H
