#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T15:07:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    result.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    game.h \
    result.h \
    board.h

FORMS    += mainwindow.ui \
    game.ui \
    result.ui

RESOURCES += \
    pics.qrc \
    pic.qrc
