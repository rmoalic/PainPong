#-------------------------------------------------
#
# Project created by QtCreator 2018-10-25T19:03:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PainPong
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 debug_and_release

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gamewidget.cpp \
    brique.cpp \
    coloredbrique.cpp \
    player.cpp \
    ball.cpp \
    text.cpp \
    gamelogic.cpp \
    scoreboard.cpp \
    gamemodel.cpp \
    powerup.cpp \
    scoreboardwidget.cpp \
    imageexception.cpp \
    imageloader.cpp

HEADERS += \
        mainwindow.h \
    gamewidget.h \
    brique.h \
    coloredbrique.h \
    player.h \
    ball.h \
    text.h \
    idrawable.h \
    idrawabletemp.h \
    gamelogic.h \
    scoreboard.h \
    constantes.h \
    gamemodel.h \
    powerup.h \
    scoreboardwidget.h \
    imageexception.h \
    imageloader.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressourses.qrc

dox.target = doc
dox.commands = doxygen Doxyfile; \
    cp screen.png html/
dox.depends =

QMAKE_EXTRA_UNIX_TARGETS += dox
