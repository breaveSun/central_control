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

    void setId(QString id);
    void setTxt(QString txt);
    void setIcon(int icon);
    void setBKColor(QString color);
    void setColor(QString color);
    void setTwoColor(QString color,QString bgColor);
signals:
        void btnPressed(QString id);
        void btnClicked(QString id);
private slots:
        void btnPressedSlot();
        void btnClickedSlot();
private:
    Ui::verticalicontextBK *ui;
    verticalIconText* widget;
    QString id_;
};

#endif // VERTICALICONTEXTBK_H
