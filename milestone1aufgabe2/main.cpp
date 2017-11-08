#include <iostream>

#include "CAbase.h"

using namespace std;

// Startmenü
void Start(bool ende) {
    CAbase base(30, 30);
    do {
        cout << "0. Exit" << endl;
        cout << "1. Envolve" << endl;
        cout << "2. Set alive cell" << endl;
        cout << "3. Reprint" << endl;
        cout << "4. Resize" << endl;

        int zahl, x, y;
        cin >> zahl;
        switch (zahl) {
            case 0 : ende = 1; break;
            case 1 : base.Envolve(); break;
            case 2 : cout << "Feld angeben: " << endl; cin >> x >> y; base.setZelle(x,y); break;
            case 3 : base.Print(); break;
            case 4 : cout << "Größe angeben: " << endl; cin >> x >> y; base.setGroese(x,y); break;
        }
    } while (ende == 0);
}

int main()
{
    Start(0);
    return 0;
}




