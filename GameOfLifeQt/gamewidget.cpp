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
    ca.runTests();
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

/*
 * Overriden function that is called whenever widget wants to redraw.
 */
void GameWidget::paintEvent(QPaintEvent *)
{
    // initiate painter
    QPainter painter(this);
    painter.setPen(Qt::darkGreen);
    // calculate width and height of cell by dividing available space by amount of cells needed
    double cellWidth = (double) width() / ca.getNx();
    double cellHeight = (double) height() / ca.getNy();
    // draw cell dividers
    for (double i = cellWidth; i <= width(); i += cellWidth)
        painter.drawLine(i, 0, i, height());
    for (double i = cellHeight; i <= height(); i += cellHeight)
        painter.drawLine(0, i, width(), i);

    // draw border from x = 0, y = 0 to x = width - 1, y = height - 1
    QRect borders(0, 0, width() - 1, height() - 1);
    painter.drawRect(borders);

    // for each cell in world, if is alive
    for (int x = 0; x < ca.getNx(); x++) {
        for (int y = 0; y < ca.getNy(); y++) {
            if (ca.getCell(x, y)) {
                // calculate left and top edges by calculating distance from top left edge
                qreal left = (qreal) (cellWidth * x);
                qreal top = (qreal) (cellHeight * y);
                // the cell should be cellWidth wide and cellHeight tall
                QRectF r(left, top, (qreal) cellWidth, (qreal) cellHeight);
                painter.fillRect(r, Qt::darkBlue);
            }
        }
    }
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{

}
