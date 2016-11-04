#ifndef Friend_H_
#define Friend_H_
#include "Person.h"

class Friend : public Person{
	private:
		int age;
	public:
		Friend(string& firstName, string& lastName, int& phoneNumber, int& age);
		void setAge(int& age);
		int getAge();
		void print();
};

#endif /* HOMEWORK_Friend_H_ */
