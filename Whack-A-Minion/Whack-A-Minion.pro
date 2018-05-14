#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T20:56:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Whack-A-Minion
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    instruction.cpp \
    score.cpp

HEADERS  += \
    game.h \
    instruction.h \
    mainwindow.h \
    score.h

FORMS    += mainwindow.ui \
    instructions.ui \
    game.ui \
    instruction.ui \
    score.ui \
    game_over.ui

RESOURCES += \
    mainminion.qrc \
    instructionminion.qrc \
    heart.qrc \
    jumpingminion.qrc \
    bye.qrc
