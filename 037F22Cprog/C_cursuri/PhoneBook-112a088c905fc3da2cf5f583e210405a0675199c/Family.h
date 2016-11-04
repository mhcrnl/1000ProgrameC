#ifndef Family_H_
#define Family_H_
#include "Person.h"

class Family : public Person{
	
	private:
		string birthday;
	public:
		Family(string& firstName, string& lastName, int& phoneNumber, string& birthday);
		void setBirthday(string& birthday);
		string getBirthday();
		int dDay();
		void print();
};

#endif /* HOMEWORK_Family_H_ */
