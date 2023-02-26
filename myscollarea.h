#ifndef MYSCOLLAREA_H
#define MYSCOLLAREA_H

#include <QObject>
#include <QScrollArea>
#include <QPoint>

class myScollArea: public QScrollArea
{
public:
    myScollArea(QWidget* parent = NULL);

protected:
    bool eventFilter(QObject *obj,QEvent *evt);

private:
    bool mMoveStart;
    bool mContinuousMove;
    QPoint mMousePoint;
};

#endif // MYSCOLLAREA_H
