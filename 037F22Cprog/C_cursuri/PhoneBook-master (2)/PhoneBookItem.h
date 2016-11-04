#ifndef PHONEBOOKITEM_H
#define PHONEBOOKITEM_H

#include <string>

struct PhoneBookItem{
    std::string m_name;
    int m_age;
    std::string m_phone;

    PhoneBookItem* m_next;
    PhoneBookItem(){}
    PhoneBookItem(const std::string& name, int age, const std::string& phone);
};

#endif // PHONEBOOKITEM_H
