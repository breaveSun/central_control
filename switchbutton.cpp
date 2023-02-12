#pragma execution_character_set("utf-8")
#include "switchbutton.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

SwitchButton::SwitchButton(QWidget *parent) : QWidget(parent)
{
    m_ID=0;
    m_space = 2;
    m_radius = 4;
    m_checked = false;
    m_showText = true;
    m_showText = false;
    m_animation = true;

    //m_bgColorOn = QColor(97,81,233);    //紫蓝
    //m_bgColorOn = QColor(21,137,200);   //淡蓝
    m_bgColorOn = QColor(0, 204, 106);  //翠绿
    m_bgColorOff = QColor(111, 122, 126);

    m_sliderColorOn = QColor(255, 255, 255);
    m_sliderColorOff = QColor(255, 255, 255);

    m_textColor = QColor(255, 255, 255);

    m_textOn = "打开";
    m_textOff = "关闭";

    m_step = 0;
    m_startX = 0;
    m_endX = 0;

    m_timer = new QTimer(this);
    m_timer->setInterval(30);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

void SwitchButton::drawBackGround(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor bgColor = m_checked ? m_bgColorOn : m_bgColorOff;
//    if (isEnabled()) {
//        bgColor.setAlpha(60);
//    }

    painter->setBrush(bgColor);

    QRect rect(0, 0, width(), height());
    int side = qMin(width(), height());

    //左侧半圆 Left semicircle
    QPainterPath path1;
    path1.addEllipse(rect.x(), rect.y(), side, side);

    //右侧半圆 Right semicircle
    QPainterPath path2;
    path2.addEllipse(rect.width() - side, rect.y(), side, side);

    //中间的矩形 Middle rectangle
    QPainterPath path3;
    path3.addRect(rect.x() + side / 2, rect.y(), rect.width() - side, height());

    QPainterPath path = path1 + path2 + path3;
    painter->drawPath(path);

    QFont font;
    font.setPointSize(height()/2);
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);// 设置字符间距 Set character spacing. default 0
    painter->setFont(font);
//    QFontDatabase::addApplicationFont("DEMO_FONT.TTF"); use self font
//    painter->setFont(QFont("DEMO_FONT", 34));

    //slider R
    int sliderWidth = qMin(height(), width()) - m_space * 2 - 5;
    if (m_checked){
        QRect textRect(0, 0, width() - sliderWidth, height()*0.95);
        painter->setPen(QPen(m_textColor));
        painter->drawText(textRect, Qt::AlignCenter, m_textOn);
    } else {
        QRect textRect(sliderWidth, 0, width() - sliderWidth, height()*0.95);
        painter->setPen(QPen(m_textColor));
        painter->drawText(textRect, Qt::AlignCenter, m_textOff);
    }

    painter->restore();
}

void SwitchButton::drawSlider(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::NoPen);

    QColor color = m_checked ? m_sliderColorOn : m_sliderColorOff;

    painter->setBrush(QBrush(color));

    int sliderWidth = qMin(width(), height()) - m_space * 2;
    QRect rect(m_space + m_startX, m_space, sliderWidth, sliderWidth);
    painter->drawEllipse(rect);

    painter->restore();
}

void SwitchButton::paintEvent(QPaintEvent *ev)
{
    //启用反锯齿 Enable anti aliasing
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    drawBackGround(&painter);

    drawSlider(&painter);
}

void SwitchButton::resizeEvent(QResizeEvent *event)
{
    //qDebug("resizeEvent:%d  w:%d  h:%d  %d",m_ID,width(),height(),m_space);
    m_checked = !m_checked;
    mousePressEvent(NULL);
}

void SwitchButton::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)

    m_checked = !m_checked;
    emit statusChanged(m_ID,m_checked);

    //Calculate step long
    m_step = width() / 10;

    //Calculate the X-pos end point for slider
    if (m_checked) {
        m_endX = width() - height();
    } else {
        m_endX = 0;
    }
    //qDebug("%d step:%d  w:%d(%d)  h:%d(%d)  endX:%d",m_ID,m_step,width(),minimumWidth(),height(),minimumHeight(),m_endX);

    //use animation or not
    if (m_animation) {
        m_timer->start();
    } else{
        m_startX = m_endX;
        update();
    }
}
// 鼠标释放事件 - 切换开关状态、发射toggled()信号
void SwitchButton::mouseReleaseEvent(QMouseEvent *ev)
{
}

void SwitchButton::updateValue()
{
    if (m_checked) {
        if (m_startX < m_endX) {
            m_startX += m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    } else {
        if (m_startX > m_endX) {
            m_startX -= m_step;
        } else {
            m_startX = m_endX;
            m_timer->stop();
        }
    }

    update();
}

qint16 SwitchButton::getID()
{
    return m_ID;
}

int SwitchButton::space() const
{
    return m_space;
}

int SwitchButton::radius() const
{
    return m_radius;
}

bool SwitchButton::checked() const
{
    return m_checked;
}

bool SwitchButton::showText() const
{
    return m_showText;
}

bool SwitchButton::showCircel() const
{
    return m_showCircle;
}

bool SwitchButton::animation() const
{
    return m_animation;
}

QColor SwitchButton::bgColorOn() const
{
    return m_bgColorOn;
}

QColor SwitchButton::bgColorOff() const
{
    return m_bgColorOff;
}

QColor SwitchButton::sliderColorOn() const
{
    return m_sliderColorOn;
}

QColor SwitchButton::sliderColorOff() const
{
    return m_sliderColorOff;
}

QColor SwitchButton::textColor() const
{
    return m_textColor;
}

QString SwitchButton::textOn() const
{
    return m_textOn;
}

QString SwitchButton::textOff() const
{
    return m_textOff;
}

int SwitchButton::step() const
{
    return m_step;
}

int SwitchButton::startX() const
{
    return m_startX;
}

int SwitchButton::endX() const
{
    return m_endX;
}


void SwitchButton::setID(qint16 id)
{
    m_ID=id;
}

void SwitchButton::setSpace(int space)
{
    if (m_space != space) {
        m_space = space;
        update();
    }
}

void SwitchButton::setRadius(int radius)
{
    if (m_radius != radius) {
        m_radius = radius;
        update();
    }
}

void SwitchButton::setChecked(bool checked)
{
    if (m_checked != checked) {
        m_checked = !checked;
        //update();
        mousePressEvent(NULL);
    }
}

void SwitchButton::setShowText(bool show)
{
    if (m_showText != show) {
        m_showText = show;
        update();
    }
}

void SwitchButton::setShowCircle(bool show)
{
    if (m_showCircle != show) {
        m_showCircle = show;
        update();
    }
}

void SwitchButton::setAnimation(bool ok)
{
    if (m_animation != ok) {
        m_animation = ok;
        update();
    }
}

void SwitchButton::setBgColorOn(const QColor &color)
{
    if (m_bgColorOn != color) {
        m_bgColorOn = color;
        update();
    }
}

void SwitchButton::setBgColorOff(const QColor &color)
{
    if (m_bgColorOff != color) {
        m_bgColorOff = color;
        update();
    }
}

void SwitchButton::setSliderColorOn(const QColor &color)
{
    if (m_sliderColorOn != color) {
        m_sliderColorOn = color;
        update();
    }
}

void SwitchButton::setSliderColorOff(const QColor &color)
{
    if (m_sliderColorOff != color) {
        m_sliderColorOff = color;
        update();
    }
}

void SwitchButton::setTextColor(const QColor &color)
{
    if (m_textColor != color) {
        m_textColor = color;
        update();
    }
}

void SwitchButton::setTextOn(const QString &text)
{
    if (m_textOn != text) {
        m_textOn = text;
        update();
    }
}

void SwitchButton::setTextOff(const QString &text)
{
    if (m_textOff != text) {
        m_textOff = text;
        update();
    }
}
