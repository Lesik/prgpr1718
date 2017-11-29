#include <QPainter>
#include <QRectF>
#include <QWidget>

#include "snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent)
{
}

int Snake::getSize() {
    return SIZE;
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
    memset(currentworld, 0, sizeof(currentworld[0][0]) * SIZE * SIZE);
    // Kopf wird mitten ins Spielfeld gesetzt mit Richtung oben
    head.setX((int)(SIZE / 2));
    head.setY((int)(SIZE / 2));
    headDirection = Up;
    currentworld[head.x()][head.y()] = 8;
    tail = head;
    length = 1;
    generateFood();
}

void Snake::generateFood() {
    do {
        // arithmetic exception
        food.setX(rand() % SIZE);
        food.setY(rand() % SIZE);
    } while (head == food);
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
    if (head.x() < 0 || head.x() > SIZE) gameOver();
    if (head.y() < 0 || head.y() > SIZE) gameOver();
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
        // body wird vergrößert
        length++;
        // neues Essen wird generiert
        generateFood();
    }
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
    currentworld[head.x()][head.y()] = 0;
    /*int counter = 0;
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
    }*/
}

// Aufgabe 3d)
void Snake::collision() {
    //Kollision mit Essen
    eatFood();
    int x = head.x();
    int y = head.y();
    // Kollision mit Wand
    if (x < 0 || x > SIZE) gameOver();
    if (y < 0 || y > SIZE) gameOver();
    // Kollision mit sich selbst
}

void Snake::gameOver() {
    headDirection = Stop;
    // Timer muss disconnectet werden
}
