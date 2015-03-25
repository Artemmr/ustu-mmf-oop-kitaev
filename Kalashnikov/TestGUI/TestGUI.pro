#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T07:51:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestGUI
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    PaintOutput.cpp \
    SampleGenerator.cpp \
    signalmixer.cpp

HEADERS  += MainWindow.h \
    PaintOutput.h \
    signalgenerator.h \
    SampleGenerator.h \
    signalmixer.h

FORMS    +=
