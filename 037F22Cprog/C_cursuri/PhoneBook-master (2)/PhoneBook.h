#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "PhoneBookItem.h"
#include <string>
#include <iostream>

using namespace std;


class PhoneBook
{

    friend ostream& operator<<(ostream&,const PhoneBookItem&);
    friend ostream& operator<<(ostream&, const PhoneBook&);
public:
    PhoneBook();
    PhoneBook(const PhoneBook&);
    ~PhoneBook();

    PhoneBook& operator=(const PhoneBook&);

    bool IsEmpty() const;
    int Size() const;
    bool Insert(const string& name, int age, const string& phone);
    bool Delete(const string& name);
    bool Lookup(const string& name, int& age, string& phone) const;
    void Output();
    void Clear();

    //EXTRA
    int GetMaxAge();
    PhoneBook GetPeopleWithGivenAge(int age);
    PhoneBook GetAllPeopleWithMaxAge();


private:
    //void Clear();
    void Copy(const PhoneBook&);
    PhoneBookItem* m_head;
    int m_num;
    int length;
};


#endif // PHONEBOOK_H
