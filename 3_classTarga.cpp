#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string PAROLA = "informatica"; 

class TargaCasuale {
public:
    string targa;

    void generaTarga() {
        targa = ""; 
        targa.append(1, generaPrimoElemento());
        targa.append(1, generaSecondoElemento());

        for (int i = 0; i < 3; i++)
            targa.append(to_string(generaNumero()));

        for (int i = 0; i < 2; i++)
            targa.append(1, generaLetteraFinale());
    }

  
    string sostituisciNumeri() {
        string nuova = targa; 
        for (int i = 0; i < nuova.length(); i++) {
            if (nuova.at(i) >= '0' && nuova.at(i) <= '9')
                nuova.at(i) = 'X';
        }
        return nuova;
    }

    string invertiTarga() {
        string nuova = targa;
        int i = 0, f = nuova.length() - 1;
        while (i < f) {
            char temp = nuova.at(i);
            nuova.at(i) = nuova.at(f);
            nuova.at(f) = temp;
            i++;
            f--;
        }
        return nuova;
    }

    bool presenzaNumero(int num) {
        string s = to_string(num);       
        return targa.find(s) != -1;      
    }

  
    char generaPrimoElemento() {
        char c = toupper(PAROLA.at(3));
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
};


int main() {
    srand(time(NULL)); 

    TargaCasuale t;
    t.generaTarga(); 

    cout << "Targa generata: " << t.targa << endl;

    cout << "Targa con numeri sostituiti da X: " << t.sostituisciNumeri() << endl;
    cout << "Targa invertita: " << t.invertiTarga() << endl;

    int num;
    cout << "Inserisci numero da cercare nella targa: ";
    cin >> num;

    if (t.presenzaNumero(num))
        cout << "Numero presente" << endl;
    else
        cout << "Numero non presente" << endl;

    return 0;
}
