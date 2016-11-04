#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
using std::string;

class Person{
	private:
        string firstName;
		string lastName;
		int phoneNumber;

	public:
		Person(string& firstName, string& lastName,int& phoneNumber);
		void setFirstName(string& firstName);
		string getFirstName();
		void setLastName(string& lastName);
		string getLastName();
		void setPhoneNumber(int& phoneNumber);
		int getPhoneNumber();
		string printPhoneNumber();
		virtual void print();
};

#endif /* HOMEWORK_PERSON_H_ */
