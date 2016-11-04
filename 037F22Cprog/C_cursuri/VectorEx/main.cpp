#include <iostream>
#include <vector>

using namespace std;

struct Contact {
    char nume[10];
    char prenume[10];
    char telefon[12];
} contacte;

void Insert(vector<Contact> vectorContacte){

    int control;
    Contact con;

    cout << "Vă rugăm să introduce-ți datele cerute (0 pt. inchiderea aplicatiei): ";
        do {
        cout << "Introduce-ți numele: ";
        cin  >> con.nume;
        cout << "Introduce-ți prenumele: ";
        cin  >> con.prenume;
        cout << "Introduce-ți numarul de telefon: ";
        cin  >> con.telefon;
        vectorContacte.push_back(con);
        cout << "Vectorul contine: " << int(vectorContacte.size()) << " elemente.\n";

        cout << "Daca nu mai adaugati contacte introduceti 0 ENTER. ";
        cin  >> control;
    } while(control);
}

int main()
{
    cout << "Hello world!" << endl;
    int myint;
    vector<Contact> vectorContacte;
    Contact con;
    Insert(vectorContacte);

    cout << "Va rugam sa introduceti datele cerute( 0 pt. inchiderea aplicatiei): ";
    do {
        cout << "Introduce-ti numele: ";
        cin  >> con.nume;
        cout << "Introduce-ti prenumel: ";
        cin  >> con.prenume;
        cout << "Introduce-ti numarul de telefon: ";
        cin  >> con.telefon;
        cout << "Introduce-ti 0 pt. inchidere: ";
        cin  >> myint;
        vectorContacte.push_back(con);
        cout<< "Vectorul contine: "<< int(vectorContacte.size())<<" elemente.\n";

    } while (myint);
    return 0;
}
