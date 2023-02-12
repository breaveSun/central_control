#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QWidget>
#include <QTimer>
#include <QColor>

class SwitchButton : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchButton(QWidget *parent = 0);
    ~SwitchButton(){}

signals:
    void statusChanged(qint16 id,bool checked);


private slots:
    void updateValue();

private:
    void drawBackGround(QPainter *painter);
    void drawSlider(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void resizeEvent(QResizeEvent *event);

private:
    qint16  m_ID;
    int     m_space;             //distance between slider and boundary
    int     m_radius;            //fillet angle

    bool    m_checked;           //switch on/off
    bool    m_showText;          //display text or not
    bool    m_showCircle;        //display circle or not
    bool    m_animation;         //use animation or not

    QColor  m_bgColorOn;         //background color when switch on
    QColor  m_bgColorOff;        //background color when switch off
    QColor  m_sliderColorOn;     //slider color when switch on
    QColor  m_sliderColorOff;    //slider color when switch off
    QColor  m_textColor;         //text color

    QString m_textOn;           //text when switch on
    QString m_textOff;          //text when switch off

    QTimer  *m_timer;           //animation timer
    int     m_step;             //animation step x pixel
    int     m_startX;           //slider start X pos
    int     m_endX;             //slider end X pos

public:
    qint16  getID();
    int     space()             const;
    int     radius()            const;
    bool    checked()           const;
    bool    showText()          const;
    bool    showCircel()        const;
    bool    animation()         const;

    QColor  bgColorOn()         const;
    QColor  bgColorOff()        const;
    QColor  sliderColorOn()     const;
    QColor  sliderColorOff()    const;
    QColor  textColor()         const;

    QString textOn()            const;
    QString textOff()           const;

    int step()                  const;
    int startX()                const;
    int endX()                  const;


public Q_SLOTS:
    void setID(qint16 id);
    void setSpace(int space);
    void setRadius(int radius);
    void setChecked(bool checked);
    void setShowText(bool show);
    void setShowCircle(bool show);
    void setAnimation(bool ok);

    void setBgColorOn(const QColor &color);
    void setBgColorOff(const QColor &color);
    void setSliderColorOn(const QColor &color);
    void setSliderColorOff(const QColor &color);
    void setTextColor(const QColor &color);

    void setTextOn(const QString &text);
    void setTextOff(const QString &text);


};



#endif
