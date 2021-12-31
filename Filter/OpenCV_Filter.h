#ifndef _OPENCV_FILTER_H_
#define _OPENCV_FILTER_H_

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <QVariant>

#include "OpenCV_Action.h"

enum Task
{
	TASKYOLO4,
};

struct CV_Task
{
	Task _tak;
	QVariant _val;
};

//class OpenCV_Filter
//{
//public:
//	static OpenCV_Filter* Get();
//	virtual void Add(CV_Task) = 0;
//	//virtual cv::Mat Filter(cv::Mat,cv::Mat) = 0;
//	virtual cv::Mat Filter(cv::Mat,cv::Mat = cv::Mat()) = 0;
//	virtual void Clear() = 0;
//    virtual void Close() = 0;
//protected:
//	OpenCV_Filter();
//	~OpenCV_Filter();
//};


class OpenCV_XFilter
{
public:
    OpenCV_XFilter();
    ~OpenCV_XFilter();
    void Add(CV_Task);
    void Clear();
    //virtual cv::Mat Filter(cv::Mat,cv::Mat);
    void Close();
    cv::Mat Filter(cv::Mat,cv::Mat = cv::Mat());
private:
    QList<CV_Task> _takList;
    OpenCV_Action _pro;
};

#endif //_OPENCV_FILTER_H_
