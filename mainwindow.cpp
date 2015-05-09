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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    path = "";
    paused = false;
    replay = false;
    posSliderPressed = false;

    player = new QMediaPlayer(this);
    h = new History(this);

    setMaximumSize(size());
    setMinimumSize(size());

    ui->statusBar-> // no idea what that does, but too scared to delete it...yet

    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);

    connect(player, &QMediaPlayer::mediaChanged, this, &MainWindow::on_mediaChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playBtn_clicked()
{
    if (!paused) {
        player->setMedia(QUrl::fromLocalFile(path));
        h->add(QUrl::fromLocalFile(path));
        player->play();
        paused = false;
    }
    else {
        player->play();
        paused = false;
    }
}

void MainWindow::on_pauseBtn_clicked()
{
    player->pause();
    paused = true;
}

void MainWindow::on_stopBtn_clicked()
{
    player->stop();
    paused = false;
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::dropEvent(QDropEvent *ev)
{
    path = "";
    QList<QUrl> urls = ev->mimeData()->urls();
    foreach(QUrl url, urls)
    {
        path += url.toString();
    }

    pathFixing();

    paused = false;
    on_playBtn_clicked();
    qDebug() << "DEBUG " << path;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *ev)
{
   ev->accept();
}

void MainWindow::on_durationChanged(qint64 duration) {
    int seconds = (duration/1000) % 60;
    int minutes = (duration/60000) % 60;
    int hours = (duration/3600000) % 24;
    QTime time(hours, minutes,seconds);
    ui->timeLabel->setText(time.toString());
    ui->posSlider->setMaximum(player->duration());
}

void MainWindow::on_positionChanged(qint64 pos) {
    int seconds = (pos/1000) % 60;
    int minutes = (pos/60000) % 60;
    int hours = (pos/3600000) % 24;
    QTime time(hours, minutes,seconds);
    ui->posLabel->setText(time.toString());

    if (!posSliderPressed)
        ui->posSlider->setValue(pos);

    qDebug() << "DEBUG " << abs(player->duration() - pos);

    if (abs(player->duration() - pos) < 1000 && replay && player->duration() != -1)
        repeat();
}

void MainWindow::on_mediaChanged(QMediaContent cont) {
    ui->statusBar->showMessage(cont.canonicalUrl().fileName());
    replay = ui->repeatCB->checkState();
}

void MainWindow::on_repeatCB_clicked()
{
    replay = ui->repeatCB->checkState();
}

void MainWindow::repeat() {
    paused = false;
    on_playBtn_clicked();
}

void MainWindow::on_posSlider_sliderReleased()
{
    posSliderPressed = false;
    player->setPosition(ui->posSlider->value());
}

void MainWindow::on_posSlider_sliderPressed()
{
    posSliderPressed = true;
}

void MainWindow::on_historyBtn_clicked()
{
    h->show();
}

void MainWindow::changeMedia(QUrl p) {
    path = p.toString();
    pathFixing();
    paused = false;
    on_playBtn_clicked();
    qDebug() << "DEBUG " << path;
}

void MainWindow::pathFixing() {
    path.replace("file://", "");
    path.replace("%5D", "]");
    path.replace("%5B", "[");
    path.replace("%5C", "\\");
    path.replace("%3F", "?");
    path.replace("%22", "\"");
    path.replace("%25", "%");
    path.replace("%60", "`");
    path.replace("%3C", "<");
    path.replace("%3E", ">");
    path.replace("%7B", "{");
    path.replace("%7D", "}");
    path.replace("%5E", "^");
    path.replace("%7C", "|");
    path.replace("%23", "#");
    path.replace("%3B", ";");
}
