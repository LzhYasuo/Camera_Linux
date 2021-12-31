#include "OpenCV_Filter.h"
#include "OpenCV_Action.h"
#include <QDebug>

//class OpenCV_XFilter : public OpenCV_Filter
//{
//public:
//	OpenCV_XFilter();
//	~OpenCV_XFilter();
//	virtual void Add(CV_Task);
//	virtual void Clear();
//	//virtual cv::Mat Filter(cv::Mat,cv::Mat);
//    virtual void Close();
//	virtual cv::Mat Filter(cv::Mat,cv::Mat = cv::Mat());
//private:
//	QList<CV_Task> _takList;
//    OpenCV_Action _pro;
//};

OpenCV_XFilter::OpenCV_XFilter()
{

}

OpenCV_XFilter::~OpenCV_XFilter()
{

}

void OpenCV_XFilter::Add(CV_Task tak)
{
	_takList.push_back(tak);
}

void OpenCV_XFilter::Clear()
{
	_takList.clear();
}

void OpenCV_XFilter::Close()
{
    _takList.clear();
}

cv::Mat OpenCV_XFilter::Filter(cv::Mat cap1, cv::Mat cap2)
{
    _pro.Set(cap1, cap2);
//    qDebug() << _takList.size();
	for (int i = 0; i < _takList.size(); i++)
	{
		Task tak = _takList.at(i)._tak;
		switch (tak)
		{
		case TASKYOLO4:
		{
            _pro.Actionyolo4();
			break;
		}
		}
	}
    return _pro.Get();
}

//OpenCV_Filter* OpenCV_Filter::Get()
//{
//	static OpenCV_XFilter cx;
//	return &cx;
//}

//OpenCV_Filter::OpenCV_Filter()
//{

//}

//OpenCV_Filter::~OpenCV_Filter()
//{

//}
