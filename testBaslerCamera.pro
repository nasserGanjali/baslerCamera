#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T20:33:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testBaslerCamera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basler.cpp
INCLUDEPATH += /opt/pylon5/include
LIBS += -L/opt/pylon5/lib -Wl,-E -lpylonbase -lpylonutility -lGenApi_gcc_v3_0_Basler_pylon_v5_0 -lGCBase_gcc_v3_0_Basler_pylon_v5_0 -Wl,--enable-new-dtags -Wl,-rpath,/opt/pylon5/lib

HEADERS  += mainwindow.h \
    basler.h

FORMS    += mainwindow.ui
