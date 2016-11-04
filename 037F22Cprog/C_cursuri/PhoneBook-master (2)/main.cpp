#include "menu.h"
#include "PhoneBook.h"
#include "PhoneBookItem.h"
#include <iostream>


using namespace std;


int main()
{
    //int *p123 = new int;

    PhoneBook yellowPages;

    cout << "Inserting: " << endl;
    yellowPages.Insert("Mr. Mead",10,"911");
    yellowPages.Insert("Alpha",10,"112");
    yellowPages.Insert("Saxton Hale",40,"1-888-222-2222");
    yellowPages.Insert("Gabe Newell",100,"1-444-444-4444");
    yellowPages.Insert("Pyro",29,"1-234-567-8901");

    cout << "Original list: " << endl;
    cout << yellowPages << endl;

    //Test copy ctor

    PhoneBook blueBook(yellowPages);
    cout << "List after copy ctor: " << endl;
    cout << blueBook << endl;

    //Test operator =
    PhoneBook whiteBook;
    whiteBook = yellowPages;

    cout << "List after operator=: " << endl;
    cout << whiteBook << endl;


    cout << "Get Max Age: ";
    cout << yellowPages.GetMaxAge() << endl;

    cout << "Get All People With Certain Age: " << endl;
    cout << yellowPages.GetPeopleWithGivenAge(29);

    cout << "Get All People With Maximum Age: " << endl;
    cout << yellowPages.GetAllPeopleWithMaxAge() << endl;


    //Pause
    cin.get();

    Menu menu(&yellowPages);
    int choice;
    bool done = false;
    while(!done){
        cout << "Select an option: \n";
        cout << "[1] Add a person\n";
        cout << "[2] Lookup a person\n";
        cout << "[3] Delete a person\n";
        cout << "[4] Print out Phonebook\n";
        cout << "[5] Get # of persons in phonebook\n";
        cout << "[6] Exit\n";
        cin >> choice;
        cin.ignore(50,'\n');

        switch(choice){

        case 1:
            menu.Add();
            break;
        case 2:
            menu.LookUp();
            break;
        case 3:
            menu.Delete();
            break;
        case 4:
            menu.PrintOut();
            break;
        case 5:
            menu.GetLength();
            break;
        case 6:{
            done = true;
            break;
        }
        default:
            break;
        }

    }


    return 0;
}

