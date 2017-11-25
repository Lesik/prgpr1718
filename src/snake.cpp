#include <QPainter>
#include <QRectF>
#include <QWidget>

#include "snake.h"
#include "cabase.h"

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
    for (int x = 0; x < ws.y(); x++) {
        currentworld[x] = new int[ws.y()];
        nextgenworld[x] = new int[ws.y()];
        for (int y = 0; y < ws.y(); y++) {
            currentworld[x][y] = 0;
            nextgenworld[x][y] = 0;
        }
    }
    head.setX((int)(ws.x() / 2));
    head.setY((int)(ws.y() / 2));
}

void Snake::generateWorld(int worldX, int worldY) {
    ws.setX(worldX);
    ws.setY(worldY);
    //cs.setX(width() / ws.x());
    //cs.setY(height() / ws.y());

    currentworld = new int*[ws.x()];
    nextgenworld = new int*[ws.x()];
    for (int x = 0; x < ws.y(); x++) {
        currentworld[x] = new int[ws.y()];
        nextgenworld[x] = new int[ws.y()];
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
        case Stop: return; break;
    }
    collision();
}

void Snake::eatFood() {
    if (head == food) {
        // tail wird vergrößert
    }
    generateFood();
}

void Snake::paintEvent(QPaintEvent *event) {
    paintHead(event);
    paintFood(event);
}

// keyPressEvent muss in gamewidget.h/cpp
void Snake::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Up:    setDirection(Up); break;
        case Qt::Key_Left:  setDirection(Left); break;
        case Qt::Key_Down:  setDirection(Down); break;
        case Qt::Key_Right: setDirection(Right); break;

        case Qt::Key_W:     setDirection(Up); break;
        case Qt::Key_A:     setDirection(Left); break;
        case Qt::Key_S:     setDirection(Down); break;
        case Qt::Key_D:     setDirection(Right); break;

        case Qt::Key_8:     setDirection(Up); break;
        case Qt::Key_4:     setDirection(Left); break;
        case Qt::Key_2:     setDirection(Down); break;
        case Qt::Key_6:     setDirection(Right); break;
    }
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
