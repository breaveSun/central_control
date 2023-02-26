#ifndef FINGERBOARD_H
#define FINGERBOARD_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class fingerboard;
}

class fingerboard : public QWidget
{
    Q_OBJECT

public:
    explicit fingerboard(QWidget *parent = nullptr);
    ~fingerboard();
    void initFocusWidget(QWidget* widget);
private slots:
    void slotKeyButtonClicked();

private:
    void init();
private:
    Ui::fingerboard *ui;
    QWidget* m_focusWidget;
    QVector<QPushButton*> m_Keys;
};

#endif // FINGERBOARD_H
