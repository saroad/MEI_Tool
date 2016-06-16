# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = ExpProcessQt
DESTDIR = ../Win32/Debug
QT += core gui sql
CONFIG += debug
DEFINES += QT_DLL QT_SQL_LIB
DEFINES += KLF_SRC_BUILD
INCLUDEPATH += ../../../../../../../../../../Program Files/MySQL/MySQL Connector.C 6.1/include \
    ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
LIBS += -L"../../../../../../../../../../Program Files/MySQL/MySQL Connector.C 6.1/lib" \
    -llibmysql
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ExpProcessQt.pri)

# note that in unix(linux) systems library names are case sensitive
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-KLFBackend/ -lklfbackend
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-KLFBackend/ -lklfbackend
else:unix: LIBS += -L$$PWD/build-KLFBackend/ -lKLFBackend

INCLUDEPATH += $$PWD/klfbackend