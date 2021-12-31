#include "Gui/MainWidget.h"
#include <QWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
//    QWidget w;
    w.show();

    return a.exec();
}




