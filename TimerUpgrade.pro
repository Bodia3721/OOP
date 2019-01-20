#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T17:56:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimerUpgrade
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

CONFIG += c++11

SOURCES += \
        Sources\main.cpp \
        Sources\mainwindow.cpp \
    Sources\alarm_diag.cpp \
    Sources\alarm.cpp \
    Sources\timer.cpp \
    Sources\timer_diag.cpp

HEADERS += \
        Headers\mainwindow.h \
    Headers\alarm_diag.h \
    Headers\alarm.h \
    Headers\timer.h \
    Headers\timer_diag.h

FORMS += \
        Forms\mainwindow.ui \
    Forms\alarm_diag.ui \
    Forms\alarm.ui \
    Forms\timer.ui \
    Forms\timer_diag.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += multimedia
