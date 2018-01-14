#include <cstdlib>
#include <QRectF>
#include <string.h>

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
    currentStatus   = new Status*[ws];
    nextgenStatus   = new Status*[ws];
    moveDirection   = new int*[ws];

    for (int i = 0; i < ws; i++) {
        currentLife[i]  = new int[ws];
        nextgenLife[i]  = new int[ws];
        currentStatus[i]= new Status[ws];
        nextgenStatus[i]= new Status[ws];
        moveDirection[i]= new int[ws];
        for (int j = 0; j < ws; j++) {
            currentLife[i][j]   = 0;
            nextgenLife[i][j]   = 0;
            currentStatus[i][j] = Dead;
            nextgenStatus[i][j] = Dead;
            moveDirection[i][j] = 0;
        }
    }
    generateRandomWorld();
}

void predatorvictim::worldEvolutionLifePredator()
{
    // clear previous directions
    //memset(moveDirection, 0, sizeof(moveDirection[0][0]) * ws * ws);

    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            QPoint point(x, y);
            Status me = currentStatus[point.x()][point.y()];
            int life = currentLife[point.x()][point.y()];

            // don't do anything if we are food
            if (me == Dead || me == Food)
                continue;

            // life is empty, is dead
            if (life == 1)
                continue;

            // don't move if you are hase and have the wolfs around you
            if (me == Victim && !existsWolfAroundMe(point))
                moveDirection[point.x()][point.y()] = 5;

            if (me == Predator || me == Victim) {
                // who is searching for what? I am so confused. but the following line clears it up
                int direction = neighbor(point, me == Predator ? Victim : Food);
                // if we didn't find a direction with neighbor(), let rand() decide
                if (!direction) {
                    do {
                        direction = (rand() % 9) + 1;
                    } while (direction == 5 || !legalityCheck(getPointByInt(point, direction)));
                }
                moveDirection[point.x()][point.y()] = direction;
            }
        }
    }
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            QPoint point(x, y);
            Status me = currentStatus[point.x()][point.y()];

            // don't do anything if we are food
            if (me == Dead)
                continue;

            if (me == Food)
                nextgenStatus[point.x()][point.y()] = me;

            int life = currentLife[point.x()][point.y()];
            if (life - 1 == 0) {
                nextgenStatus[point.x()][point.y()] == Dead;
                continue;
            }

            QPoint placeWhereIWillMove = getPointByInt(point, moveDirection[point.x()][point.y()]);
            Status whatIsThereWhereIWIllMove = currentStatus[placeWhereIWillMove.x()][placeWhereIWillMove.y()];


            // copy old life health points into new life minus one
            nextgenLife[placeWhereIWillMove.x()][placeWhereIWillMove.y()] = currentLife[point.x()][point.y()] - 1;

            if ((me == Predator && whatIsThereWhereIWIllMove == Victim) || (me == Victim && whatIsThereWhereIWIllMove == Food)) {
                nextgenLife[placeWhereIWillMove.x()][placeWhereIWillMove.y()] = maxlife;
            }

            // move
            nextgenStatus[placeWhereIWillMove.x()][placeWhereIWillMove.y()] = me;

        }
    }

    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            currentStatus[x][y] = nextgenStatus[x][y];
            nextgenStatus[x][y] = Dead;
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
            currentStatus[x][y] = (Status) value;
}

int predatorvictim::getCell(int x, int y)
{
    if (x >= 0 && y >= 0)
        if (x < ws && y < ws)
            return (int) currentStatus[x][y];
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
            if (counter < food) currentStatus[x][y] = Food;
            if (counter >= food && counter < food + victim) currentStatus[x][y] = Victim;
            if (counter >= food + victim) currentStatus[x][y] = Predator;
            if (currentStatus[x][y] == Predator || currentStatus[x][y] == Victim) currentLife[x][y] = maxlife;
            counter++;
        }
    } while (counter < sum);
}


bool predatorvictim::existsWolfAroundMe(QPoint point)
{
    // no 5 because no need to check if we are wolf ourselves
    for (int i : { 1, 2, 3, 4, 6, 7, 8, 9 }) {
        QPoint possiblewolf = getPointByInt(point, i);
        if (outOfBoundsCheck(possiblewolf)) continue;
        if (currentStatus[possiblewolf.x()][possiblewolf.y()] == Predator) return true;
    }
    return false;
}

int predatorvictim::neighbor(QPoint point, Status status)
{
    for (int i : { 1, 2, 3, 4, 6, 7, 8, 9 }) {
        QPoint searchForNeightbor = getPointByInt(point, i);
        // return false if check outside of boundary
        if (outOfBoundsCheck(searchForNeightbor)) continue;
        if (currentStatus[searchForNeightbor.x()][searchForNeightbor.y()] == status) return i;
    }
    return false;
}

void predatorvictim::randomMove(QPoint point)
{
    if (currentStatus[point.x()][point.y()] == Predator || currentStatus[point.x()][point.y()] == Victim) {
        int direction = (rand() % 8) + 1;
        QPoint newpoint = getPointByInt(point, direction);
        bool check = legalityCheck(newpoint);
        int it = 6;
        if (legalityCheck(newpoint))   // TODO
            moveDirection[point.x()][point.y()] = direction;
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
        break;
    case 6:
        point.rx()++;
        break;
    case 7:
        point.rx()--;
        point.ry()++;
        break;
    case 8:
        point.ry()++;
        break;
    case 9:
        point.rx()++;
        point.ry()++;
        break;
    }
    return point;
}

/*
 * return true if out of bounce
 * and false if point is OK
 */
bool predatorvictim::outOfBoundsCheck(QPoint point) {
    return (point.x() < 0 || point.x() >= ws || point.y() < 0 || point.y() >= ws);
}

bool predatorvictim::legalityCheck(QPoint point)
{
    // if out of bounds, legality is wounds
    if (outOfBoundsCheck(point)) return false;
    int x = point.x();
    int y = point.y();
    // other legality checks by kelvin
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
