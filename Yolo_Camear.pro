#-------------------------------------------------
#
# Project created by QtCreator 2021-12-24T13:20:55
#
#-------------------------------------------------

QT       += core gui concurrent

INCLUDEPATH += /usr/include/opencv4 \
               /usr/include/yoloInc

LIBS += /usr/lib/aarch64-linux-gnu/libopencv_* \
        /usr/lib/yoloLib/libdarknet.so

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Yolo_Camear
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


SOURCES += \
        main.cpp \
    Gui/GuiBaseWidget.cpp \
    Gui/MainWidget.cpp \
    Gui/GuiOpenGLWidget.cpp \
    Pub/Pub_Function.cpp \
    Filter/OpenCV_Action.cpp \
    Filter/OpenCV_Filter.cpp \
    Task/Camera_ThreadID0.cpp \
    Task/Camera_ThreadID1.cpp \
    Task/Thread_Sync.cpp

HEADERS += \
    Gui/GuiBaseWidget.h \
    Gui/MainWidget.h \
    Gui/GuiOpenGLWidget.h \
    Pub/Pub_Function.h \
    Filter/OpenCV_Action.h \
    Filter/OpenCV_Filter.h \
    Task/Camera_ThreadID0.h \
    Task/Camera_ThreadID1.h \
    Task/Thread_Sync.h
