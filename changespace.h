#ifndef CHANGESPACE_H
#define CHANGESPACE_H

#include <QWidget>

namespace Ui {
class changeSpace;
}

class changeSpace : public QWidget
{
    Q_OBJECT

public:
    explicit changeSpace(QWidget *parent = nullptr);
    ~changeSpace();

private:
    Ui::changeSpace *ui;
};

#endif // CHANGESPACE_H
