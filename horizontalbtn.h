#ifndef HORIZONTALBTN_H
#define HORIZONTALBTN_H

#include <QWidget>

namespace Ui {
class horizontalBtn;
}

class horizontalBtn : public QWidget
{
    Q_OBJECT

public:
    explicit horizontalBtn(QWidget *parent = nullptr);
    ~horizontalBtn();
    void setTxt(QString txt);
    void setIcon(QString icon);
    void setBkColor(QString color);

signals:
        void btnPressed();
        void btnClicked();
private slots:
        void btnPressedSlot();
        void btnClickedSlot();
private:
    Ui::horizontalBtn *ui;
};

#endif // HORIZONTALBTN_H
