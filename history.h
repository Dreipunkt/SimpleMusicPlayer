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

#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QUrl>
#include <QMainWindow>

class MainWindow;

namespace Ui {
class History;
}

class History : public QDialog
{
    Q_OBJECT

public:
    explicit History(MainWindow *mW, QWidget *parent = 0);
    ~History();
    void add(QUrl path);

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::History *ui;
    MainWindow *mW;
    QUrl* list;
    unsigned int counter;
};

#endif // HISTORY_H
