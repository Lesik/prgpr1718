#include <iostream>
#include <cstdlib>
#include "CAbase.h"

using namespace std;

/*
 * Constructor – set
 */
CAbase::CAbase() : CAbase(30, 30) {}
CAbase::CAbase(int x, int y) { worldWidth = x; worldHeight = y; createWorld(); }

/*
 * Empty deconstructor
 */
CAbase::~CAbase() {}

int CAbase::getIndexByCoord(int x, int y) { return x + worldHeight * y; }

void CAbase::setSize(int x, int y) // Erstellt die Größe des Feldes
{
    // DON'T USE YET
    worldWidth = x;
    worldHeight = y;
    delete[] currentworld;
    delete [] nextgenworld;
    createWorld();
}

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

void CAbase::setCurrent(int x, int y) { CAbase::changeCurrent(x, y, true); }
void CAbase::setNextgen(int x, int y) { CAbase::changeNextgen(x, y, true); }
void CAbase::unsetCurrent(int x, int y) { CAbase::changeCurrent(x, y, false); }
void CAbase::unsetNextgen(int x, int y) { CAbase::changeNextgen(x, y, false); }
void CAbase::changeCurrent(int x, int y, bool wert) { currentworld[getIndexByCoord(x, y)] = wert; }
void CAbase::changeNextgen(int x, int y, bool wert) { nextgenworld[getIndexByCoord(x, y)] = wert; }

/*
 * Return true if element (x,y) is alive, false otherwise
 */
bool CAbase::getCell(int x, int y) { return currentworld[getIndexByCoord(x, y)]; }
int CAbase::getNx() { return worldWidth; }
int CAbase::getNy() { return worldHeight; }

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
        return (getCell(x - 1, 0) + getCell(x - 1,  1) + getCell(x, 1) + getCell(x + 1, 1)
               + getCell(x + 1, 0) + getCell(x - 1, getNy() - 1) + getCell(x, getNy() - 1) + getCell(x + 1, getNy() - 1));
    }
    //letzte reihe
    else if (y == getNy() - 1) {
        return (getCell(x - 1, y - 1) + getCell(x, y - 1) + getCell(x + 1, y - 1) + getCell(x - 1, y)
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
               + getCell(x - 1, y + 1) + getCell(0, y - 1) + getCell(0, y) + getCell(0, y + 1));
    }
    //rest
    else {
        return (getCell(x - 1, y - 1) + getCell(x - 1, y) + getCell(x - 1, y + 1) + getCell(x, y - 1)
               + getCell(x, y + 1) + getCell(x + 1, y - 1) + getCell(x + 1, y) + getCell(x + 1, y + 1));
    }
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
                setNextgen(x, y);
                break;
            case 3:
                setNextgen(x, y);
                break;
            default:
                unsetNextgen(x, y);
        }
    }
     else {
        if (nachbar(x, y) == 3) setNextgen(x, y);
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

bool CAbase::runTests() {
    int changes = 12;
    int changesX[changes] = {0, 29, 0, 0, 0, 4, 5, 6, 12, 12, 13, 13};
    int changesY[changes] = {0, 29, 3, 4, 5, 6, 4, 4, 12, 13, 12, 13};
    for (int i = 0; i < changes; i++) {
        setCurrent(changesX[i], changesY[i]);
    }
    CAbase::print();
    CAbase::evolve();
    CAbase::print();
    return true;
}
