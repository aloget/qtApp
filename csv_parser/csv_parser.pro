#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T03:15:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csv_parser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    history.cpp \
    convert.cpp

HEADERS  += mainwindow.h \
    history.h \
    convert.h

FORMS    += mainwindow.ui \
    history.ui \
    convert.ui
