#include "Person.h"
using std::cout;
using std::endl;

Person::Person(string& firstName, string& lastName, int& phoneNumber){
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
}

void Person::setFirstName(string& firstName){
	this->firstName = firstName;
}

string Person::getFirstName(){
	return firstName;
}

void Person::setLastName(string& lastName){
	this->lastName = lastName;
}

string Person::getLastName(){
	return lastName;
}

void Person::setPhoneNumber(int& phoneNumber){
	this->phoneNumber = phoneNumber;
}

int Person::getPhoneNumber(){
	return phoneNumber;
}
//METHOD 설명:int형태로 저장되어 있는 phoneNumber를 string형태로 변환해서 출력
string Person::printPhoneNumber(){
    string checkDigit = std::to_string(phoneNumber);
	string* term = new string[3];
	
	//CASE1 : '02'로 시작 시
    if(checkDigit.substr(0,1)=="2"){
		term[0] = checkDigit.substr(0,1);
		term[1] = checkDigit.substr(1,4);
		term[2] = checkDigit.substr(5,4);
	}
	
    //CASE2 : '010'으로 시작 시
	if(checkDigit.substr(0,2)=="10"){
		term[0] = checkDigit.substr(0,2);
		term[1] = checkDigit.substr(2,4);
		term[2] = checkDigit.substr(6,4);

	}	

	string format = "0";
	for(int i=0;i<3;i++){
		format.append(term[i]);
		if(i==2)
			break;
		format.append("-");

	}
	return format;
}


void Person::print(){
	if(getLastName()=="No Last Name")
		cout<<getFirstName() << "_";
	else
		cout<<getFirstName() << " " << getLastName() << "_";
	cout << printPhoneNumber() << endl;
}

