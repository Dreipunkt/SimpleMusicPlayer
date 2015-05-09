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

#include "history.h"
#include "ui_history.h"
#include "mainwindow.h"

History::History(MainWindow *mW, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::History)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    list = new QUrl[100];
    counter = 0;
    this->mW = mW;
}

History::~History()
{
    this->hide();
}

void History::add(QUrl path) {
    if (counter == 100)
        counter = 0;
    bool save = true;
    for (int i = 0; i < 100 && save; i++)
        save = !(list[i] == path);
    if (save) {
        ui->listWidget->addItem(path.fileName());
        list[counter] = path;
        counter++;
    }
}

void History::on_listWidget_doubleClicked(const QModelIndex &index)
{
    mW->changeMedia(list[index.row()]);
    qDebug() << index.row() << " " << list[index.row()];
}
