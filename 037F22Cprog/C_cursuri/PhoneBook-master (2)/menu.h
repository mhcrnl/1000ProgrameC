#ifndef MENU_H
#define MENU_H

#include "PhoneBook.h"

class Menu
{
public:
    Menu();
    Menu(PhoneBook*);
    void Add();
    void LookUp();
    void Delete();
    void GetLength();
    void PrintOut();


    //Extra--
    void GetMaxAge();

private:
    PhoneBook* pb;

};

#endif // MENU_H
