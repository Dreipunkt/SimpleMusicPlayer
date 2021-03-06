#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T17:10:35
#
#-------------------------------------------------

QT       += core gui multimedia
QT       += multimediawidgets

win32:RC_ICONS += icon.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleMusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myslider.cpp \
    history.cpp

HEADERS  += mainwindow.h \
    myslider.h \
    history.h

FORMS    += mainwindow.ui \
    history.ui
