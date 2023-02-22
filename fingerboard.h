#ifndef FINGERBOARD_H
#define FINGERBOARD_H

#include <QWidget>

namespace Ui {
class fingerboard;
}

class fingerboard : public QWidget
{
    Q_OBJECT

public:
    explicit fingerboard(QWidget *parent = nullptr);
    ~fingerboard();

private:
    Ui::fingerboard *ui;
};

#endif // FINGERBOARD_H
