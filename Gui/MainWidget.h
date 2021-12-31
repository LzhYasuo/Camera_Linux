#ifndef _MAIN_WIDGET_H_
#define _MAIN_WIDGET_H_

#include "GuiBaseWidget.h"
//#include "Task/Thread_Sync.h"

class Thread_Sync;
class OpenCV_Thread;
class MainWidget : public GuiBaseWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = nullptr);
	virtual ~MainWidget();

protected:
    void closeEvent(QCloseEvent *event);

private:
	void Init();
	QWidget* InitWidget();

private:

    Thread_Sync * _sync;

};


#endif //MAIN_WIDGET_H_
