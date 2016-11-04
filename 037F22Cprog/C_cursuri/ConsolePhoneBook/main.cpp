#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//http://stackoverflow.com/questions/7911919/sorting-array-from-typedef-struct-in-c
using namespace std;

struct Contact {
    char nume[30];
    char prenume[30];
    char telefon[30];
};
int counter =0;

void meniu(){
    //system("Color 10");
    cout << "*****************MENIU APLICATIE ********************"<<endl;
    cout << "**             A. Adauga contact.                  **"<<endl;
    cout << "**             Q. Inchide aplicatia                **"<<endl;
}

void AddEntry(Contact contacte[]){
    counter++;
    printf("\n Nume: ");
    scanf("%s", contacte[counter-1].nume);
    printf("\n Prenume: ");
    scanf("%s", contacte[counter-1].prenume);
    printf("\n Numar telefon: ");
    scanf("%s", contacte[counter-1].telefon);
    printf("\n Contactul %s a fost adaugat.", contacte[counter-1].nume);
}

int main()
{
    cout << "Hello world! From ConsolePhoneBook Application "  << endl;
    Contact contacte[40];
    char userChoise;
    while(userChoise != 'Q') {
        meniu();
        scanf("%s", &userChoise);
        if(userChoise == 'A'){
            AddEntry(contacte);
        }
        if(userChoise == 'Q'){
            cout << "Aplicatia se va inchide! "<<endl;
        }
    }

    return 0;
}
