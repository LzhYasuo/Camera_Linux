#ifndef _CAMERA_THREAD_ID_0_H_
#define _CAMERA_THREAD_ID_0_H_

#include <QMutex>
#include <QObject>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

#include "../Filter/OpenCV_Filter.h"

class Camera_ThreadID0 : public QObject
{
	Q_OBJECT
public:
    Camera_ThreadID0();
    ~Camera_ThreadID0();

    void Open();
	void Close();
    bool GetYolov4Mat(cv::Mat&);

signals:
    void finish();
    void SendMat(cv::Mat);

private:
	QMutex mux;
	bool isClose;
    bool isCamera0;
    const int CamearIndex = 0;

    OpenCV_XFilter filt;
    cv::Mat PaintMat;
};



#endif //_CAMERA_THREAD_ID_0_H_
