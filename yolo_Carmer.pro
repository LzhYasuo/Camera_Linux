#-------------------------------------------------
#
# Project created by QtCreator 2021-12-20T10:19:42
#
#-------------------------------------------------

#cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local/ -D CUDA_ARCH_BIN='3.5' -D WITH_CUDA=ON -D WITH_CUBLAS=ON -D WITH_TBB=ON -D WITH_V4L=ON -D WITH_QT=ON -D WITH_OPENGL=ON -D WITH_FFMPEG=ON -D OPENCV_EXTRA_MODULES_PATH=~/Opencv/opencv-4.4.0/opencv-4.4.0/opencv_contrib-4.4.0/modules -D OPENCV_GENERATE_PKGCONFIG=YES ..

QT       += core gui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv4 \
                /home/lzhyasuo/qtPro/yolo_Carmer/Inc

LIBS += /usr/local/lib/libopencv_* \
        /home/lzhyasuo/qtPro/yolo_Carmer/libdarknet.so

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yolo_Carmer
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
        main.cpp \
    Pub/Pub_Function.cpp \
    Filter/OpenCV_Action.cpp \
    Filter/OpenCV_Filter.cpp \
    Gui/GuiBaseWidget.cpp \
    Gui/GuiOpenGLWidget.cpp \
    Gui/MainWidget.cpp \
    Task/OpenCV_Thread.cpp
HEADERS += \
    Pub/Pub_Function.h \
    Filter/OpenCV_Action.h \
    Filter/OpenCV_Filter.h \
    Gui/GuiBaseWidget.h \
    Gui/GuiOpenGLWidget.h \
    Gui/MainWidget.h \
    Task/OpenCV_Thread.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
