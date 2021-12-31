#ifndef _GUI_OPENGL_WIDGET_H_
#define _GUI_OPENGL_WIDGET_H_

#include <QOpenGLWidget>
#include <QWidget>
#include "opencv2/imgproc.hpp"
#include <QImage>

class GuiOpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT
public:
	GuiOpenGLWidget(QWidget* parent = nullptr);
    virtual ~GuiOpenGLWidget();
public slots:
	//����������ͼƬת����IMGȻ���ڴ���ˢ��
	void ShowImg(cv::Mat);
protected:
	void paintEvent(QPaintEvent* e);
private:
	//��ʾ��ͼƬ
	QImage _img;
};


#endif //_GUI_OPENGL_WIDGET_H_
