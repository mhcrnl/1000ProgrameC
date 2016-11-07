/**
	Author:		Mihai Cornel	Romania			mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                Fedora 23	    Code::Blocks 16.01	gcc 5.3.1
	Copyright:	@2016
	Problem:    Substringuri in c++;
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world! SUBstrings" << endl;
    /**
        Utilizarea functiei append() din <string>
    */
    string oldString = "continut";
    string noulString;
    noulString.append(oldString);
    noulString.append(3,'X');
    noulString.append(oldString, 3, 7);
    noulString.append(noulString);
    noulString.append("Acest string");
    oldString.append(noulString);

    cout << noulString << endl;
    cout << oldString << endl;
/**
    Utilizarea functiei push_back()
*/
    string pushString;
    for(char c ='A'; c<='Z'; c++)
        pushString.push_back(c);
    cout << pushString <<endl;

    string litereMici;
    for(char c ='a'; c<='z'; c++)
        litereMici.push_back(c);
    cout << litereMici + "A" + "B" <<endl;
/**
    Utilizarea functiei insert()
    */
    string intrebare = "Whyserious?", altCuvant ="monsoom";
    intrebare.insert(3,2,' ').insert(4,altCuvant,3,2);

    cout << intrebare << endl;
/**
    Utilizarea functiei assign
    */
    string stelute;
    stelute.assign(80,'*');

    cout << stelute <<endl;
/**
    Utilizarea functiei replace()
    */
    string unu = "Ma voi gandi la asta dupa o ora.";
    string doi = "astazi maine ieri";
    unu.replace(21, 10, doi, 0,6);

    cout <<unu << endl;
/**
    Utilizarea functiei erase()
    */
    string unde ="Cred ca suntem in Bucuresti pe undeva.";
    unde.erase(38,8).erase(27,10);

    cout << unde <<endl;
/**
    Utilizarea functiei swap()
    */
    string bautura = "Tuica";
    string suc ="CocaCola";
    stelute.assign(60, '@');
    cout<<stelute<<endl;
    cout << bautura << " . "<< suc<<endl;
    bautura.swap(suc);
    cout << bautura << " . "<< suc<<endl;

    return 0;
}
