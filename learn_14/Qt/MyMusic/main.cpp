#include "mainwindow.h"

#include <QApplication>
#include "resmgr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResMgr::getInstance().loadMusic("../MyMusic/resources/config.json");
    MainWindow w;
    w.show();
    return a.exec();
}
