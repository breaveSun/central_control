#ifndef TITLEICON_H
#define TITLEICON_H

#include <QWidget>

namespace Ui {
class titleIcon;
}

class titleIcon : public QWidget
{
    Q_OBJECT

public:
    explicit titleIcon(QWidget *parent = nullptr);
    ~titleIcon();
    void setText(QString name);
    void setIcon(int icon);

private:
    Ui::titleIcon *ui;
};

#endif // TITLEICON_H
