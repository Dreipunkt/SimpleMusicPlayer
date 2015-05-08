#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>
#include <QtWidgets>
#include <QDebug>

class MySlider : public QSlider
{
    Q_OBJECT

public:
    explicit MySlider(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // MYSLIDER_H
