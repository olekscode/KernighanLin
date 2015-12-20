#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T16:11:46
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KernighanLin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vertex.cpp \
    graph.cpp \
    kernighanlin.cpp \
    graphgenerator.cpp \
    graphcontroller.cpp \
    analyzer.cpp \
    systemmonitor.cpp \
    graphdrawer.cpp \
    algorythm.cpp

HEADERS  += mainwindow.h \
    vertex.h \
    graph.h \
    kernighanlin.h \
    graphgenerator.h \
    graphcontroller.h \
    analyzer.h \
    systemmonitor.h \
    graphdrawer.h \
    algorythm.h \
    exception.h

FORMS    += mainwindow.ui
