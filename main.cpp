#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	// declare two-dimensional array
    int A1[30][30];

	// traverse through array
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
			// fill with random values
            A1[i][j] = rand() % 10;
			// and print them
            std::cout << A1[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    int k = 0;	// line counter
    int l = 0;	// position counter
	// create one-dimensional array
    int* A2 = new int[30 * 30];
    for (int i = 0; i < 30 * 30; i++) {
		// if we're at the end of a line
        if (l % 30 == 0 && l != 0) {
			// increment line counter
            k = k + 1;
			// reset position counter
            l = 0;
            cout << "\n";
        }
		// copy value from two-dimensional array
        A2[i] = A1[k][l];
        std::cout << A2[i] << " ";
		// increase position counter
        l = l + 1;
    }

    bool end = 0;
    int auswahl;

    do {
        int k = 0;
        int l = 0;
        cout << "\n 0. Exit\n 1. Change Cell\n 2. Reprint\n";
        cin >> auswahl;

        switch(auswahl) {

            case 0:
                end = 1;
                break;
            case 1:
				// same as above, too lazy to separate into function
                for (int i = 0; i < 30; i++) {
                    for (int j = 0; j < 30; j++) {
                        A1[i][j] = rand() % 10;
                    };
                };
                break;
            case 2:
				// same as above, too lazy to separate into function
                for (int i = 0; i < 30 * 30; i++) {
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
