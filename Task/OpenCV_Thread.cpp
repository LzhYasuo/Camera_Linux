#include "OpenCV_Thread.h"
#include <QThread>
#include <iostream>
#include <QDateTime>
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

#include "../Filter/OpenCV_Filter.h"


std::string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method,int CamearIndex)
{
#if 1
    return "nvarguscamerasrc sensor-id=" + std::to_string(CamearIndex) + " ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
#endif

//    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
//           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
//           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
//           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

static cv::VideoCapture capCamera0;
static cv::VideoCapture capCamera1;
static cv::VideoCapture capCamera2;
static cv::VideoCapture capCamera3;

OpenCV_Thread::OpenCV_Thread()
{
	isClose = false;
    isCamera0 = false;
    filt.Add(CV_Task{TASKYOLO4});
}

OpenCV_Thread::~OpenCV_Thread()
{

}

void OpenCV_Thread::Sleep(int msec)
{
    qint64 dieTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    while( QDateTime::currentDateTime().toMSecsSinceEpoch()-dieTime < msec )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        QThread::msleep(1);
    }

}

bool OpenCV_Thread::DoSomething(int index)
{
    const std::string strPath = "/home/nako/QtPro/Yolo_Camear/test.mp4";
//    mux.lock();
    bool isOpen;
//    if(index == 0)
        isOpen = capCamera0.open(strPath);
//    else if(index == 1)
//        isOpen = capCamera1.open(strPath);
//    else if(index == 2)
//        isOpen = capCamera2.open(strPath);
//    else if(index == 3)
//        isOpen = capCamera3.open(strPath);
//    mux.unlock();
    if(!isOpen)
    {
        return false;
    }
    _fps = capCamera0.get(cv::CAP_PROP_FPS);
    return true;
}

//bool OpenCV_Thread::Open(QString path)
//{
//    const std::string strPath = path.toStdString();
//    qDebug() << path;
//    mux.lock();
//    bool isOpen = capCamera0.open(strPath);
//    qDebug() << isOpen;
//    mux.unlock();
//    if (!isOpen)
//    {
//        return false;
//    }
//    _fps = capCamera0.get(cv::CAP_PROP_FPS);
//    isCamera = true;
//    return true;
//}

//bool OpenCV_Thread::Open(int index)
//{
//    qDebug() << index;
//    CamearIndex = index;
//    std::string pipeline = gstreamer_pipeline(capture_width,
//    capture_height,
//    display_width,
//    display_height,
//    framerate,
//    flip_method,
//    CamearIndex);
//    std::cout << "Using pipeline: \n\t" << pipeline << "\n";

//    if(CamearIndex == 0)
//    {
//        mux.lock();
//        const bool isOpen = capCamera0.open(pipeline,cv::CAP_GSTREAMER);
//        mux.unlock();
//        if (!isOpen)
//        {
//            qDebug() << "false";
//            return false;
//        }
//        isCamera0 = true;
//        return true;
//    }
//    else if(CamearIndex == 1)
//    {
//        mux.lock();
//        const bool isOpen = capCamera1.open(pipeline,cv::CAP_GSTREAMER);
//        mux.unlock();
//        if (!isOpen)
//        {
//            qDebug() << "false";
//            return false;
//        }
//        isCamera1 = true;
//        return true;
//    }

//}

void OpenCV_Thread::Close()
{
//    mux.lock();
    filt.Clear();
//    if(capCamera0.isOpened())
//        capCamera0.release();
	isClose = true;
	this->quit();
	this->wait();
//    mux.unlock();;
}

#if 1
void OpenCV_Thread::run()
{
    while (1)
    {
        mux.lock();
        if (isClose)
        {
            mux.unlock();
            break;
        }
        if (capCamera0.isOpened())
        {
            cv::Mat matCamear;
            bool isRead = capCamera0.read(matCamear);
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CameraShow0(matCamear);
            }
        }
        if(capCamera1.isOpened())
        {
            cv::Mat matCamear;
            bool isRead = capCamera1.read((matCamear));
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CamearShow1(matCamear);
            }
        }
        if(capCamera2.isOpened())
        {
            cv::Mat matCamear;
            bool isRead = capCamera2.read((matCamear));
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CamearShow2(matCamear);
            }
        }
        if(capCamera3.isOpened())
        {
            cv::Mat matCamear;
            bool isRead = capCamera3.read((matCamear));
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CameraShow3(matCamear);
            }
        }
        Sleep(_fps);
        mux.unlock();
    }
}
#else
void OpenCV_Thread::run()
{
	while (1)
	{
		mux.lock();
		if (isClose)
		{
			mux.unlock();
			break;
		}
        if (isCamera0 && capCamera0.isOpened())
		{
			cv::Mat matCamear;
            bool isRead = capCamera0.read(matCamear);
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CameraShow0(matCamear);
            }
		}
        if(isCamera1 && capCamera1.isOpened())
        {
            cv::Mat matCamear;
            bool isRead = capCamera1.read((matCamear));
            if(isRead)
            {
                matCamear = filt.Filter(matCamear, cv::Mat());
                emit CameraShow1(matCamear);
            }
        }
		mux.unlock();
	}
}

#endif
