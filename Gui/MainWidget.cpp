#include "MainWidget.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QFile>
#include <QFileDialog>

#include "GuiOpenGLWidget.h"
#include "Task/Thread_Sync.h"

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

MainWidget::MainWidget(QWidget* parent /*= nullptr*/)
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    _sync = new Thread_Sync();

    this->setFixedSize(1600, 800);
	this->Init();

    _sync->start();

}

void MainWidget::closeEvent(QCloseEvent *event)
{
    _sync->Close();
}

MainWidget::~MainWidget()
{

}

void MainWidget::Init()
{
	QHBoxLayout* mLayout = Get_HLayout();

	QWidget* mWidget = InitWidget();

	mLayout->addWidget(mWidget);

	this->setLayout(mLayout);
}

QWidget* MainWidget::InitWidget()
{
	QWidget* mWidget = new QWidget();
	QVBoxLayout* mLayout = Get_VLayout();

    QHBoxLayout* glLayout = Get_HLayout();
    GuiOpenGLWidget* glWidget0 = new GuiOpenGLWidget();
    glWidget0->setFixedWidth(800);
    GuiOpenGLWidget* glWidget1 = new GuiOpenGLWidget();
    glWidget1->setFixedWidth(800);
    glLayout->addWidget(glWidget0);
    glLayout->addWidget(glWidget1);


	QHBoxLayout* buttonLayout = Get_HLayout();
    QPushButton* btn_Camear0 = Get_Button("Camear0");
    QPushButton* btn_Camear1 = Get_Button("Camear1");

    QPushButton* btn_Open = Get_Button("VOice");

	QPushButton* btn_yolo4 = Get_Button("yolo4");
    buttonLayout->addWidget(btn_Camear0);
    buttonLayout->addWidget(btn_Camear1);
	buttonLayout->addWidget(btn_Open);
	buttonLayout->addWidget(btn_yolo4);

    mLayout->addLayout(glLayout);
	mLayout->addLayout(buttonLayout);
	mWidget->setLayout(mLayout);

    this->connect(_sync,&Thread_Sync::SendMat1,glWidget0,&GuiOpenGLWidget::ShowImg);
    this->connect(_sync,&Thread_Sync::SendMat2,glWidget1,&GuiOpenGLWidget::ShowImg);

	return mWidget;
}
