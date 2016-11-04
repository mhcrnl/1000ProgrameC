/**
    Acest program evidentiaza principiile programarii orientate pe obiecte
    PROGRAMAREA STRUCTURATA:
        1. analiza TOP-DOWN: problema de rezolvat este impartita in subprobleme
            relativ independente; fiecare subtproblema este analizata in acelasi mod;
        2. modularizarea: programul este impartit in mai multe sectiuni(denumite module,
             subprograme, proceduri sau functii), fiecare modul rezolvand o subproblema a
             problemei date( in concordanta cu analiza TOP-DOWN a problemei);
        3. codul structurat: fiecare modul consta in compunerea celor trei structuri de
            control fundamentale: secventiala, alternativa, repetitiva;
*/
#include <iostream>
#include <deque>

using namespace std;
/** Controlul accesului la membrii unei clase:
    public = membrul poate fi accesat din orice functiedin domeniul de declaratie al clasei;
    private = membrul poate fi accesat doar din functiile membre ala clasei, precum si functiile
        prietene(friend) ale clasei; DEFAULT
    protected = ca efect, este similar cu private, dar, in plus, accesul este permis si pentru functiile
        membre si functiile prietene ale claselor derivate din clasa respectiva*/
class Contact {
    public:
        string nume, prenume, telefon;
    public:
        //Constructori
        Contact();
        Contact(string);
        Contact(string, string);
        Contact(string, string, string);
        /** Destructor */
        ~Contact();
        //get/set functii
        string getNume(void);
        void setNume(string n);
        string getPrenume(void);
        void setPrenume(string p);
        string getTelefon(void);
        void setTelefon(string t);
        /** Copy constructor creaza un obiect care este initializat cu un obiect al aceleasi clase
            1. initializeaza un obiect din alt obiect al aceleasi clase
            2. copiaza un obiect pentru a fi pasat ca argument unei functii
            3. copiaza un obiect returnat dintr-o functie*/
        Contact(const Contact &con);
        /** Functiile friend au acces la toti membrii private si protected ai clasei */
        friend void print(Contact con);
        friend istream &operator>>(istream &input, Contact &con);
        friend ostream &operator<<(ostream &output, const Contact &con);
        int compare(Contact con);
};
//Constructor fara argumente
Contact::Contact(){
    nume = "Andrei";
    prenume = " ";
    telefon = " ";
}
//Constructor cu un singur argument
Contact::Contact(string n){
    nume = n;
    prenume = " ";
    telefon = " ";
}
//Constructor cu doua argumente
Contact::Contact(string n, string p){
    nume = n;
    prenume =p;
    telefon = " ";
}
//Constructor cu trei argumente de tip string
Contact::Contact(string n, string p, string t){
    nume = n;
    prenume = p;
    telefon = t;
}
// functii get / set pentru variabilele
string Contact::getNume(){
    return nume;
}

void Contact::setNume(string n){
    nume = n;
}
string Contact::getPrenume(){
    //string p;
    cout << "Introduce-ti prenumele persoanei: ";
    cin >> prenume;
    //prenume = p;
    return prenume;
}
void Contact::setPrenume(string p){
    prenume = p;
}
string Contact::getTelefon(){
    cout << "Introduce-ti numarul de telefon: ";
    cin >> telefon;
    return telefon;
}
void Contact::setTelefon(string t){
    telefon = t;
}
/** Definirea destructorului : */
Contact::~Contact(void){
    cout<< "Obiectul este distrus.";
}
/** Copy Constructor */
Contact::Contact(const Contact &con){
    cout << "Copy constructor alocand pointer"<<endl;
    //nume = new string;
   //  *nume = *con.nume;
}
/** Functia friend pentru afisarea contactului*/
void print(Contact *con){
    cout<<"Afisare functie PRINT: " ;
    cout<< con->nume<<" "<<con->prenume<<" "<<con->telefon <<endl;
}
int Contact::compare (Contact con){
    return this->nume > con.nume;
}
/** Operatorul extraction >>*/
istream &operator>>(istream &input, Contact &con){
    input >> con.nume >> con.prenume >> con.telefon;
    return input;
}
/** Operatorul insertie <<*/
ostream &operator<<(ostream &output, const Contact &con){
    output <<"Nume: "<< con.nume<<" Prenume: "<<con.prenume<< " Telefon: "<<con.telefon;
    return output;
}

int main()
{
    cout << "Hello world!" << endl;
    Contact con5;
    cin >> con5;
    cout << con5;
    //crearea unui contact fara parametrii;
    Contact* con3 = new Contact();
    con3->getNume();
    con3->setNume("Vasile");
    print(con3);
    cout << con3->nume;
    con3->getPrenume();
    cout << con3->prenume;
    /** crearea unui obiect contact cu un parametru */
    Contact *con4 = new Contact("vasile");
    cout<< con4->getNume();
    // adaugarea unui element in deque;
    deque<Contact> lista_contacte;
    Contact* con1 = new Contact("Mihai", "Cornel", "0722270796");
    print(con1);
    Contact* con2 = new Contact("Vihai", "Vasile", "0722270796");
    if(con1->compare(*con2)){
        cout << "con2 este mai mic decat con1";
    } else {
        cout << "con2 este egala sau mai mare decat con1.";
    }
    lista_contacte.push_front(*con1);
    lista_contacte.push_front(*con2);

    // Iterare deque
    deque<Contact>::iterator it = lista_contacte.begin();
    while(it++ != lista_contacte.end())
        cout<<' '<< con1->getNume()<<' '<<con1->prenume<<' '<<con1->telefon<<endl;

    //iterare deque
    //for(auto it=lista_contacte.cbegin();it !=lista_contacte.cend(); ++it)
        //cout<<' '<<con2->prenume;
    return 0;
}
