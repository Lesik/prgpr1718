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
    universeSize = size;
    ca.setSize(size, size);
    update();
}

void GameWidget::startGame() {
    timer->start();
}

void GameWidget::stopGame() {
    timer->stop();
}

void GameWidget::clear() {
    setUniverseSize(universeSize);
}

void GameWidget::newGeneration() {
    ca.evolve();
    update();
}

void GameWidget::mousePressEvent(QMouseEvent *event) {
    double cellGeometry = 580.00/universeSize;
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
    }
    update();
}

void GameWidget::mouseMoveEvent(QMouseEvent *event) {
    double cellGeometry = 580.00/universeSize;
    int xPosition = event->x()/cellGeometry;
    int yPosition = event->y()/cellGeometry;
    if (ca.getCell(xPosition, yPosition) == 0) {
        ca.setCell(xPosition, yPosition, 1);
    }
    update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
    paintGrid();
    paintUniverse();
}

void GameWidget::paintGrid()
{
    QPainter painter(this);
    QRect rec(0, 0, 580.00, 580.00);
    double cellGeometry = 580.00 / universeSize;
    for(double i = 0; i <= 580.00; i += cellGeometry) {
        painter.drawLine(i, 0, i, 580.00);
        painter.drawLine(0, i, 580.00, i);
    }
    painter.drawRect(rec);
}

void GameWidget::paintUniverse() {
    QPainter painter(this);
    double cellGeometry = 580.00 / universeSize;
    for(int j = 0; j < universeSize; j++) {
        for(int i = 0; i < universeSize; i++) {
            if(ca.getCell(i, j) == 1) {
                QRectF rec(i * cellGeometry, j * cellGeometry, cellGeometry, cellGeometry);
                painter.fillRect(rec, Qt::black);
            }
        }
    }
}
