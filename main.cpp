#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/new/splash/splash.png"));
    splash->show();

    MainWindow w;
    QTimer::singleShot(100,splash,SLOT(close()));
    QTimer::singleShot(100,&w,SLOT(show()));

    return a.exec();
}
