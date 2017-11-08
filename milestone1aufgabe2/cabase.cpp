#include <iostream>
#include "CAbase.h"

using namespace std;

CAbase::CAbase(int x, int y) // Initialisiere Spiel
{
    Nx = x; Ny = y;
    for (int i=0; i<x*y; i++) {
        currentworld[i] = 0;
        nextgenworld[i] = 0;
    }
}

CAbase::~CAbase()
{
    // empty deconstructor
}


// Setter & Getter - Methoden

void CAbase::setGroese(int x, int y) // Erstellt die Größe des Feldes
{
    Nx = x;
    Ny = y;
}

void CAbase::setZelle(int x, int y) // Setzt lebende Zelle auf Feld (x,y)
{
    *currentworld[x*y] = 1;
}

int CAbase::getNx() //
{
    return Nx;
}

int CAbase::getNy() //
{
    return Ny;
}

bool CAbase::getZelle(int x, int y) // Gibt den aktuellen Zustand von Feld (x,y)
{
    return currentworld[x*y];
}

int CAbase::nachbar(int x, int y) // Zählt die Anzahl der Nachbarn vom Feld (x,y)
{
    int AnzNachbar = 0;
    if(*currentworld[(x-1)*(y-1)]==1) {AnzNachbar++;}
    if(*currentworld[(x-1)*(y)]==1) {AnzNachbar++;}
    if(*currentworld[(x-1)*(y+1)]==1) {AnzNachbar++;}
    if(*currentworld[(x)*(y-1)]==1) {AnzNachbar++;}
    if(*currentworld[(x)*(y+1)]==1) {AnzNachbar++;}
    if(*currentworld[(x+1)*(y-1)]==1) {AnzNachbar++;}
    if(*currentworld[(x+1)*(y)]==1) {AnzNachbar++;}
    if(*currentworld[(x+1)*(y+1)]==1) {AnzNachbar++;}

    return AnzNachbar;
}

void CAbase::regel(int x, int y) // Regel von des Spiels
{
    if (CAbase::getZelle(x,y) == 1 && CAbase::nachbar(x,y) < 2) {
        nextgenworld[x*y] = 0;
    }
    if (CAbase::nachbar(x,y) == 2 || CAbase::nachbar(x,y) == 3) {
        nextgenworld[x*y] = 1;
    }
    if (CAbase::nachbar(x,y) > 3) {
        nextgenworld[x*y] = 0;
    }
    if (CAbase::getZelle(x,y) == 0 && CAbase::nachbar(x,y) == 3) {
        nextgenworld[x*y] = 1;
    }
}


void CAbase::Print()
{
    for (int i=0; i< Nx; i++) {
        for (int k=0; k<Ny; k++) {
            if (i==0 || i==Nx-1 || k==0) {
                cout << " . ";
            }
            if(*currentworld[Nx*Ny] == 1) {
                cout << " * ";
            }
            else {
                cout << "   ";
            }
            if (k==Ny-1) {
                cout << "." << endl;
            }
        }
    }
    cout << endl;
}

void CAbase::Envolve()
{
    for (int i=0; i<Nx; i++) {
        for(int j=0; j<Ny; j++) {
            CAbase::regel(i, j);
        }
    }
    for (int k=0; k<Nx*Ny; k++) {
        //*A1[k] = *A2[k];
    }
}
