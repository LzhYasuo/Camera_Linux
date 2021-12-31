#include "Thread_Sync.h"

#include <QDebug>

#include <QDateTime>
#include <QCoreApplication>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>


#include "../Filter/OpenCV_Filter.h"


void Thread_Sync::Sleep(int msec)
{
    qint64 dieTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    while( QDateTime::currentDateTime().toMSecsSinceEpoch()-dieTime < msec )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        QThread::msleep(1);
    }

}

Thread_Sync::Thread_Sync()
{
    QThread* camThread0 = new QThread();
    QThread* camThread1 = new QThread();
    _camObj0 = new Camera_ThreadID0();
    _camObj1 = new Camera_ThreadID1();

    _camObj0->moveToThread(camThread0);
    _camObj1->moveToThread(camThread1);

    this->connect(this,&Thread_Sync::CloseAll,_camObj0,&Camera_ThreadID0::Close);
    this->connect(_camObj0,&Camera_ThreadID0::finish,camThread0,&QThread::quit);
    this->connect(camThread0,&QThread::finished,camThread0,&QThread::deleteLater);
    this->connect(camThread0,&QThread::finished,_camObj0,&Camera_ThreadID0::deleteLater);

    this->connect(this,&Thread_Sync::CloseAll,_camObj1,&Camera_ThreadID1::Close);
    this->connect(_camObj1,&Camera_ThreadID1::finish,camThread1,&QThread::quit);
    this->connect(camThread1,&QThread::finished,camThread1,&QThread::deleteLater);
    this->connect(camThread1,&QThread::finished,_camObj1,&Camera_ThreadID1::deleteLater);

    this->connect(camThread0,&QThread::started,_camObj0,&Camera_ThreadID0::Open);
    this->connect(camThread1,&QThread::started,_camObj1,&Camera_ThreadID1::Open);

    this->connect(_camObj0,&Camera_ThreadID0::SendMat,this,&Thread_Sync::SendMat1);

    camThread0->start();
    camThread1->start();
}

Thread_Sync::~Thread_Sync()
{

}

void Thread_Sync::Close()
{
    isClose = true;
    emit CloseAll();
}

void Thread_Sync::run()
{
    while(1)
    {
        _mux.lock();
        if(isClose)
        {
            _mux.unlock();
            break;
        }
        cv::Mat mat;
        cv::Mat mat1;
        bool isRead = _camObj0->GetYolov4Mat(mat);
        bool isRead1 = _camObj1->GetYolov4Mat(mat1);

        if(isRead && isRead1)
        {
            emit SendMat1(mat);
            emit SendMat2(mat1);
        }

        _mux.unlock();
    }
}
