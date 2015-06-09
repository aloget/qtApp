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
    parsersession.cpp \
    configuration.cpp \
    parser.cpp \
    csvobject.cpp \
    htmlobject.cpp \
    source.cpp \
    dbhelper.cpp

HEADERS  += mainwindow.h \
    parsersession.h \
    configuration.h \
    parser.h \
    csvobject.h \
    htmlobject.h \
    source.h \
    dbhelper.h

FORMS    += mainwindow.ui
