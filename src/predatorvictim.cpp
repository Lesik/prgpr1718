#include <cstdlib>

#include "predatorvictim.h"

predatorvictim::predatorvictim()
{
    lifeInterval    = 50;
    ws              = 30;

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
    generateRandomWolrd();
}

void predatorvictim::worldEvolutionLifePredator()
{
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            cellEvolutionDirection(x, y);
        }
    }
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            cellEvolutionDirection(x, y);
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

void predatorvictim::cellEvolutionDirection(int x, int y)
{
    if (currentStatus[x][y] == 1) {
        if (neighbor(x, y, 2) > 0) {
            eatNeighbor(x, y, 1);
        }
        else randomMove(x, y);
    }
    if (currentStatus[x][y] == 2) {
        if (neighbor(x, y, 1) != 0) {
            if (neighbor(x, y, 3) > 0) {
                eatNeighbor(x, y, 2);
            }
            else randomMove(x, y);
        }
    }
}

void predatorvictim::generateRandomWolrd()
{
    int predator = 10;
    int victim = 20;
    int food = 30;
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

int predatorvictim::neighbor(int x, int y, int value)
{
    return 0;
}

void predatorvictim::eatNeighbor(int x, int y, int value)
{
    return;
}

void predatorvictim::randomMove(int x, int y)
{
    return;
}
