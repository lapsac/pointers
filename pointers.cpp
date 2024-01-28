#include <iostream>
#include <limits>
#include <string>
using namespace std;

    // Divdimensiju masiva izveide un ta vertibu ievade un izvade, kļūdu atpazīšana
    // ar row un col referencem, izmantojot "&" atgriež to vērtības nevis nokopē tās
int** divdimensijuMasivs(int& row, int& col) {
        //rindu skaita ievade izmantojot ciklu kas nepieciešams kļūdu apstrādei
    while (true) {
            //cout << "rows=";
        string rInp;
        cin >> rInp;

    try {
            // string ==> integer
        row = stoi(rInp);
            // Izeja no cikla, ja rindu simboli atbilst prasibam
        break;
            // Ja ne, tad kļūdu apstrāde ar exception metodi
        } catch (const invalid_argument& e) {
            cin.clear();
        }
    }

        //kolonnu skaita ievade izmantojot ciklu kas nepieciešams kļūdu apstrādei
    while (true) {
            // cout << "column=";
        string cInp;
        cin >> cInp;

        try {
                // string ==> integer
            col = stoi(cInp);
                // Izeja no cikla, ja kolonnu ievade ir derīga
            break;
        } catch (const invalid_argument& e) {
            cin.clear();
        }
    }

        // kolonnu reprezentacija 2D masīvam
    int** masivs = new int*[row];

    for (int i = 0; i < row; ++i) {
        masivs[i] = new int[col];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            while (true) {
                string elementInput;
                cin >> elementInput;

                try {
                    masivs[i][j] = stoi(elementInput);
                        // Izeja no cikla, ja ievade ir derīga:
                    break;
                } catch (const invalid_argument& e) {
                        // cout << "Nepareizi" << endl;
                    cin.clear();
                }
            }
        }
    }
    // atgriež rādītāju uz 2D masīvu
    return masivs;
}

int* mazakasVertibas(int** masivs, int row, int col) {

        // izveido 1D masīvu ar 'new' operatoru. Lielums tiek noteikts pēc 2d masīva col skaita.
    int* viendim = new int[col];

        // Cikls kurš iet cauri katrai 2d masīva kolonnai
    for (int j = 0; j < col; ++j) {
        int min = masivs[0][j];

        for (int i = 1; i < row; ++i) {
            if (masivs[i][j] < min) {
                min = masivs[i][j];
            }
        }
        viendim[j] = min;
    }
    return viendim;
}

    // viendimensiju masiva izveide
void viendimensijuMasivs(ostream& out, const int* viendim, int col) {
    out << "result: ";
    for (int j = 0; j < col; ++j) {
            // izvada elementus atdalitus ar atstarpem
        out << viendim[j] << " ";
    }
    out << endl;
}

// main funkcija galveno uzdevumu definesanai
int main() {

    int row, col;
    int** masivs = divdimensijuMasivs(row, col);
    int* viendim = mazakasVertibas(masivs, row, col);
        
    viendimensijuMasivs(cout, viendim, col);
    for (int i = 0; i < row; ++i) {
        delete[] masivs[i];
    }
    delete[] masivs;
    delete[] viendim;
    return 0;
}
