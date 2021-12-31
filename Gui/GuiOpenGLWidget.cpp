#include "GuiOpenGLWidget.h"
#include <QPainter>
#include <QDebug>

GuiOpenGLWidget::GuiOpenGLWidget(QWidget* parent /*= nullptr*/)
    :QOpenGLWidget(parent)
{

	//_img = QImage();
	//QImage::Format fmt = QImage::Format_RGB888;
	//unsigned char* imgSize = new unsigned char[(this->width() * this->height() * 3)];
    //_img = QImage(imgSize, this->width(), this->height(), fmt);
}

QImage cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

GuiOpenGLWidget::~GuiOpenGLWidget()
{

}

void GuiOpenGLWidget::ShowImg(cv::Mat mat)
{
//    _img = cvMat2QImage(mat);
//    update();
    QImage::Format fmt = QImage::Format_RGB888;
    int pixSize = 3;
    if (mat.type() == CV_8UC1)
    {
        fmt = QImage::Format_Grayscale8;
        pixSize = 1;
    }
    if (fmt != _img.format() || _img.isNull())
    {
        delete _img.bits();
        unsigned char* imgSize = new unsigned char[(this->width()) * (this->height()) * pixSize];
        _img = QImage(imgSize, this->width(), this->height(), fmt);
    }
    cv::Mat des;
    cv::resize(mat, des, cv::Size(_img.size().width(), _img.size().height()));
    if (pixSize > 1)
    {
        cv::cvtColor(des, des, cv::COLOR_BGR2RGB);
    }
    memcpy(_img.bits(), des.data, des.cols * des.rows * des.elemSize());
    update();
}

void GuiOpenGLWidget::paintEvent(QPaintEvent* e)
{
	QPainter p;
	p.begin(this);
	p.drawImage(QPointF(0, 0), _img);
	p.end();
}
