#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T20:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab02
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paintoutput.cpp \
    SGen.cpp \
    signalmixer.cpp \
    signalgenerator.cpp \
    rclowpassfilter.cpp

HEADERS  += mainwindow.h \
    signalgenerator.h \
    paintoutput.h \
    SGen.h \
    signalmixer.h \
    rclowpassfilter.h
