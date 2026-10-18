#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {

    int pPin = 2005;
    int wprowadzonyPin;
    int probyPin = 0;
    bool zalogowano = false;
    double saldo = 1000.0;
    bool dziala = true;
    int wybor;
    double wyplata;
    double wplata;
    vector<string> historia;


    while (!zalogowano && probyPin < 3) {
        cout << "Wprowadz pin: " << endl;
        cin >> wprowadzonyPin;
        if (wprowadzonyPin == pPin) {
            zalogowano = true;
            cout << "Pin poprawny zapraszamy!"<< endl;
        }else {
            probyPin = probyPin + 1;
            cout << "Nie poprawny pin!! sprobuj ponownie: " << endl;
            cout << "Pozostale proby: " << 3 - probyPin << endl;
        }
        }
    if (!zalogowano) {
        cout << "Karta zablokowana!!"<< endl;
        return 0;
    }

    while (dziala) {
        cout << "=== MENU GLOWNE ===" << endl;
        cout << "1. Sprawdz saldo" << endl;
        cout << "2. Wplac pieniadze" << endl;
        cout << "3. Wyplac pieniadze" << endl;
        cout << "4.Historia Tranzakcji"<< endl;
        cout << "5.Zmiana pinu"<<endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                cout << "saldo wynosi: "<< saldo << endl;
                break;
            case 2: {
                cout << "podaj kwote ktora chcesz wplacic: " << endl;
                cin >> wplata;
                saldo += wplata;
                ostringstream stream;
                stream << fixed << setprecision(2) << wplata;
                historia.push_back("wplata : " + stream.str() + "zl");
                cout << " Aktualna kwota: " << saldo << endl;
                break;
            }
            case 3: {
                cout << "Ile chcesz wyplacic?: " << endl;
                cin >> wyplata;
                ostringstream streamWyplata;
                streamWyplata << fixed << setprecision(2) << wyplata;

                if (wyplata > saldo) {
                    cout << "Brak takiej ilosci pieniedzy na konice!! aktualny stan gotowki: " << saldo << endl;
                    cout << "Sprobuj ponownie";
                }else {
                    saldo -= wyplata;
                    historia.push_back("wyplata: " + streamWyplata.str() + " zl");
                    cout <<"Aktualne saldo wynosi: " << saldo << endl;
                }
                break;
            }
            case 4:
                if (historia.empty()) {
                    cout << "Brak tranzakcji zapisanych w historii!"<<endl;
                }else {
                    for(string wpis : historia ) {
                        cout << wpis << endl;
                    }
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