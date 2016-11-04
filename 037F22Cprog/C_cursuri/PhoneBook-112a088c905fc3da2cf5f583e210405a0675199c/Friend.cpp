#include "Person.h"
#include "Friend.h"
using std::cout;
using std::endl;

Friend::Friend(string& firstName, string& lastName, int& phoneNumber, int& age)
	:Person(firstName,lastName,phoneNumber)
{
	this->age = age;
}

void Friend::setAge(int& age){
	this->age=age;
}

int Friend::getAge(){
	return age;
}


void Friend::print(){
	if(getLastName()=="No Last Name")
		cout << getFirstName() << "_";
	else
		cout << getFirstName() << " " << getLastName() << "_";
	cout << printPhoneNumber() << "_";
	cout << getAge() << endl;
}




