#ifndef VERTICALICONTEXTBK_H
#define VERTICALICONTEXTBK_H

#include <QWidget>

namespace Ui {
class verticalicontextBK;
}
class verticalIconText;
class verticalicontextBK : public QWidget
{
    Q_OBJECT

public:
    explicit verticalicontextBK(QWidget *parent = nullptr);
    ~verticalicontextBK();

    void setTxt(QString txt);
    void setIcon(int icon);
    void setBKColor(QString color);
    void setColor(QString color);
signals:
        void btnPressed();
        void btnClicked();
private slots:
        void btnPressedSlot();
        void btnClickedSlot();
private:
    Ui::verticalicontextBK *ui;
    verticalIconText* widget;
};

#endif // VERTICALICONTEXTBK_H
