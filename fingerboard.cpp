#include "fingerboard.h"
#include "ui_fingerboard.h"

#include <qdebug.h>
#include <QKeyEvent>

fingerboard::fingerboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fingerboard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint /*| Qt::Tool */| Qt::WindowDoesNotAcceptFocus);

    this->setWindowModality(Qt::WindowModal);
    this->setAttribute(Qt::WA_DeleteOnClose);

//    MoveWidget* moveWidget = new MoveWidget();
//    moveWidget->setWidget(this);

    init();
}

fingerboard::~fingerboard()
{
    delete ui;
}
void fingerboard::initFocusWidget(QWidget* widget){
    m_focusWidget = widget;
}

void fingerboard::init(){
    QList<QPushButton*> pbtns = this->findChildren<QPushButton*>();
    foreach(QPushButton * pbtn, pbtns) {
        pbtn->setAutoRepeat(true);    //允许自动重复
        pbtn->setAutoRepeatDelay(500);//设置重复操作的时延
        connect(pbtn, &QPushButton::clicked, this, &fingerboard::slotKeyButtonClicked);
        m_Keys.push_back(pbtn);
    }
}

void fingerboard::slotKeyButtonClicked(){
    QPushButton* pbtn = (QPushButton*)sender();
    if (pbtn->text() >= 'A' && pbtn->text() <= 'Z') {
        QKeyEvent keyPress(QEvent::KeyPress, int(pbtn->text().at(0).toLatin1()), Qt::NoModifier, pbtn->text());
        QKeyEvent keyRelease(QEvent::KeyRelease, int(pbtn->text().at(0).toLatin1()), Qt::NoModifier, pbtn->text());
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyPress);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyRelease);
    } else if(pbtn->text() >= '0' && pbtn->text() <= '9'){
        QKeyEvent keyPress(QEvent::KeyPress, pbtn->text().toInt() + 48, Qt::NoModifier, pbtn->text());
        QKeyEvent keyRelease(QEvent::KeyRelease, pbtn->text().toInt() + 48, Qt::NoModifier, pbtn->text());
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyPress);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyRelease);
    } else if(pbtn->objectName().contains("btnDel")){
        //删除
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyPress);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyRelease);
    } else if(pbtn->objectName().contains("btnDefine")){
        //确认
        QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Save, Qt::NoModifier);
        QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Save, Qt::NoModifier);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyPress);
        QApplication::sendEvent(m_focusWidget->focusWidget(), &keyRelease);
    }
}
