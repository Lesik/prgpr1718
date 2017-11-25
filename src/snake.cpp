#include <QPainter>
#include <QRectF>
#include <QWidget>

#include "snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent)
{
}

void Snake::paintHead(QPaintEvent *) {
    QPainter painter(this);
    for (int x = 0; x < ws.x(); x++) {
        for (int y = 0; y < ws.y(); y++) {
            if(currentworld[x][y] != 0) {
                qreal left  = cs.x() * x;
                qreal top   = cs.y() * y;
                QRectF r(left, top, cs.x(), cs.y());
                painter.fillRect(r, Qt::darkBlue); //Farbe für Kästchen
            }
        }
    }
}

// Aufgabe 4b)
void Snake::paintFood(QPaintEvent *) {
    QPainter painter(this);
    qreal left  = cs.x() * food.x();
    qreal top   = cs.y() * food.y();
    QRectF r(left, top, cs.x(), cs.y());
    painter.fillRect(r, Qt::red);
}

// Aufgabe 2
void Snake::PrepareFieldSnake() {
    for (int x = 0; x < ws.x(); x++) {
        for (int y = 0; y < ws.y(); y++) {
            currentworld[x][y] = 0;
            nextgenworld[x][y] = 0;
        }
    }
    head.setX((int)(ws.x() / 2));
    head.setY((int)(ws.y() / 2));
    headDirection = Up;
    currentworld[head.x()][head.y()] = 1;
    generateFood();
}

void Snake::generateWorld(int worldX, int worldY) {
    ws.setX(worldX);
    ws.setY(worldY);
    //cs.setX(width() / ws.x());
    //cs.setY(height() / ws.y());

    for (int i = 0; i < ws.x(); i++) {
        currentworld[i] = new int[ws.y()];
        nextgenworld[i] = new int[ws.y()];
    }

    PrepareFieldSnake();
}

void Snake::generateFood() {
    do {
        food.setX(rand() % ws.x());
        food.setY(rand() % ws.y());
    } while (head != food);
}

void Snake::setDirection(Direction direction) {
    if(headDirection == Up && direction == Down)
        return;
    if(headDirection == Left && direction == Right)
        return;
    if(headDirection == Down && direction == Up)
        return;
    if(headDirection == Right && direction == Left)
        return;
    headDirection = direction;
}

Snake::Direction Snake::getDirection() {
    return headDirection;
}

// Aufgabe 1
void Snake::evolve() {
    if (head.x() < 0 || head.x() > ws.x()) headDirection = Stop;
    if (head.y() < 0 || head.y() > ws.y()) headDirection = Stop;
    switch (headDirection) {
        case Up:    onUp(); break;
        case Left:  onLeft(); break;
        case Down:  onDown(); break;
        case Right: onRight(); break;
        case Stop:  return; break;
    }
    collision();
}

void Snake::eatFood() {
    if (head == food) {
        // tail wird vergrößert
    }
    // neues Essen wird generiert
    generateFood();
}

void Snake::paintEvent(QPaintEvent *event) {
    paintHead(event);
    paintFood(event);
}

void Snake::onUp() {
    currentworld[head.x()][head.y()-1] = 8;
    currentworld[head.x()][head.y()] = 0;
    head.ry() -= 1;
}

void Snake::onLeft() {
    currentworld[head.x()-1][head.y()] = 4;
    currentworld[head.x()][head.y()] = 0;
    head.rx() -= 1;
}

void Snake::onDown() {
    currentworld[head.x()][head.y()+1] = 2;
    currentworld[head.x()][head.y()] = 0;
    head.ry() += 1;
}

void Snake::onRight() {
    currentworld[head.x()+1][head.y()] = 6;
    currentworld[head.x()][head.y()] = 0;
    head.rx() += 1;
}

void Snake::collision() {

}

void Snake::gameOver() {

}
