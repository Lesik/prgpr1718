/*
    Javi (), Lesik (6082200), Kelvin Tsang (5428328)
*/

#ifndef CABASE_H
#define CABASE_H

// Klasse CAbase wird definiert
class CAbase
{
private:
    enum GameType { Snake, GameOfLife };
    GameType game;
    int worldWidth, worldHeight;                 // Membervariable
    int* currentworld;
    int* nextgenworld;
    void changeGame(int index);
    void generate();
    int getIndexByCoord(int x, int y);

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
    int* getCurrentWorld();
    int* getNextGenWorld();

// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);

    void print();
    void evolve();

    void onUp();
    void onLeft();
    void onDown();
    void onRight();
};

#endif // CABASE_H
