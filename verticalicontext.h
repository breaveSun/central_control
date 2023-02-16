#ifndef VERTICALICONTEXT_H
#define VERTICALICONTEXT_H

#include <QWidget>

namespace Ui {
class verticalIconText;
}

class verticalIconText : public QWidget
{
    Q_OBJECT

public:
    explicit verticalIconText(QWidget *parent = nullptr);
    ~verticalIconText();
    void setTxt(QString txt);
    void setIcon(int icon);
    void setIconColor(QString color);
signals:
        void btnPressed();
        void btnClicked();
        void btnReleased();
private slots:
        void btnPressedSlot();
        void btnClickedSlot();
        void btnReleasedSlot();
private:
    Ui::verticalIconText *ui;
};

#endif // VERTICALICONTEXT_H
