#include <iostream>

#include "CAbase.h"

using namespace std;

// Startmenü
void Start(bool end) {
    CAbase base(30, 30);
    base.print();

    cout << endl << base.nachbar(12,12);

    do {
        const char *functions[] = {"Exit", "Evolve", "Set alive cell", "Reprint", "Resize"};

        for (int i = 0; i < 5; i++)
            cout << i << ". " << functions[i] << endl;

        int zahl, x, y;
        cin >> zahl;
        switch (zahl) {
            case 0 : end = 1; break;
            case 1 : base.evolve(); base.print(); break;
            case 2 : cout << "Feld angeben: " << endl; cin >> x >> y; base.setCell(x - 1, y - 1, 1); break;
            case 3 : base.print(); break;
            case 4 : cout << "Größe angeben: " << endl; cin >> x >> y; base.setSize(x, y); break;
        }
    } while (end == false);
}

int main()
{
    Start(false);
    return 0;
}




