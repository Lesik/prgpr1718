#include "gamewidget.h"
#include "CAbase.h"
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
    timer->start(100);
}

void GameWidget::stopGame() {
    //timer->stop();
}

void GameWidget::clear() {
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QRect borders(0, 0, width() - 1, height() - 1);
    painter.drawRect(1, 2, 6, 4);
    painter.setPen(Qt::darkGreen);
    double cellWidth = (double) width() / ca.getNx();
    double cellHeight = (double) height() / ca.getNy();
    for (double i = cellWidth; i <= width(); i += cellWidth)
        painter.drawLine(i, 0, i, height());
    for (double i = cellHeight; i <= height(); i += cellHeight)
        painter.drawLine(i, 0, i, width());
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{

}
