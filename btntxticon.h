#ifndef BTNTXTICON_H
#define BTNTXTICON_H

#include <QWidget>

namespace Ui {
class btnTxtIcon;
}

class btnTxtIcon : public QWidget
{
    Q_OBJECT

public:
    explicit btnTxtIcon(QWidget *parent = nullptr);
    ~btnTxtIcon();
    void setTxt(QString txt);
    void setIcon(QString icon,int size = 10);
signals:
        void btnPressed();
        void btnReleased();
        void btnClicked(bool clicked);
private slots:

private:
    Ui::btnTxtIcon *ui;
};

#endif // BTNTXTICON_H
