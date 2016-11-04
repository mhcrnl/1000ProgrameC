#include "BookConsole.h"
#include "Book.h"
#include "Person.h"
#include "Work.h"
#include "Family.h"
#include "Friend.h"
#include <iostream>
#include <exception>

using std::cout;
using std::cin;
using std::endl;


int main(){
	Book* pb = new Book();
    string input;
    BookConsole procedure;
    while(true){
        cout << "CP-2016-12345>";
        getline(cin,input);

        if(input.empty()){
            procedure.showPrompt();
            continue;
        }

        if(input=="exit")
            break;

        //(Function)예외처리 : Add,remove,print에 해당하는 1,2,3과 input이 다를 경우
        for(int i=0;i<input.length();i++){
        	if(!std::isdigit(input[i]))
        		continue;
        }

        if(input.length()>1 || (input[0]!='1' && input[0]!='2' && input[0]!='3'))
        	continue;


        procedure.mainProcess(pb,input);
    }
    cout <<"Bye." << endl;
}

