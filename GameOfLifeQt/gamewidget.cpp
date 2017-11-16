#include "gamewidget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QRectF>
#include <QPainter>
#include <iostream>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))
{
    //connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

void GameWidget::setTimerIntervall(int t) {
    //timer->setInterval(t);
}

void GameWidget::setUniverseSize(int size) {
    ca.setSize(size, size);
}

void GameWidget::startGame() {
    std::cout << "asd" << std::endl;
    //timer->start();
}

void GameWidget::stopGame() {
    //timer->stop();
}

void GameWidget::clear() {
}
