/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/
#ifndef CABASE_H
#define CABASE_H

#include "snake.h"

// Klasse CAbase wird definiert
class CAbase
{
private:
    int worldWidth, worldHeight;                 // Membervariable
    int* currentworld;
    int* nextgenworld;
    //void generate();
    int getIndexByCoord(int x, int y);
    int currentX;
    int currentY;

public:
    // Konstruktoren
    CAbase();
    CAbase(int x, int y);
    // Destruktor
    ~CAbase(); // Destruktor

// Setter
    void setSize(int x, int y);
    void setCell(int x, int y, int wert);
    void setCell_next(int x, int y, int wert);

// Getter
    int getNx();
    int getNy();
    int getCell(int x, int y);

// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);
    void clicked(int x, int y);

    void generate();
    void print();
    void evolve();
};

#endif // CABASE_H
