#include "menu.h"
#include "PhoneBookItem.h"

Menu::Menu()
{
}

Menu::Menu(PhoneBook *phonebook){
    pb = phonebook;
}


void Menu::Add(){
    //Precondition: None.
    //Postcondition:
    //Adds person to phonebook.

    int age;
    string name;
    string phone;


    cout << "Enter name: ";
    getline(cin,name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter phone number: ";
    cin >> phone;

    pb->Insert(name,age,phone);
    cout << "\n";


}

void Menu::LookUp(){
    //Precondition: None.
    //Postcondition: Returns person's info
    //Accepts user input and calls PhoneBook::Lookup.

    PhoneBookItem temp;

    cout << "Enter name: ";
    getline(cin,temp.m_name);

    if(pb->Lookup(temp.m_name,temp.m_age,temp.m_phone))
    cout << "\n\nName: " << temp.m_name << " Age: " << temp.m_age << " Phone Number: " << temp.m_phone << "\n\n";
    else
        cout << "Person not found!\n\n";

}

void Menu::Delete(){
    //Precondition: None.
    //Postcondition: Person is deleted from phonebook.
    //Calls PhoneBook::Delete. If person is not found, output error message.

    string name;

    cout << "Enter name: ";
    getline(cin,name);

    if(pb->Delete(name))
        cout << "Entry for " << name << " has been deleted.\n\n";
    else
        cout << "Person not found!\n\n";

}

void Menu::PrintOut(){

    cout << "\n\n" << *pb;
    cout << "\n\n";

}

void Menu::GetLength(){
    //Returns size of Phonebook.

    cout << "Number of people in phonebook: " << pb->Size() << "\n\n";
}


//EXTRA

//void Menu::GetMaxAge(){

//    cout << "The maximum age in current Phonebook: ";
//    cout << pb->GetMaxAge() << "\n\n";
//}

