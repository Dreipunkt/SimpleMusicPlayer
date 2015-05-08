/**
SimpleMusicPlayer

Copyright 2015 by Christian Rauch <crauc3@gmail.com>


This file is part of SimpleMusicPlayer.

SimpleMusicPlayer is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SimpleMusicPlayer is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SimpleMusicPlayer. If not, see <http://www.gnu.org/licenses/>.
*/

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
