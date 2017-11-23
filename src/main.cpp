/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.game->setUniverseSize(50);
    return a.exec();
}
