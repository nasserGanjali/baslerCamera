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
    basler.cpp \
    mycanny.cpp
INCLUDEPATH += /opt/pylon5/include
LIBS += -L/opt/pylon5/lib -Wl,-E -lpylonbase -lpylonutility -lGenApi_gcc_v3_0_Basler_pylon_v5_0 -lGCBase_gcc_v3_0_Basler_pylon_v5_0 -Wl,--enable-new-dtags -Wl,-rpath,/opt/pylon5/lib
INCLUDEPATH += -I/usr/include/opencv
LIBS += -LC:/usr/lib/arm-linux-gnueabihf -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab

HEADERS  += mainwindow.h \
    basler.h \
    mycanny.h

FORMS    += mainwindow.ui
