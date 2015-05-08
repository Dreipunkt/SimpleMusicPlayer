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

#include "myslider.h"

MySlider::MySlider(QWidget *parent) :
QSlider(parent)
{}

void MySlider::mousePressEvent ( QMouseEvent * event )
{
  QStyleOptionSlider opt;
  initStyleOption(&opt);
  QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

  if (event->button() == Qt::LeftButton &&
      sr.contains(event->pos()) == false)
  {
    int newVal;
    if (orientation() == Qt::Vertical)
       newVal = minimum() + ((maximum()-minimum()) * (height()-event->y())) / height();
    else
       newVal = minimum() + ((maximum()-minimum()) * event->x()) / width();

    double halfHandleWidth = (0.5 * sr.width()) + 0.5;
    int adaptedPosX = event->x();
    if ( adaptedPosX < halfHandleWidth )
            adaptedPosX = halfHandleWidth;
    if ( adaptedPosX > width() - halfHandleWidth )
            adaptedPosX = width() - halfHandleWidth;
    double newWidth = (width() - halfHandleWidth) - halfHandleWidth;
    double normalizedPosition = (adaptedPosX - halfHandleWidth)  / newWidth ;

    newVal = minimum() + ((maximum()-minimum()) * normalizedPosition);

    if (invertedAppearance() == true)
        setValue( maximum() - newVal );
    else
        setValue(newVal);

    event->accept();
  }
  QSlider::mousePressEvent(event);
}
