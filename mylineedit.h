#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class myLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit myLineEdit(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void focusInEvent(QFocusEvent *event);    //覆盖这两个函数
    void focusOutEvent(QFocusEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:
    void mouseReleased();
    void focusIn();
    void focusOut();

};

#endif // MYTEXTEDIT_H
