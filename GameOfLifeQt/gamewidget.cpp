#include "gamewidget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QRectF>
#include <QPainter>

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))
{
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
}

void GameWidget::setTimerIntervall(int t) {
    timer->setInterval(t);
}

void GameWidget::setUniverseSize(int size) {
    ca.setSize(size, size);
}

void GameWidget::startGame() {
    timer->start();
}

void GameWidget::stopGame() {
    timer->stop();
}

void GameWidget::clear() {
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
            universe[k*universeSize + j] = false;
        }
    }
    gameEnds(true);
}
