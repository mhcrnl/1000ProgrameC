#ifndef WORK_H_
#define WORK_H_
#include "Person.h"

class Work: public Person{
	private:
		string team;
	public:
		Work(string& firstName, string& lastName, int& phoneNumber, string& team);
		void setTeam(string& team);
		string getTeam();
		void print();

};

#endif /* HOMEWORK_WORK_H_ */
