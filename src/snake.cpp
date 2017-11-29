#include <QPainter>
#include <QRectF>
#include <QWidget>

#include "snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent)
{
}

int Snake::getCell(int x, int y) {
    return currentworld[x][y];
}

int Snake::getFoodCoordX() {
    return food.x();
}

int Snake::getFoodCoordY() {
    return food.y();
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
    length = 1;
    generateFood();
}

void Snake::generateWorld(int worldX, int worldY) {
    ws.setX(worldX);
    ws.setY(worldY);

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
    //if (head.x() < 0 || head.x() > ws.x()) headDirection = Stop;
    //if (head.y() < 0 || head.y() > ws.y()) headDirection = Stop;
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

void Snake::onUp() {
    currentworld[head.x()][head.y()-1] = 8;
    generateBody();
    head.ry() -= 1;
}

void Snake::onLeft() {
    currentworld[head.x()-1][head.y()] = 4;
    generateBody();
    head.rx() -= 1;
}

void Snake::onDown() {
    currentworld[head.x()][head.y()+1] = 2;
    generateBody();
    head.ry() += 1;
}

void Snake::onRight() {
    currentworld[head.x()+1][head.y()] = 6;
    generateBody();
    head.rx() += 1;
}

void Snake::generateBody() {
    int counter = 0;
    int currentTail = currentworld[tail.x()][tail.y()];
    currentworld[tail.x()][tail.y()] = 0;
    if (head != food) {
        do {
            switch (currentTail) {
                case 2: break;
                case 4: break;
                case 6: break;
                case 8: break;
            }
            counter++;
        } while (length == counter);
    }
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
