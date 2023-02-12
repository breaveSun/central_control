#ifndef LIGHTPAGE_H
#define LIGHTPAGE_H

#include <QWidget>

namespace Ui {
class lightPage;
}

class lightPage : public QWidget
{
    Q_OBJECT

public:
    explicit lightPage(QWidget *parent = nullptr);
    ~lightPage();

signals:
    void goback();
private:
    Ui::lightPage *ui;
};

#endif // LIGHTPAGE_H

