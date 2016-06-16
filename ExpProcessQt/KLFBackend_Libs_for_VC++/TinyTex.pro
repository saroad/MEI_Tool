#-------------------------------------------------
#
# Project created by QtCreator 2013-04-06T08:57:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
VERSION = 0.2

DEFINES += KLF_SRC_BUILD

TARGET = TinyTex
QTPLUGIN += QSQLMYSQL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    GeneratedFiles/ui_mainwindow.h

FORMS    += mainwindow.ui

# note that in unix(linux) systems library names are case sensitive
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-KLFBackend/ -lklfbackend
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-KLFBackend/ -lklfbackend
else:unix: LIBS += -L$$PWD/build-KLFBackend/ -lKLFBackend

INCLUDEPATH += $$PWD/klfbackend
INCLUDEPATH += "C:\Program Files\MySQL\MySQL Connector.C 6.1\include"
LIBS += "C:\Program Files\MySQL\MySQL Connector.C 6.1\lib\libmysql.lib"
