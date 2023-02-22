#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit myLineEdit(QWidget *parent = 0);
    void focusInEvent(QFocusEvent *event);//覆盖这两个函数
    void focusOutEvent(QFocusEvent *event);
signals:
   void focusIn();//获得焦点信号
   void focusOut();//失去焦点信号
public:
};

#endif // MYLINEEDIT_H
