#ifndef BOOKCONSOLE_H_
#define BOOKCONSOLE_H_
#include "Book.h"
#include "Person.h"
#include "Work.h"
#include "Family.h"
#include "Friend.h"

class BookConsole{
	public:
		void showPrompt();
		void mainProcess(Book* pb,string& input);
		void selectType();
        string* getInformation(int type,string* information);
		void enterIndex();
		void personInfo();
};




#endif /* BOOKCONSOLE_H_ */
