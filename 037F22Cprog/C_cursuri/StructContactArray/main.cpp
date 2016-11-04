#include <iostream>
#include <string>
//#include <array>

using namespace std;

struct contact{
    contact(string& n, string& p, string& t):nume(n), prenume(p), telefon(t) {}
    string nume;
    string prenume;
    string telefon;
} contact;

/*
int adauga_contact(int sizeOfArray, struct contact* &contacte){

    contact* newContact = new contact[sizeOfArray + 1];

    for(int index=0; index<sizeOfArray; index++){
        newContact[index] = contacte[index];
    }

    cout << "\nIntroduce-ti numele: " ;
    getline(cin, newContact[index].nume);
    cout << "\nIntroduce-ti prenumele: " ;
    getLine(cin, newContact[index].prenume);
    cout << "\nIntroduce-ti numarul de telefon: " ;
    getline(cin, newContact[index].telefon);

    delete[] contacte;
    contacte = newContact;
    return sizeOfArray + 1;
}
*/
int main()
{
    cout << "Hello world!from StructContactArray;"  << endl;
    //contact contacte_array[3];

    int size_arr = 1;
    //contact *con = new contact[size_arr];
    //con[0].nume = "Mihai";
    //con[0].prenume = "Cornel";
    //con[0].telefon = "0722270796";
    //size_arr = adauga_contact(size_arr, con);

    for(int i=0; i<0; i++ ) {
        cout << "\nIntroduce-ti numele: " ;
        cin >> contact.nume ;
        cout << "\nIntroduce-ti prenumele: " ;
        cin >> contact.prenume ;
        cout << "\nIntroduce-ti numarul de telefon: " ;
        cin >> contact.telefon ;

    }
    return 0;
}
