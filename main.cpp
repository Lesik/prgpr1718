#include <iostream>
#include <stdlib.h>

using namespace std;

void HelloWorld () {
    cout << "Hello World!" << endl;
}

void Drucken (int x, int y) {
    int A1[x][y];

    for (int i=0; i<=x; ++i) {
        for (int k=0; k<=y; ++k ) {
           A1[i][k] = (rand () % 9)+1;
           cout << A1[i][k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //HelloWorld();

    int x, y; x = 30; y = 30;
    int A1[x][y];
    srand (time(NULL));

    for (int i=0; i<=x; ++i) {
        for (int k=0; k<=y; ++k ) {
           A1[i][k] = (rand () % 9)+1;
           //cout << A1[i][k] << " ";
        }
        //cout << endl;
    }

    int* A2 = new int [30*30];
    int k = 0; int l = 0;

    for (int i=0; i<= x*y; ++i) {
        //cout << k << endl;
        if (k != 0 && k % x == 0) {
           ++l; k = 0;
           cout << endl;
        }
        A2[i] = A1[k][l];
        cout << A2[i]<< " ";
        ++k;
    }

    bool ende = 0; int zahl;
    do {
       cout << "0. Exit" << endl;
       cout << "1. Change Cell" << endl;
       cout << "2. Reprint" << endl;

       cin >> zahl;
       switch (zahl) {
            case 0 : ende = 1; break;
            case 1 : cout << "Zellengröße x -> "; cin >> x; cout << "y ->"; cin >> y; break;
            case 2 : Drucken(x, y); break;
            //default: cout << "Falsch!!!" << endl;
            }
        } while (ende == 0);

    return 0;
}
