#include <iostream>
using namespace std;

int main() {

    double saldo = 1000.0;
    bool dziala = true;
    int wybor;
    double wyplata;
    double wplata;
    while (dziala) {
        cout << "=== MENU GLOWNE ===" << endl;
        cout << "1. Sprawdz saldo" << endl;
        cout << "2. Wplac pieniadze" << endl;
        cout << "3. Wyplac pieniadze" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                cout << "saldo wynosi: "<< saldo << endl;
                break;
            case 2:

                cout << "podaj kwote ktora chcesz wplacic: " << endl;
                cin >> wplata;
                saldo += wplata;
                cout << " Aktualna kwota: " << saldo << endl;
                break;
            case 3:
                cout << "Ile chcesz wyplacic?: " << endl;
                cin >> wyplata;

                if (wyplata > saldo) {
                    cout << "Brak takiej ilosci pieniedzy na konice!! aktualny stan gotowki: " << saldo << endl;
                    cout << "Sprobuj ponownie";
                }else {
                    saldo -= wyplata;
                    cout <<"Aktualne saldo wynosi: " << saldo << endl;
                }
                break;
            case 0:
            dziala = false;
                break;
            default:
                cout << "Nie poprawny numer sprobuj ponownie!!"<< endl;
                break;
        }
        if (dziala) {
            cout << "\nNacisnij Enter, aby powrocic do menu...";
            cin.ignore();
            cin.get();
        }

    }
}