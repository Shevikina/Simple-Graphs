#include "mainwindow.h"
#include "vsegrafiki.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vsegrafiki v;
    v.show();
    return a.exec();
}


