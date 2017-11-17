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
    CAbase();
    CAbase(int x, int y); // Konstruktor
    ~CAbase(); // Destruktor

// Setter
    void setSize(int x, int y);
    void setCurrent(int x, int y);
    void setNextgen(int x, int y);
    void unsetCurrent(int x, int y);
    void unsetNextgen(int x, int y);
    void invertCurrent(int x, int y);
    void changeCurrent(int x, int y, bool wert);
    void changeNextgen(int x, int y, bool wert);

// Getter
    int getNx();
    int getNy();
    bool getCell(int x, int y);


// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);

    void print();
    void evolve();

    bool runTests();
};

#endif // CABASE_H
