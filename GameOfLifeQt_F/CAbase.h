/*
    Fatih (), Javi (), Lesik (), Kelvin Tsang (5428328)

    Milestone 1

*/
#ifndef CABASE_H
#define CABASE_H

class CAbase
{
private:
    int worldWidth, worldHeight;                 // Menmbervariable
    int* currentworld;
    int* nextgenworld;
    void createWorld();
    void populateRandomly();
    void populate_test();
    int getIndexByCoord(int x, int y);

public:
    CAbase();
    CAbase(int x, int y); // Konstruktor
    ~CAbase(); // Destruktor

// Setter
    void setSize(int x, int y);
    void setCell(int x, int y, int wert);
    void setCell_next(int x, int y, int wert);

// Getter
    int getNx();
    int getNy();
    int getCell(int x, int y);
    int* getCurrentWorld();
    int* getNextGenWorld();


// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);

    void print();
    void evolve();
};

#endif // CABASE_H
