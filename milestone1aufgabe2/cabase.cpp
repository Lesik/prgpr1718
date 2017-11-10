#include <iostream>
#include <cstdlib>
#include "CAbase.h"

using namespace std;

/*
 * Constructor – set
 */
CAbase::CAbase(int x, int y) { worldWidth = x; worldHeight = y; createWorld(); populateRandomly(); }

/*
 * Empty deconstructor
 */
CAbase::~CAbase() {}

int CAbase::getIndexByCoord(int x, int y) { return x + worldHeight * y; }

void CAbase::createWorld()
{
    currentworld = new bool[worldWidth * worldHeight];
    nextgenworld = new bool[worldWidth * worldHeight];
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
                currentworld[getIndexByCoord(x, y)] = false;
                nextgenworld[getIndexByCoord(x, y)] = false;
        }
    }
}

void CAbase::populateRandomly()
{
    for (int x = 0; x < worldWidth; x++) {
        for (int y = 0; y < worldHeight; y++) {
                currentworld[getIndexByCoord(x, y)] = rand() > (RAND_MAX / 2);
                nextgenworld[getIndexByCoord(x, y)] = rand() > (RAND_MAX / 2);
        }
    }
}

void CAbase::setSize(int x, int y) // Erstellt die Größe des Feldes
{
    // DON'T USE YET
    worldWidth = x;
    worldHeight = y;
}

void CAbase::setCell(int x, int y, bool wert) // Setzt wert auf Zelle (x,y)
{
    currentworld[x + worldHeight * y] = wert;
}

/*
 * Return true if element (x,y) is alive, false otherwise
 */
bool CAbase::getCell(int x, int y)
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
    if(getCell((x-1), (y-1))) {anzahlNachbar++;}
    if(getCell((x-1), y)) {anzahlNachbar++;}
    if(getCell((x-1), (y+1))) {anzahlNachbar++;}
    if(getCell((x), (y-1))) {anzahlNachbar++;}
    if(getCell((x), (y+1))) {anzahlNachbar++;}
    if(getCell((x+1), (y-1))) {anzahlNachbar++;}
    if(getCell((x+1), y)) {anzahlNachbar++;}
    if(getCell((x+1), (y+1))) {anzahlNachbar++;}

    return anzahlNachbar;
}

void CAbase::print()
{
    for (int i = 0; i < worldHeight; i++) {
        for (int k = 0; k < worldWidth; k++) {
            if (currentworld[getIndexByCoord(i, k)]) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void CAbase::regel(int x, int y) // Regel des Spiels
{
    int value = getCell(x, y);
    int neighbors = nachbar(x, y);
    if (value == true && neighbors < 2) {
        nextgenworld[x*y] = 0;
    }
    if (neighbors == 2 || neighbors == 3) {
        nextgenworld[x*y] = 1;
    }
    if (neighbors > 3) {
        nextgenworld[x*y] = 0;
    }
    if (value == false && neighbors == 3) {
        nextgenworld[x*y] = 1;
    }
}

void CAbase::evolve()
{
    for (int x = 0; x < worldHeight; x++)
        for (int y = 0; y < worldWidth; y++)
            regel(x, y);

    for (int x = 0; x < worldHeight; x++)
        for (int y = 0; y < worldWidth; y++)
            currentworld[getIndexByCoord(x, y)] = nextgenworld[getIndexByCoord(x, y)];
}
