#include "mainwindow.h"

#include <QApplication>
#include "resmgr.h"

#include "SDL.h"

int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_VIDEO);

SDL_Quit();

    QApplication a(argc, argv);
    ResMgr::getInstance().loadMusic("../MyMusic/resources/config.json");
    MainWindow w;
    w.show();
    return a.exec();
}
