#ifndef LABELBTN_H
#define LABELBTN_H

#include <QWidget>

namespace Ui {
class labelBtn;
}

class labelBtn : public QWidget
{
    Q_OBJECT

public:
    explicit labelBtn(QWidget *parent = nullptr);
    ~labelBtn();

    void setName(QString name);

    void setId(int id);

    int id();

    void setColor(QString color);

    void setBKColor(QString color);

    void setStyleSheet(QString style);

signals:
    void btnClicked(int id);

private slots:
    void btnClickedSlot(bool clicked);

private:
    Ui::labelBtn *ui;
    int id_;
};

#endif // LABELBTN_H
