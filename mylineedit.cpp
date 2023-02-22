#include "mylineedit.h"

myLineEdit::myLineEdit(QWidget *parent) : QLineEdit(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void myLineEdit::focusInEvent(QFocusEvent *event)
{

    emit focusIn();

}
void myLineEdit::focusOutEvent(QFocusEvent *event)
{
    emit focusOut();
}
