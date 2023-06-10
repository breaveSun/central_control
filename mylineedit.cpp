#include "mylineedit.h"
#include <qdebug.h>
#include <QKeyEvent>
#include <QGuiApplication>
myLineEdit::myLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void myLineEdit::mousePressEvent(QMouseEvent *event){
    qDebug()<<__FUNCTION__;
    QLineEdit::mousePressEvent(event);
}
void myLineEdit::mouseMoveEvent(QMouseEvent *event){
//    qDebug()<<__FUNCTION__;
    QLineEdit::mouseMoveEvent(event);

}
void myLineEdit::mouseReleaseEvent(QMouseEvent *event){
    qDebug()<<__FUNCTION__<<this->cursorPosition();
    QLineEdit::mouseReleaseEvent(event);

    emit mouseReleased();
}
void myLineEdit::mouseDoubleClickEvent(QMouseEvent *event){
    qDebug()<<__FUNCTION__;
    QLineEdit::mouseDoubleClickEvent(event);

}

void myLineEdit::focusInEvent(QFocusEvent *event)
{

    qDebug()<<__FUNCTION__;
    QLineEdit::focusInEvent(event);
    emit focusIn();

}
void myLineEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
    emit focusOut();
}

void myLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"cursorPosition"<<this->cursorPosition();
    qDebug()<<__FUNCTION__<<event->key()<<":"<<event->text();
    QLineEdit::keyPressEvent(event);
}
