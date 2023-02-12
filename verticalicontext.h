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
    void setIcon(QString icon);
    void setIconColor(QString color);
signals:
        void btnToggle();
        void btnPressed();
        void btnClicked();
private slots:
        void btnToggleSlot();
        void btnPressedSlot();
        void btnClickedSlot();
private:
    Ui::verticalIconText *ui;
};

#endif // VERTICALICONTEXT_H
