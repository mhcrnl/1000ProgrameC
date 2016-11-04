#include "Person.h"
#include "Work.h"
using std::cout;
using std::endl;

Work::Work(string& firstName, string& lastName, int& phoneNumber, string& team)
	: Person(firstName,lastName,phoneNumber)
{
	this->team = team;
}


void Work::setTeam(string& team){
	this->team = team;
}

string Work::getTeam(){
    return team;
}

void Work::print(){
	if(getLastName()=="No Last Name")
		cout << getFirstName() << "_";
	else
		cout << getFirstName() << " " << getLastName() << "_";
	cout << printPhoneNumber() << "_";
	cout << getTeam() << endl;

}





