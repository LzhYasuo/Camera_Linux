#include "Pub_Function.h"
#include <QApplication>
#include <QIODevice>
#include <QDateTime>
#include <QTextStream>
#include <QFile>

std::string Pub_Function::GetStr(int index)
{
    const int capture_width = 800 ;
    const int capture_height =600  ;
    const int display_width = 800 ;
    const int display_height = 600 ;
    const int framerate = 3 ;
    const int flip_method = 0 ;
    const int CamearIndex = index;

    return "nvarguscamerasrc sensor-id=" + std::to_string(CamearIndex) + " ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + ", height=(int)" +
           std::to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + std::to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + std::to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           std::to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

QString Pub_Function::appName() const
{
	QString name;
	if (name.isEmpty())
	{
		name = qApp->applicationName();
		QStringList list = name.split("/");
		name = list.at(list.count() - 1).split(".").at(0);
	}
	return name;
}

QString Pub_Function::appPath() const
{
	//���������Android����
#ifdef Q_OS_ANDROID
	const QString path = QString("/sdcard/Android/%1").arg(appName());
	return path;
#else
	const QString path = qApp->applicationDirPath();
	return path;
#endif
}

void Pub_Function::writeInfo(const QString& info, bool needWrite /*= false*/, const QString& filePath /*= "log"*/, const QString& FileName /*= ""*/)
{
	if (!needWrite)
		return;

	QString fileName = QString("%1/%2%3_%4reinfo.txt")
		.arg(this->appPath()).arg(filePath).arg(this->appName()).arg(FileName)/*.arg(QDate::currentDate().toString())*/;

	QFile File(fileName);
	if (File.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text))
	{
		QTextStream stream(&File);
		stream << "\n" << QDateTime::currentDateTime().toString() << " " << info;
		File.close();
	}
}

void Pub_Function::writeError(const QString& info, bool needWrite /*= false*/, const QString& filePath /*= "log"*/, const QString& FileName /*= ""*/)
{
	if (!needWrite)
		return;
	QString fileName = QString("%1/%2%3_%4reerror.txt")
		.arg(this->appPath()).arg(filePath).arg(this->appName()).arg(FileName)/*.arg(QDate::currentDate().toString())*/;

	QFile File(fileName);
	if (File.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text))
	{
		QTextStream stream(&File);
		stream << "\n" << QDateTime::currentDateTime().toString() << " " << info;
		File.close();
	}
}

Pub_Function::Pub_Function()
{

}

Pub_Function::~Pub_Function()
{

}

