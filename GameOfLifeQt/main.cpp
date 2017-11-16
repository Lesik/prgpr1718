#include <iostream>
#include <QApplication>

#include "CAbase.h"
#include "mainwindow.h"

using namespace std;

int qtgame(CAbase base, int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void consolegame(CAbase base) {
    bool end = false;
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

int main(int argc, char* argv[])
{
    CAbase base(30, 30);

    cout << "Press 0 for Qt interface or 1 for terminal interface." << endl;
    int input; cin >> input;
    switch (input) {
        case 0:
            qtgame(base, argc, argv); break;
        case 1:
            consolegame(base); break;
    }
    return 0;
}




