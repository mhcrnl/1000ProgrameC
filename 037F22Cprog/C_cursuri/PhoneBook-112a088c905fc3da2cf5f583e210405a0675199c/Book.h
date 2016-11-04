#ifndef BOOK_H_
#define BOOK_H_

#include "Person.h"
#include "Work.h"
#include "Family.h"
#include "Friend.h"
#include <iostream>
#include <vector>
#include <string>

class Book{
	private:
		std::vector<Person*> phoneBook;
	public:
		Book();
		void addInformation(int type, string* information);
		void removeInformation(int index);
		void print();
		void enroll(Person* person);
};

#endif /*HOMEWORK_BOOK_H */
