#ifndef CABASE_H
#define CABASE_H

class CAbase
{
private:
    int Nx, Ny;                 // Menmbervariable
    int* currentworld[30*30], nextgenworld[30*30];

public:
    CAbase(int x, int y); // Konstruktor
    ~CAbase(); // Destruktor

// Setter
    void setGroese(int x, int y);
    void setZelle(int x, int y);

// Getter
    int getNx();
    int getNy();
    bool getZelle(int x, int y);


// 'Spiel des Lebens' - Regeln / Methoden
    int nachbar(int x, int y);
    void regel(int x, int y);

    void Print();
    void Envolve();
};

#endif // CABASE_H
