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
    int getIndexByCoord(int x, int y);

public:
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


// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);

    void print();
    void evolve();
};

#endif // CABASE_H
