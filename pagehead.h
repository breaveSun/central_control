#ifndef PAGEHEAD_H
#define PAGEHEAD_H

#include <QWidget>

#include "common.h"
namespace Ui {
class pageHead;
}
class QHBoxLayout;
class pageHead : public QWidget
{
    Q_OBJECT

public:
    explicit pageHead(QWidget *parent = nullptr);
    ~pageHead();
    void setTitle(QString name);

    void addBackBtn();
    void addListBtn(QString txt);
signals:
    void backClick();
    void listClick();

private:
    Ui::pageHead *ui;
    QHBoxLayout* pTitleHLayout;
    QPushButton *pBackBtn_;
    QPushButton *pListBtn_;
};

#endif // PAGEHEAD_H
