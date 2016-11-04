#include "Book.h"
using std::cout;
using std::endl;
using std::vector;


Book::Book(){
    vector<Person*> phoneBook;
}

void Book::addInformation(int type, string information[]){
    int phoneNumber = std::stoi(information[2]);
    
	if(type==1){
        Person* person = new Person(information[0],information[1],phoneNumber);
        enroll(person);
	}

	else if(type==2){
		Work* work = new Work(information[0],information[1],phoneNumber,information[3]);
		enroll(work);
	}

	else if(type==3){
		Family* family = new Family(information[0],information[1],phoneNumber,information[3]);
		enroll(family);
	}

	else{
        int age = std::stoi(information[3]);
		Friend* mate = new Friend(information[0],information[1],phoneNumber,age);
		enroll(mate);
	}
    
	cout << "Successfully added new person" << endl;
}

void Book::removeInformation(int index){

	if(phoneBook.end()<phoneBook.begin()+index)
		cout << "Person does not exist" << endl;
	else
		phoneBook.erase(phoneBook.begin()+index);

}

void Book::print(){
	for(int i=0;i<phoneBook.size();i++){
		cout << (i+1) << ". ";
		phoneBook[i]->print();
	}
}

void Book::enroll(Person* person){
	phoneBook.push_back(person);
}
