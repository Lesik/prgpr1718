/*
    Fatih (), Javi (), Lesik (), Kelvin Tsang (5428328)

    Milestone 1

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
