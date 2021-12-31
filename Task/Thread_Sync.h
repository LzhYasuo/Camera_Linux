#ifndef THREAD_SYNC_H_
#define THREAD_SYNC_H_

#include <QThread>
#include <QMutex>

#include "Camera_ThreadID0.h"
#include "Camera_ThreadID1.h"

class Thread_Sync : public QThread
{
    Q_OBJECT
public:
    Thread_Sync();
    ~Thread_Sync();
    void Close();
    void Sleep(int msec);
protected:
    virtual void run();

signals:
    void SendMat1(cv::Mat);
    void SendMat2(cv::Mat);
    void CloseAll();
private:
    Camera_ThreadID0* _camObj0;
    Camera_ThreadID1* _camObj1;

    bool isClose = false;
    QMutex _mux;

    bool isOpen1 = false;
    bool isOpen2 = false;
private:
};



#endif //THREAD_SYNC_H_
