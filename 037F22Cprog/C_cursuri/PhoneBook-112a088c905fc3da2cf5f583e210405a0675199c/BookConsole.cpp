#include "BookConsole.h"
#include "Book.h"
#include "Person.h"
#include "Friend.h"
#include "Family.h"
#include "Work.h"
using std::cout;
using std::endl;
using std::stoi;
using std::cin;

void BookConsole::showPrompt(){
    cout <<"Phone Book" << endl;
    cout << "1. Add person" << endl;
    cout << "2. Remove person" << endl;
	cout << "3. Print phone book" << endl;
}

//METHOD 설명 : FUNCTION ADD,REMOVE,PRINT와 관련된 user Input을 받는 함수
void BookConsole::mainProcess(Book* pb,string& input){
    int number = stoi(input);

    //(PERSON CLASS)입력 : PERSON,WORK,FAMILY,FRIEND 중 list에 저장할 class 정보 입력
	switch(number){
        case 1 :{
        	while(true){
        		selectType();
        		string typeInput;
        		cin >> typeInput;
        		//(PERSON CLASS)예외처리 : PERSON,WORK,FAMILY,FRIEND에 해당하는 1,2,3,4와 input이 다를 경우
        		if(typeInput.empty())
        			continue;
        		for(int i=0;i<typeInput.length();i++){
        			if(!std::isdigit(typeInput[i]))
        				continue;
        		}

        		if(typeInput.length()>1 || (typeInput[0]!='1' && typeInput[0]!='2' && typeInput[0]!='3' && typeInput[0]!='4'))
        		    continue;
        		int type = stoi(typeInput);
        		string information[4];
        		//(추가 정보)입력 : PERSON,WORK,FAMILY,FRIEND에 관한 정보 입력
        		getInformation(type,information);
        		//DB 정보 저장 : 입력받은 정보를 LIST에 최종 저장
        		pb->addInformation(type,information);
        		break;
        	}
			break;
        	}
        case 2 :{
        	//(REMOVE INDEX)입력 : LIST에서 제거할 사용자의 INDEX 입력
			string indexInput;
			int index = 0;
			bool invalid = true;
        		while(invalid){
				enterIndex();
				getline(cin,indexInput);
				//(INDEX)예외처리 : 숫자로 이루어지지 않은 INPUT
				if(indexInput.empty()){
					invalid = true;
					continue;
				}

				for(int i=0;i<indexInput.length();i++){
					if(!std::isdigit(indexInput[i])){
						invalid = true;
						break;
					}
					if(i==indexInput.length()-1)
						invalid = false;
				}
			}
        	index =stoi(indexInput);
            	//DB 정보 제거 : LIST로부터 해당 INDEX 정보 제거
		pb->removeInformation(index);
		break;
        	}
        case 3 :{
		personInfo();
		//DB 정보 출력 : LIST로부터 해당 정보 출력
		pb->print();
		break;
        	}
	}
}

void BookConsole::selectType(){
	cout << "Select type" << endl;
	cout << "1. Person" << endl;
	cout << "2. Work" << endl;
	cout << "3. Family" << endl;
	cout << "4. Friend" << endl;
	cout << "CP-2016-12345>";
}

//METHOD 설명 : NAME,PHONENUMBER,(TEAM,BIRTHDAY,AGE) 등 관련된 정보 입력받아 ARRAY에 저장
string* BookConsole::getInformation(int type, string information[]){
	//(NAME 정보)입력 : FIRSTNAME과 LASTNAME에 대한 정보 입력
	string input;
    bool invalid = true;
	while(invalid){
		cout << "Name: ";
		cin.ignore();
		getline(cin,input);
		if(input.empty()){
			invalid = true;
			continue;
		}
		//(잘못된 이름)예외처리 : alphabet과 ' '를 제외한 글자로 이루어진 input
		for(int i=0;i<input.length();i++){
			if(!std::isalpha(input[i]) && input[i]!=' '){
				invalid = true;
				break;
			}
			if(i==input.length()-1)
				invalid=false;
		}
	}
    size_t position = input.find_first_of(" ");
    string* name = new string[20];
    int j=0;
    int start = 0;
    int counter=0;
    while(position != string::npos){
        counter++;
        name[j++] = input.substr(start,static_cast<int>(position));
        start=static_cast<int>(position+1);
        position = input.find_first_of(" ",static_cast<int>(position+1));
    }
    name[j++] = input.substr(start,static_cast<int>(position));

    int nameSize = counter+1;
    //(이름)CASE1 : lastName이 부재 시
	if(nameSize==1){
		information[0] = name[0];
		information[1] = "No Last Name";
	}
	//(이름)CASE2 : lastName 존재 시 정보처리
	if(nameSize>=2){
		information[0] = name[0];
        string format;
        for(int i=1;i<nameSize;i++){
			format.append(name[i]);
			if(i==nameSize-1)
				continue;
			format.append(" ");
		}
		information[1] = format;
    }
    

	//(PHONENUMBER 정보)입력 : 02-XXXX-XXXX,010-XXXX-XXXX 형태 정보 입력받기
	string secInput;
	bool invalid2 = true;
	while(invalid2){
		cout << "Phone_number: ";
		getline(cin,secInput);
		if(secInput.length()!=12 && secInput.length()!=13){
			invalid2 = true;
			continue;
		}

		if(secInput.length()==12){
			string term1 = secInput.substr(0,2);
			char term2 = secInput[2];
			string term3 = secInput.substr(3,4);
			char term4= secInput[7];
			string term5 = secInput.substr(8);

			if(term1!="02" || term2!='-' || term4!='-'){
				invalid2 = true;
				continue;
			}

			for(int i=0;i<term3.length();i++){
				if(!std::isdigit(term3[i])){
					invalid2 = true;
					break;
				}
				if(i==term3.length()-1)
					invalid2=false;
			}
			if(invalid2==true)
				continue;

			for(int j=0;j<term5.length();j++){
				if(!std::isdigit(term5[j])){
					invalid2 = true;
					break;
				}
				if(j==term5.length()-1)
					invalid2=false;
			}

		}

		if(secInput.length()==13){
			string term1 = secInput.substr(0,3);
			char term2 = secInput[3];
			string term3 = secInput.substr(4,4);
			char term4= secInput[8];
			string term5 = secInput.substr(9);

			if(term1!="010" || term2!='-' || term4!='-'){
				invalid2 = true;
				continue;
			}

			for(int i=0;i<term3.length();i++){
				if(!std::isdigit(term3[i])){
					invalid2 = true;
					break;
				}
				if(i==term3.length()-1)
					invalid2=false;
			}
			if(invalid2==true)
				continue;

			for(int j=0;j<term5.length();j++){
				if(!std::isdigit(term5[j])){
					invalid2 = true;
					break;
				}
				if(j==term5.length()-1)
					invalid2=false;
			}
		}

	}
	//(PHONENUMBER 정보 변형)특수처리 : int형태로 저장하기 위해, "-"를 제외한 글자를 저장 준비
    string* number = new string[2];
    size_t position2 = secInput.find_first_of("-");
    size_t position3 = secInput.find_last_of("-");
    number[0] = secInput.substr(0,position2);
    number[1] = secInput.substr(position2+1,4);
    number[2] = secInput.substr(position3+1);

    string pNum;
	for(int i=0;i<3;i++){
		pNum.append(number[i]);
	}
	information[2] = pNum;
    
	//(WORK,FAMILY,FRIEND 정보)입력 : TEAM,BIRTHDAY,AGE 관련 정보 입력
	if(type==1){
		information[3]="No Information";
	}
	else if(type==2){
		string info;
		bool invalid = true;
		while(invalid){
			cout << "Team: ";
			getline(cin,info);
			//(TEAM 입력)예외처리 : team은 alphabet과 숫자로만 이루어지도록 예외처리
			for(int i=0;i<info.length();i++){
				if(!std::isalpha(info[i]) &&!std::isdigit(info[i])){
					invalid = true;
					break;
				}
				if(i==info.length()-1)
					invalid=false;
			}
		}
		information[3] = info;
	}
	else if(type==3){
		string info;
		bool invalid = true;
		while(invalid){
			cout << "Birthday: ";
			getline(cin,info);
			//(BIRTHDAY)예외처리 : YYMMDD가 아닐 경우 예외처리
			if(info.empty()){
				invalid = true;
				continue;
			}
			if(info.length()!=6){
				invalid = true;
				continue;
			}

			for(int i=0;i<info.length();i++){
				if(!std::isdigit(info[i])){
					invalid = true;
					break;
				}
				if(i==info.length()-1)
					invalid=false;
			}
			string monthS = info.substr(2,2);
			string dayS = info.substr(4);
			int month = stoi(monthS);
			int day =stoi(dayS);
			if((month>=1 && month<=12) && (day>=1 && day<=31))
				invalid=false;
			else
				invalid =true;
		}

        information[3] = info;
	}
	//(AGE)예외처리 : 나이는 150살 이상으로 input이 들어오면 예외처리
	else if(type==4){
		string info;
		bool invalid = true;
		while(invalid){
			cout << "Age: ";
			getline(cin,info);
			if(info.empty()){
				invalid = true;
				continue;
			}

			for(int i=0;i<info.length();i++){
				if(!std::isdigit(info[i])){
					invalid = true;
					break;
				}
				if(i==info.length()-1)
					invalid=false;
			}
			if(info.length()>3 || (info.length()==3 && info[0]!='1') || (info.length()==3 && info[0]=='1' && (info[1]!='0'&& info[1]!='1'&&info[1]!='2'&&info[1]!='3'&&info[1]!='4'))){
				invalid = true;
				continue;
			}

		}
		information[3]=info;
		}
    
    return information;
}

void BookConsole::enterIndex(){
	cout << "Enter index of person:";
}

void BookConsole::personInfo(){
	cout << "Phone Book Print" << endl;
}

