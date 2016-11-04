#include <iostream>
#include <string>
#include <deque>
#include <list>

using namespace std;

struct contact{
     //category(int i, const std::string& n): id(i), name(n) {}
    contact(const string& n, const string& p, const string& t) : nume(n), prenume(p), telefon(t){}
    string nume;
    string prenume;
    string telefon;
} ;



int main()
{
    cout << "Hello world!" << endl;
    // crearea containerului deque
    //std::deque<contact*> mydeque();
    contact contact1 = contact ("Mihai", "Cornel", "0722270796");

    list<contact> lista_contacte;

    // crearea conrtactului
    cout<< contact1.nume<<endl ;
    //contact.prenume = "Cornel";
    //contact.telefon = "0722270796";
   // std::deque<contact> mydeque();

    // adaugare contact in mudeque
    lista_contacte.push_front(contact1);
    for (list<contact>::iterator it =lista_contacte.begin(); it != lista_contacte.end(); ++it){
        std::cout <<' '<< contact1.nume<<' '<<contact1.prenume<<' '<<contact1.telefon;
    }

    return 0;
}
