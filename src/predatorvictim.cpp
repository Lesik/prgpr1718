#include <cstdlib>
#include <QRectF>

#include "predatorvictim.h"

predatorvictim::predatorvictim()
{
    lifeInterval    = 50;
    ws              = 10;

}

void predatorvictim::prepareField()
{
    currentLife     = new int*[ws];
    nextgenLife     = new int*[ws];
    currentStatus   = new int*[ws];
    nextgenStatus   = new int*[ws];
    moveDirection   = new int*[ws];

    for (int i = 0; i < ws; i++) {
        currentLife[i]  = new int[ws];
        nextgenLife[i]  = new int[ws];
        currentStatus[i]= new int[ws];
        nextgenStatus[i]= new int[ws];
        moveDirection[i]= new int[ws];
        for (int j = 0; j < ws; j++) {
            currentLife[i][j]   = 0;
            nextgenLife[i][j]   = 0;
            currentStatus[i][j] = 0;
            nextgenStatus[i][j] = 0;
            moveDirection[i][j] = 0;
        }
    }
    generateRandomWorld();
}

void predatorvictim::worldEvolutionLifePredator()
{
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            QPoint point(x, y);
            randomMove(point);
            cellEvolutionDirection(point);
        }
    }
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            currentStatus[x][y] = nextgenStatus[x][y];
            nextgenStatus[x][y] = 0;
            currentLife[x][y] = nextgenLife[x][y];
            nextgenLife[x][y] = 0;
            moveDirection[x][y] = 0;
        }
    }

}

void predatorvictim::setSize(int size)
{
    ws = size;
    prepareField();
}

int predatorvictim::getSize()
{
    return ws;
}

void predatorvictim::setLifeInterval(int interval)
{
    lifeInterval = interval;
    prepareField();
}

void predatorvictim::setCell(int x, int y, int value)
{
    if (x >= 0 && y >= 0)
        if (x < ws && y < ws)
            currentStatus[x][y] = value;
}

int predatorvictim::getCell(int x, int y)
{
    if (x >= 0 && y >= 0)
        if (x < ws && y < ws)
            return currentStatus[x][y];
    return 0;
}

void predatorvictim::cellEvolutionDirection(QPoint point)
{
    QPoint newpoint = getPointByInt(point, moveDirection[point.x()][point.y()]);
    nextgenStatus[newpoint.x()][newpoint.y()] = currentStatus[point.x()][point.y()];
    return;
    if (currentStatus[point.x()][point.y()] == Predator) {
        if (neighbor(point, Victim) > 0) {
            eatNeighbor(point, Predator);
        }
        else randomMove(point);
    }
    if (currentStatus[point.x()][point.y()] == Victim) {
        if (neighbor(point, Predator) != 0) {
            if (neighbor(point, Food) > 0) {
                eatNeighbor(point, Victim);
            }
            else randomMove(point);
        }
    }
    if (currentStatus[point.x()][point.y()] == Predator || currentStatus[point.x()][point.y()] == Victim)
        currentLife[point.x()][point.y()]--;
}

void predatorvictim::generateRandomWorld()
{
    int predator = 2;
    int victim = 5;
    int food = 10;
    int sum = predator + victim + food;
    int counter = 0;

    do {
        int x = rand() % ws;
        int y = rand() % ws;
        if (currentStatus[x][y] == 0) {
            if (counter < food) currentStatus[x][y] = 3;
            if (counter >= food && counter < food + victim) currentStatus[x][y] = 2;
            if (counter >= food + victim) currentStatus[x][y] = 1;
            counter++;
        }
    } while (counter < sum);
}

int predatorvictim::neighbor(QPoint point, Status status)
{
    return 0;
}

void predatorvictim::eatNeighbor(QPoint point, Status status)
{
    return;
}

void predatorvictim::randomMove(QPoint point)
{
    if (currentStatus[point.x()][point.y()] == Predator || currentStatus[point.x()][point.y()] == Victim) {
        int direction = (rand() % 8) + 1;
        QPoint newpoint = getPointByInt(point, direction);
        bool check = legalityCheck(newpoint);
        int it = 6;
        if (legalityCheck(newpoint))   // TODO
            moveDirection[newpoint.x()][newpoint.y()] = direction;
    }
}

QPoint predatorvictim::getPointByInt(QPoint point, int direction) {
    switch (direction) {
    case 1:
        point.rx()--;
        point.ry()--;
        break;
    case 2:
        point.ry()--;
        break;
    case 3:
        point.rx()++;
        point.ry()--;
        break;
    case 4:
        point.rx()--;
        break;
    case 5:
        point.rx()++;
        break;
    case 6:
        point.rx()--;
        point.ry()++;
        break;
    case 7:
        point.ry()++;
        break;
    case 8:
        point.rx()++;
        point.ry()++;
        break;
    }
    return point;
}

bool predatorvictim::legalityCheck(QPoint point)
{
    // TODO CHECK FOR -1 COORDINATES, OTHERWISE OUTOFBOUNDS
    if ((0 <= point.x() && point.x() < ws) && (0 <= point.y() && point.y() < ws)) return false;
    int x = point.x();
    int y = point.y();
    if (x > 0) {
        if (y > 0) {
            if(moveDirection[x - 1][y - 1] == 9)    return false;
        }
        if(moveDirection[x - 1][y] == 8)            return false;
        if (y < ws - 1) {
            if(moveDirection[x - 1][y + 1] == 7)    return false;
        }
    }
    if (y > 0) {
        if(moveDirection[x][y - 1] == 6)            return false;
    }
    if (y < ws - 1) {
            if(moveDirection[x][y + 1] == 4)        return false;
    }
    if (x < ws - 1) {
        if (y > 0) {
            if(moveDirection[x + 1][y - 1] == 3)    return false;
        }
        if(moveDirection[x + 1][y] == 2)            return false;
        if (y < ws - 1) {
            if(moveDirection[x + 1][y + 1] == 1)    return false;
        }
    }
    return true;
}
