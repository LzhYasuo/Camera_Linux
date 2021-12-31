#ifndef _OPENCV_THREAD_H_
#define _OPENCV_THREAD_H_

#include <QThread>
#include <QMutex>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include "../Filter/OpenCV_Filter.h"

class OpenCV_Thread : public QThread
{
	Q_OBJECT
public:
	OpenCV_Thread();
	~OpenCV_Thread();

    bool DoSomething(int);
//    bool Open(QString path);
//    bool Open(int index);
	void Close();

    void Sleep(int msec);
	virtual void run();

signals:
    void CameraShow0(cv::Mat);
    void CamearShow1(cv::Mat);
    void CamearShow2(cv::Mat);
    void CameraShow3(cv::Mat);
private:
	QMutex mux;
	//�Ƿ��˳�
	bool isClose;
	//����ͷ�Ƿ��
    bool isCamera0;
    bool isCamera1;

	//��������ͷ������� fps����д��
    int _fps = 23;


    const int capture_width = 800 ;
    const int capture_height =600  ;
    const int display_width = 800 ;
    const int display_height = 600 ;
    const int framerate = 5 ;
    const int flip_method = 0 ;
    int CamearIndex = 0;

    OpenCV_XFilter filt;
};



#endif //_OPENCV_THREAD_H_
