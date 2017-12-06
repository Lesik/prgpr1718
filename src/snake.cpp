/*
    Javi (6038555), Lesik (6082200), Kelvin Tsang (5428328)
*/


#include <QPainter>
#include <QRectF>
#include <QWidget>
#include <QDebug>

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

bool Snake::getEnd() {
    return end;
}

QPoint Snake::getFood() {
    return food;
}

// Aufgabe 2)
void Snake::prepareFieldSnake() {
    end = false;
    // Spielfeld wird initialisiert
    memset(currentworld, 0, sizeof(currentworld[0][0]) * SIZE * SIZE);
    // Kopf wird mitten ins Spielfeld gesetzt
    head.setX((int)(SIZE / 2));
    head.setY((int)(SIZE / 2));
    headDirection = Stop;
    currentworld[head.x()][head.y()] = 1;
    tail = head;

    generateFood();

    //Ränder werden definiert
    for (int i = 0; i < SIZE; i++) {
        currentworld[0][i] = -1;
        currentworld[i][0] = -1;
        currentworld[i][SIZE-1] = -1;
        currentworld[SIZE-1][i] = -1;
    }
}

void Snake::generateFood() {
    do {
        // Nahrung wird random im Intervall 1 und Size - 2 generiert
        food.setX((rand() % (SIZE - 2)) + 1);
        food.setY((rand() % (SIZE - 2)) + 1);
    } while (currentworld[food.x()][food.y()] != 0); // solange bis auf dem Feld nichts ist
}

// Aufgabe 3b)
void Snake::setDirection(Direction direction) {
    // verhindert, dass wenn Schlange Richtung X geht, nicht in die entgegengesetzte Richtung gehen kann
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

// Aufgabe 1)
void Snake::evolve() {
    // Aufgabe 1b) // bitte drin lassen
    /*
    if (head.x() == 0 ) {
        headDirection = Stop;
        end = true;
    }
    if (head.x() == SIZE) {
        headDirection = Stop;
        end = true;
    }
    if (head.y() == 0) {
        headDirection = Stop;
        end = true;
    }
    if (head.y() == SIZE) {
        headDirection = Stop;
        end = true;
    }
    */

    doHead();
    doTail();
}

void Snake::doHead() {
    switch (headDirection) {
    // Schlange bewegt sich in Richtung X und wenn Feld vor der Schlange belegt ist -> Spiel ende
    case Down:
        currentworld[head.x()][head.y()] = 2;
        head.ry()++;
        if (currentworld[head.x()][head.y()] != 0)
            end = true;
        currentworld[head.x()][head.y()] = 2;
        break;
    case Left:
        currentworld[head.x()][head.y()] = 4;
        head.rx()--;
        if (currentworld[head.x()][head.y()] != 0)
            end = true;
        currentworld[head.x()][head.y()] = 4;
        break;
    case Right:
        currentworld[head.x()][head.y()] = 6;
        head.rx()++;
        if (currentworld[head.x()][head.y()] != 0)
            end = true;
        currentworld[head.x()][head.y()] = 6;
        break;
    case Up:
        currentworld[head.x()][head.y()] = 8;
        head.ry()--;
        if (currentworld[head.x()][head.y()] != 0)
            end = true;
        currentworld[head.x()][head.y()] = 8;
        break;
    case Stop:
        return;
        break;
    }
}

void Snake::doTail() {
    // wenn Schlange Nahrung ist, wird neues Essen generiert
    bool eaten = (head.x() == food.x() && head.y() == food.y());
    if (eaten) {
        generateFood();
    } else {
        // Schwanz wird gekürzt
        switch (currentworld[tail.x()][tail.y()]) {
        case 2:
            currentworld[tail.x()][tail.y()] = 0;
            tail.ry()++;
            break;
        case 4:
            currentworld[tail.x()][tail.y()] = 0;
            tail.rx()--;
            break;
        case 6:
            currentworld[tail.x()][tail.y()] = 0;
            tail.rx()++;
            break;
        case 8:
            currentworld[tail.x()][tail.y()] = 0;
            tail.ry()--;
            break;
        }
    }
}
