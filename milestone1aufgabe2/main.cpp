#include <iostream>

#include "CAbase.h"

using namespace std;

// Startmenü
void Start(bool ende) {
    CAbase base(30, 30);
    do {
        const char *functions[] = {"Exit", "Evolve", "Set alive cell", "Reprint", "Resize"};

        for (int i = 0; i < 5; i++) {
            cout << i << ". " << functions[i] << endl;
        }

        int zahl, x, y;
        cin >> zahl;
        switch (zahl) {
            case 0 : ende = 1; break;
            case 1 : base.Envolve(); break;
            case 2 : cout << "Feld angeben: " << endl; cin >> x >> y; base.setZelle(x,y); break;
            case 3 : base.Print(); break;
            case 4 : cout << "Größe angeben: " << endl; cin >> x >> y; base.setGroese(x,y); break;
        }
    } while (ende == false);
}

int main()
{
    Start(false);
    return 0;
}




