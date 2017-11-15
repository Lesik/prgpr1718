#include <iostream>
#include <cstdlib>
#include "CAbase.h"

using namespace std;

/*
 * Constructor – set
 */
CAbase::CAbase(int x, int y) { worldWidth = x; worldHeight = y; createWorld(); populate_test(); }

/*
 * Empty deconstructor
 */
CAbase::~CAbase() {}

int CAbase::getIndexByCoord(int x, int y) { return x + worldHeight * y; }

void CAbase::createWorld()
{
    currentworld = new int[worldWidth * worldHeight];
    nextgenworld = new int[worldWidth * worldHeight];
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
                currentworld[getIndexByCoord(x, y)] = 0;
                nextgenworld[getIndexByCoord(x, y)] = 0;
        }
    }
}

void CAbase::populateRandomly()
{
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
                currentworld[getIndexByCoord(x, y)] = rand() % 2;
        }
    }
}

void CAbase::populate_test()
{
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
                currentworld[getIndexByCoord(x, y)] = 0;
        }
    }
    currentworld[getIndexByCoord(0, 0)] = 1;
    currentworld[getIndexByCoord(29, 29)] = 1;
    // blinker
    currentworld[getIndexByCoord(4, 4)] = 1;
    currentworld[getIndexByCoord(5, 4)] = 1;
    currentworld[getIndexByCoord(6, 4)] = 1;
    //rechteck
    currentworld[getIndexByCoord(12, 12)] = 1;
    currentworld[getIndexByCoord(12, 13)] = 1;
    currentworld[getIndexByCoord(13, 12)] = 1;
    currentworld[getIndexByCoord(13, 13)] = 1;
}

void CAbase::setSize(int x, int y) // Erstellt die Größe des Feldes
{
    // DON'T USE YET
    worldWidth = x;
    worldHeight = y;

    delete[] currentworld;
    currentworld = new int [x * y];
    delete[] nextgenworld;
    nextgenworld = new int [x * y];
}

void CAbase::setCell(int x, int y, int wert) // Setzt wert auf Zelle (x,y)
{
    currentworld[x + worldHeight * y] = wert;
}

void CAbase::setCell_next(int x, int y, int wert) // Setzt wert auf Zelle (x,y)
{
    nextgenworld[x + worldHeight * y] = wert;
}

/*
 * Return true if element (x,y) is alive, false otherwise
 */
int CAbase::getCell(int x, int y)
{
    return currentworld[x + worldHeight * y];
}
int CAbase::getNx() //
{
    return worldWidth;
}

int CAbase::getNy() //
{
    return worldHeight;
}

int CAbase::nachbar(int x, int y) // Zählt die Anzahl der Nachbarn vom Feld (x,y)
{
    int anzahlNachbar = 0;
    int arrayX[8] = {x - 1, x - 1, x - 1, x, x, x + 1, x + 1, x + 1};
    int arrayY[8] = {y - 1, y, y + 1, y - 1, y + 1, y - 1, y, y + 1};
    for(int i = 0; i < 8; i++) {
        if(arrayX[i] > worldHeight)
            arrayX[i] = 0;
        if(arrayX[i] < 0)
            arrayX[i] = worldHeight;
        if(arrayY[i] > worldWidth)
            arrayX[i] = 0;
        if(arrayY[i] < 0)
            arrayX[i] = worldWidth;
        if(getCell(arrayX[i], arrayY[i])) anzahlNachbar++;
    }

    return anzahlNachbar;
}

void CAbase::print() {
    cout << ". ";
    for (int j = 0; j < worldWidth; j++) {
        cout << " . ";
    }
    cout << " .";
    cout << endl;
    for (int i = 0; i < worldHeight; i++) {
        cout << ". ";
        for (int k = 0; k < worldWidth; k++) {
            if (currentworld[getIndexByCoord(k, i)] == 1) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }
        }
        cout << " .";
        cout << endl;
    }
    cout << ". ";
    for (int j = 0; j < worldWidth; j++) {
        cout << " . ";
    }
    cout << " .";
    cout << endl;
}

void CAbase::regel(int x, int y) // Regel des Spiels
{
    if (getCell(x, y) == 1) {
        switch (nachbar(x, y)) {
            case 2:
                setCell_next(x, y, 1);
                break;
            case 3:
                setCell_next(x, y, 1);
                break;
            default:
                setCell_next(x, y, 0);
        }
    }
     else {
        if (nachbar(x, y) == 3) {setCell_next(x, y, 1);}
    }
}

void CAbase::evolve()
{
    for (int y = 0; y < worldHeight; y++)
        for (int x = 0; x < worldWidth; x++)
            regel(x, y);

    for (int y = 0; y < worldHeight; y++)
        for (int x = 0; x < worldWidth; x++)
            currentworld[getIndexByCoord(x, y)] = nextgenworld[getIndexByCoord(x, y)];
}
