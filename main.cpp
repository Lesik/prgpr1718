#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int A1[30][30];

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            A1[i][j] = rand() % 10;
            std::cout << A1[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    int k = 0;
    int l = 0;
    int* A2 = new int[30*30];
    for (int i = 0; i < 30*30; i++) {
        if (l % 30 == 0 && l != 0) {
            k = k + 1;
            l = 0; 
            cout << "\n";
        }
        A2[i] = A1[k][l];
        std::cout << A2[i] << " ";
        l = l + 1;
    }

    bool end = 0;
    int auswahl;

    do {
        int k = 0;
        int l = 0;
        cout << "\n 0. Exit\n 1. Change Cell\n 2. Reprint\n";
        cin >> auswahl;

        switch(auswahl){

            case 0:
                end = 1;
                break;
            case 1:
                for (int i = 0; i < 30; i++) {
                    for (int j = 0; j < 30; j++) {
                        A1[i][j] = rand() % 10;
                    };
                };
                break;
            case 2:
                for (int i = 0; i < 30*30; i++) {
                    if (l % 30 == 0 && l != 0) {
                        k = k + 1;
                        l = 0;
                        cout << "\n";
                    }
                    A2[i] = A1[k][l];
                    std::cout << A2[i] << " ";
                    l = l + 1;
                };
                break;
            default: cout << "Falsche Eingabe!";
    	}

    } while (end == 0);
}
