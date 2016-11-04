#include "Person.h"
#include "Family.h"
#include <ctime>
#include <time.h>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::istringstream;

Family::Family(string& firstName, string& lastName, int& phoneNumber, string& birthday)
	:Person(firstName,lastName,phoneNumber)
{
	this->birthday = birthday;
}

void Family::setBirthday(string& birthday){
	this->birthday = birthday;
}

string Family::getBirthday(){
	return birthday;
}

//METHOD 설명 : 생일과 오늘 날짜를 고려한 d-Day 계산하기
//**한달을 31일로 고정해서 계산, 일 년 총 372일로 산정**
int Family::dDay(){

	time_t now = time(0);
	tm *ltm = localtime(&now);
	int presentMonth = ltm->tm_mon+1;
	int presentDay = ltm->tm_mday;

	string month = birthday.substr(2,2);
	string day = birthday.substr(4,2);
	int birthMonth = std::stoi(month);
    int birthDay = std::stoi(day);
    int difference = 0;

    //CASE1 : 오늘 날짜와 birthday가 같은 경우
	if(birthMonth==presentMonth && birthDay==presentDay)
		difference=0;
	//CASE2 : birthday가 올해 아직 안 온 경우
	else if((birthMonth>presentMonth)||((birthMonth==presentMonth)&&(birthDay>presentDay))){
		difference = (birthMonth-presentMonth)*31+birthDay-presentDay;
	} 
	//CASE3 : birthday가 지나가고, 내년인 경우
	else{
		difference = 372 - ((presentMonth-birthMonth)*31 + presentDay - birthDay);
	}

	return difference;
}	


void Family::print(){
	if(getLastName()=="No Last Name")
		cout << getFirstName() << "_";
	else
		cout << getFirstName() << " " << getLastName() << "_";
	cout << printPhoneNumber() << "_";
	cout << getBirthday() << "_";
	cout << dDay() << endl;
}
