#include <cstdlib>

#include "predatorvictim.h"

predatorvictim::predatorvictim()
{
    maxHealth   = 50;
    ws          = 50;

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
        }
    }
    generateRandomWolrd();
}

void predatorvictim::evolve()
{
    // moveDirection wird 0 gesetzt
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            moveDirection[x][y] = 0;
        }
    }

    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++) {
            randomMove(x, y);
        }
    }

    moveDirection2currentStatus();
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
}

void predatorvictim::moveDirection2currentStatus()
{
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++){
            int xPos = x;
            int yPos = y;
            switch (moveDirection[x][y]) {
            case 1:
                xPos--;
                yPos--;
                break;
            case 2:
                xPos--;
                break;
            case 3:
                xPos--;
                yPos++;
                break;
            case 4:
                yPos--;
                break;
            case 6:
                yPos++;
                break;
            case 7:
                xPos++;
                yPos--;
                break;
            case 8:
                xPos++;
                break;
            case 9:
                xPos++;
                yPos++;
                break;
            }
            nextgenStatus[xPos][yPos] = currentStatus[x][y];
        }
    }
    for (int x = 0; x < ws; x++) {
        for (int y = 0; y < ws; y++){
            currentStatus[x][y] = nextgenStatus[x][y];
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

void predatorvictim::randomMove(int x, int y)
{
    int xPos = x;
    int yPos = y;
    int var = 0;

    switch (rand() % 8) {
    case 0:
        xPos--;
        yPos--;
        var = 1;
        break;
    case 1:
        xPos--;
        var = 2;
        break;
    case 2:
        xPos--;
        yPos++;
        var = 3;
        break;
    case 3:
        yPos--;
        var = 4;
        break;
    case 4:
        yPos++;
        var = 6;
        break;
    case 5:
        xPos++;
        yPos--;
        var = 7;
        break;
    case 6:
        xPos++;
        var = 8;
        break;
    case 7:
        xPos++;
        yPos++;
        var = 9;
        break;
    }
    if (xPos >= 0 && yPos >= 0) {
        if (xPos < ws && y < ws) {
            if (legalityCheck(xPos, yPos) == true) {
                moveDirection[x][y] = var;
            }
            else moveDirection[x][y] = 0;
        }
    }
}

void predatorvictim::eatNeighbor(int x, int y, int value)
{
    int xPos = x;
    int yPos = y;
    int var;

    switch (currentNeighbor[rand() % numberNeighbor]) {
    case 0:
        xPos--;
        yPos--;
        var = 1;
        break;
    case 1:
        xPos--;
        var = 2;
        break;
    case 2:
        xPos--;
        yPos++;
        var = 3;
        break;
    case 3:
        yPos--;
        var = 4;
        break;
    case 4:
        yPos++;
        var = 6;
        break;
    case 5:
        xPos++;
        yPos--;
        var = 7;
        break;
    case 6:
        xPos++;
        var = 8;
        break;
    case 7:
        xPos++;
        yPos++;
        var = 9;
        break;
    }
    if (legalityCheck(xPos, yPos) == true) {
        //nextStatus[xPos][yPos] = value;
        //nextLife[xPos][yPos] = maxHealth;
        moveDirection[x][y] = var;
    }
}

int predatorvictim::neighbor(int x, int y, int value)
{
    int counter = 0;
    if (x > 0) {
        if (y > 0) {
            if (currentStatus[x - 1][y - 1] == value) {
                currentNeighbor[counter] = 0;
                counter++;
            }
        }
        if (currentStatus[x - 1][y] == value) {
            currentNeighbor[counter] = 1;
            counter++;
        }
        if (y < ws - 1) {
            if (currentStatus[x - 1][y + 1] == value) {
                currentNeighbor[counter] = 2;
                counter++;
            }
        }
    }
    if (y > 0) {
        if (currentStatus[x][y - 1] == value) {
            currentNeighbor[counter] = 3;
            counter++;
        }
    }
    if (y < ws - 1) {
        if (currentStatus[x][y + 1] == value) {
            currentNeighbor[counter] = 4;
            counter++;
        }
    }
    if (x < ws - 1) {
        if (y > 0) {
            if (currentStatus[x + 1][y - 1] == value) {
                currentNeighbor[counter] = 5;
                counter++;
            }
        }
        if (currentStatus[x + 1][y] == value) {
            currentNeighbor[counter] = 6;
            counter++;
        }
        if (y < ws - 1) {
            if (currentStatus[x + 1][y + 1] == value) {
                currentNeighbor[counter] = 7;
                counter++;
            }
        }
    }

    return counter;
}

bool predatorvictim::legalityCheck(int x, int y)
{
    bool legal = true;
    if (x > 0) {
        if (y > 0) {
            if(moveDirection[x - 1][y - 1] == 9)    legal = false;
        }
        if(moveDirection[x - 1][y] == 8)            legal = false;
        if (y < ws - 1) {
            if(moveDirection[x - 1][y + 1] == 7)    legal = false;
        }
    }
    if (y > 0) {
        if(moveDirection[x][y - 1] == 6)            legal = false;
    }
    if (y < ws - 1) {
            if(moveDirection[x][y + 1] == 4)        legal = false;
    }
    if (x < ws - 1) {
        if (y > 0) {
            if(moveDirection[x + 1][y - 1] == 3)    legal = false;
        }
        if(moveDirection[x + 1][y] == 2)            legal = false;
        if (y < ws - 1) {
            if(moveDirection[x + 1][y + 1] == 1)    legal = false;
        }
    }
    return legal;
}

