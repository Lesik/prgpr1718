#include <QPainter>
#include <QRectF>
#include <QWidget>

#include "snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent)
{
}

void Snake::paintSnake(QPaintEvent *) {
    QPainter painter(this);
    for (int x = 0; x < ws.x(); x++) {
        for (int y = 0; y < ws.y(); y++) {
            if(currentworld[x][y] != 0) { // Füllt alle Felder != 0
                qreal left  = cs.x() * x;
                qreal top   = cs.y() * y;
                QRectF r(left, top, cs.x(), cs.y());
                painter.fillRect(r, Qt::darkBlue); //Farbe für Felder
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
    painter.fillRect(r, Qt::red); // Farbe des Essens
}

// Aufgabe 2)
void Snake::PrepareFieldSnake() {
    for (int x = 0; x < ws.x(); x++) {
        for (int y = 0; y < ws.y(); y++) {
            currentworld[x][y] = 0;
            nextgenworld[x][y] = 0;
        }
    }
    // Kopf wird mitten ins Spielfeld gesetzt mit Richtung oben
    head.setX((int)(ws.x() / 2));
    head.setY((int)(ws.y() / 2));
    headDirection = Up;
    currentworld[head.x()][head.y()] = 8;
    head = tail;
    generateFood();
}

void Snake::generateWorld(int worldX, int worldY) {
    ws.setX(worldX);
    ws.setY(worldY);
    // Zellengröße soll ausgerechnet werden
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

// Aufgabe 3b)
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

// Aufgabe 1)
void Snake::evolve() {
    // Aufgabe 1b)
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
        length++;
        // body wird vergrößert
    }
    // neues Essen wird generiert
    generateFood();
}

void Snake::paintEvent(QPaintEvent *event) {
    paintSnake(event);
    paintFood(event);
}

void Snake::onUp() {
    currentworld[head.x()][head.y()-1] = 8;
    body();
    head.ry() -= 1;
}

void Snake::onLeft() {
    currentworld[head.x()-1][head.y()] = 4;
    body();
    head.rx() -= 1;
}

void Snake::onDown() {
    currentworld[head.x()][head.y()+1] = 2;
    body();
    head.ry() += 1;
}

void Snake::onRight() {
    currentworld[head.x()+1][head.y()] = 6;
    body();
    head.rx() += 1;
}

void Snake::body() {
    if (head != food)
        currentworld[tail.x()][tail.y()] = 0;
}

// Aufgabe 3d)
void Snake::collision() {
    //Kollision mit Essen
    eatFood();
    int x = head.x();
    int y = head.y();
    // Kollision mit Wand
    if (x < 0 || x > ws.x()) gameOver();
    if (y < 0 || y > ws.y()) gameOver();
    // Kollision mit sich selbst
}

void Snake::gameOver() {
    // Timer muss disconnectet werden
}
