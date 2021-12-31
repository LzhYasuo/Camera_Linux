#include "Camera_ThreadID0.h"
#include <QDebug>
#include <QFutureWatcher>
#include <QtConcurrent>

#include "../Pub/Pub_Function.h"
#include "../Filter/OpenCV_Filter.h"

static cv::VideoCapture capCamera0;

Camera_ThreadID0::Camera_ThreadID0()
{
	isClose = false;
    isCamera0 = false;
    filt.Add(CV_Task{TASKYOLO4});
}

Camera_ThreadID0::~Camera_ThreadID0()
{

}

void Camera_ThreadID0::Open()
{
   const std::string str = Pub_Function::Get()->GetStr(CamearIndex);
    mux.lock();
    const bool isOpen = capCamera0.open(str,cv::CAP_GSTREAMER);
    mux.unlock();
    if (!isOpen)
    {
        qDebug() << "false";
        return;
    }
    isCamera0 = true;
    return;
}

void Camera_ThreadID0::Close()
{
    capCamera0.release();
    filt.Clear();
    emit finish();
}


bool Camera_ThreadID0::GetYolov4Mat(cv::Mat& nullMat)
{
    bool isOk = false;
    if(capCamera0.read(nullMat) && isCamera0)
    {
          nullMat = filt.Filter(nullMat);
          isOk = true;
    }
    return isOk;
}
