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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDropEvent>
#include <QUrl>
#include <QDebug>
#include <QtWidgets>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_playBtn_clicked();

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

    void on_volumeSlider_valueChanged(int);

    void on_durationChanged(qint64);

    void on_positionChanged(qint64);

    void on_mediaChanged(QMediaContent);

    void on_repeatCB_clicked();

    void repeat();

    void on_posSlider_sliderReleased();

    void on_posSlider_sliderPressed();

protected:
    void dropEvent(QDropEvent *ev);
    void dragEnterEvent(QDragEnterEvent *ev);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    bool paused;
    QString path;
    bool replay;
    bool posSliderPressed;
};

#endif // MAINWINDOW_H
