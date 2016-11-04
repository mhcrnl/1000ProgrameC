#include "PhoneBookItem.h"


PhoneBookItem::PhoneBookItem(const std::string& name, int age, const std::string& phone) : m_name(name), m_age(age), m_phone(phone), m_next(NULL)
{
}


