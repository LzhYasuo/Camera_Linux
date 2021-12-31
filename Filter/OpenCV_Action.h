#ifndef _OPENCV_ACTION_H_
#define _OPENCV_ACTION_H_

#ifdef _WIN32
#define OPENCV
#define GPU
#endif

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

#include <iostream>
#include "yolo_v2_class.hpp"
#include "darknet.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <QVector>
#include <QString>

//#pragma comment(lib, "yolo_cpp_dll.lib") //引入YOLO动态链接库

class OpenCV_Action
{
public:
    OpenCV_Action();
    ~OpenCV_Action();

    void Set(cv::Mat, cv::Mat);
    cv::Mat Get() const;

    void Actionyolo4();
    void Clear();
    void Close();

private:
    const std::string _nameFile = "/home/nako/QtPro/Yolo_Camear/coco.names";
    const std::string _cfgFile = "/home/nako/QtPro/Yolo_Camear/yolov4-tiny.cfg";
    const std::string _widgetFile = "/home/nako/QtPro/Yolo_Camear/yolov4-tiny.weights";
    std::vector<std::string> obj_names;

    cv::Mat _inputMat;
    cv::Mat _inputMat2;
    cv::Mat _ouputMat;
    Detector* _detector;
};

#endif //_OPENCV_ACTION_H_
