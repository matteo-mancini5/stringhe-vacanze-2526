#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


const string PAROLA = "informatica";


char generaPrimoElemento() {
    char c = toupper(PAROLA.at(3));

    // strategia: se vocale o numero uso Z
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 'Z';
    else
        return c;
}


char generaSecondoElemento() {
    char c;
    do {
        c = char(rand() % 26 + 65); 
    } while (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    return c;
}


int generaNumero() {
    return rand() % 9 + 1;
}


char generaLetteraFinale() {
    return char(rand() % 26 + 65);
}


string numeriInX(string targa) {
    for (int i = 0; i < targa.length(); i++) {
        if (targa.at(i) >= '0' && targa.at(i) <= '9')
            targa.at(i) = 'X';
    }
    return targa;
}


string inverti(string targa) {
    int i = 0, f = targa.length() - 1;
    char temp;

    while (i < f) {
        temp = targa.at(i);
        targa.at(i) = targa.at(f);
        targa.at(f) = temp;
        i++;
        f--;
    }
    return targa;
}


bool presenzaNumero(string targa, int num) {
    string s = to_string(num);
    return targa.find(s) != -1;
}

int main() {
    srand(time(NULL));

    string targa = "";
    int scelta, num;

    targa.append(1, generaPrimoElemento());
    targa.append(1, generaSecondoElemento());

    for (int i = 0; i < 3; i++)
        targa.append(to_string(generaNumero()));

    for (int i = 0; i < 2; i++)
        targa.append(1, generaLetteraFinale());

    cout << "Targa generata: " << targa << endl;

    do {
        cout << "\n--- MENU ---";
        cout << "1) Sostituisci numeri con X"<<endl;
        cout << "2) Inverti targa"<<endl;
        cout << "3) Cerca numero"<<endl;
        cout << "0) Esci"<<endl;
        cout << "Scelta: ";
        cin >> scelta;

        if (scelta == 1)
            cout << numeriInX(targa) << endl;
        else if (scelta == 2)
            cout << inverti(targa) << endl;
        else if (scelta == 3) {
            cout << "Inserisci numero: ";
            cin >> num;
           if (presenzaNumero(targa, num) == true)
           cout << "Presente" << endl;
        else
           cout << "Non presente" << endl;
        }

    } while (scelta != 0);

    return 0;
}

