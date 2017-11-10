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
                nextgenworld[getIndexByCoord(x, y)] = rand() % 2;
        }
    }
}

void CAbase::setSize(int x, int y) // Erstellt die Größe des Feldes
{
    // DON'T USE YET
    worldWidth = x;
    worldHeight = y;
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
    if (x == 0 && y == 0) {
        return (getCell(0, 1) + getCell(1, 1) + getCell(1, 0) + getCell(1, getNy() - 1)
                + getCell(0, getNy() - 1) + getCell(getNx() - 1, 0) + getCell(getNx() - 1, 1)
                + getCell(getNx() - 1, getNy() - 1));
    }
    //rechts oben
    else if (x == getNx() - 1 && y == 0) {
        return (getCell(x, 1) + getCell(x - 1, 1) + getCell(x, 0) + getCell(x - 1, getNy() - 1)
                + getCell(x, getNy() - 1) + getCell(0, getNy() - 1) + getCell(0, 0) + getCell(0, 1));
    }
    //links unten
    else if (x == 0 && y == getNy() - 1) {
        return (getCell(0, y - 1) + getCell(1, y - 1) + getCell(1, y)
                + getCell(1, 0) + getCell(0, 0) + getCell(getNx() - 1, 0) + getCell(getNx() - 1, y)
                + getCell(getNx() - 1, y - 1));
    }
    //rechts unten
    else if (x == getNx() - 1 && y == getNy() - 1) {
        return (getCell(x, y - 1) + getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, 0) + getCell(x - 1, 0)
                + getCell(0, 0) + getCell(0, y) + getCell(0, y - 1));
    }
    //erste reihe
    else if (y == 0) {
        return (getCell(x - 1, 0) + getCell(x - 1,  1) + getCell(x, y + 1) + getCell(x + 1, 1)
               + getCell(x + 1, 0) + getCell(x - 1, getNy() - 1) + getCell(x, getNy() - 1) + getCell(x + 1, getNy() - 1));
    }
    //letzte reihe
    else if (y == getNy() - 1) {
        return (getCell(x - 1, y - 1) + getCell(x, y - 1) + getCell(x, y - 1) + getCell(x - 1, y)
               + getCell(x + 1, y) + getCell(x - 1, 0) + getCell(x, 0) + getCell(x + 1, 0));
    }
    //erste spalte
    else if (x == 0) {
        return (getCell(0, y - 1) + getCell(0, y + 1) + getCell(1, y - 1) + getCell(1, y)
               + getCell(1, y + 1) + getCell(getNx() - 1, y - 1) + getCell(getNx() - 1, y) + getCell(getNx() - 1, y + 1));
    }
    //letzte spalte
    else if (x == getNx() - 1) {
        return (getCell(x, y - 1) + getCell(x, y + 1) + getCell(x - 1, y - 1) + getCell(x - 1,  y)
               + getCell(x + 1, y + 1) + getCell(0, y - 1) + getCell(0, y) + getCell(0, y + 1));
    }
    //rest
    else {
        return (getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1)
               + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1));
    }
}

void CAbase::print() {
    for (int i = 0; i < worldHeight; i++) {
        for (int k = 0; k < worldWidth; k++) {
            if (currentworld[getIndexByCoord(i, k)] == 1) {
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

void CAbase::evolve()
{
    for (int x = 0; x < worldHeight; x++)
        for (int y = 0; y < worldWidth; y++)
            regel(x, y);

    for (int x = 0; x < worldHeight; x++)
        for (int y = 0; y < worldWidth; y++)
            currentworld[getIndexByCoord(x, y)] = nextgenworld[getIndexByCoord(x, y)];
}
