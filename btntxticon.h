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
    bool isChecked();
    void setChecked(bool checked);
signals:
        void btnPressed();
        void btnReleased();
        void btnClicked(bool clicked);
private slots:
        void btnClickedSlot(bool clicked);

private:
    Ui::btnTxtIcon *ui;
    bool isChecked_;
};

#endif // BTNTXTICON_H
