#ifndef LISTBTN_H
#define LISTBTN_H

#include <QWidget>
#include "common.h"
namespace Ui {
class listBtn;
}
class titleIcon;
class listBtn : public QWidget
{
    Q_OBJECT

public:
    explicit listBtn(QWidget *parent = nullptr);
    ~listBtn();
    void setName(QString name);
    void setIcon(int icon);
signals:
    void btnClick();
private:
    Ui::listBtn *ui;
    QLabel *pGoPage_;
    titleIcon *pTitle_;

};

#endif // LISTBTN_H
