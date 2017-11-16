#include <iostream>

#include "CAbase.h"

using namespace std;

// Startmenü
void Start(bool end) {
    CAbase base(30, 30);

    do {
        base.print();
        const char *functions[] = {"Exit", "Evolve", "Set alive cell", "Reprint", "Resize", "Run tests"};

        for (int i = 0; i < 6; i++)
            cout << i << ". " << functions[i] << endl;

        int zahl, x, y;
        cin >> zahl;
        switch (zahl) {
            case 0 : end = 1; break;
            case 1 : base.evolve(); break;
            case 2 :
                cout << "Feld angeben, Reihe dann Spalte(1 bis n): " << endl;
                cin >> x >> y;
                if (x < base.getNx() && y < base.getNy()) {
                    base.changeCurrent(x - 1, y - 1, 1);
                }
                else {
                    cout << "Falsche Eingabe!" << endl;
                }
                break;
            case 3 : base.print(); break;
            case 4 :
                cout << "Groeße angeben (min. 3): " << endl;
                cin >> x >> y;
                if (x < 3 || y < 3) {
                    cout << "Falsche Eingabe!" << endl;
                }
                else {
                    base.setSize(x, y);
                }
                break;
            case 5:
                cout << "Running automated tests..." << endl;

        }
    } while (end == false);
}

int main()
{
    Start(false);
    return 0;
}




