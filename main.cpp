#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QIcon>
#include "headers/mainclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./icons/goomba.png"));
    QPixmap pixmap("./icons/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Loading...");

    MainClient mc;
    mc.show();
    splash.finish(&mc);
    return a.exec();
}