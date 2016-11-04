#include <iostream>
#include <stack>

using namespace std;

struct contact{
    char nume[10];
    char prenume[10];
    char telefon[12];
};

void Adauga(stack<contact> st_con, contact con){
    cout<<"Nume: ";
    cin >> con.nume;
    cout<<"Prenume: ";
    cin >> con.prenume;
    cout<<"Telefon: ";
    cin >>con.telefon;

    st_con.push(con);
}
/**< Transferul parametrilor prin referinta */
void Adauga_ref(stack<contact> *st_con, contact *con){

}

int main()
{
    cout << "Hello world!" << endl;

    stack<int> stiva; // constructor declaratie o stiva goala
    /**< Adaugarea de elemente in stack */
    for(int i=0; i<10; i++){
        stiva.push(i+100);
    }
    /**< Afisarea elementelor din stiva invers */
    cout<<"Afisarea elementelor din stiva: ";
    while(!stiva.empty()){
        cout<<' '<<stiva.top();
        stiva.pop();
    }

    stack<contact> stivaContacte;
    struct contact contact[20];
    for(int i=0; i<3; i++){
        cout<<"Nume: ";
        cin >>contact[i].nume;
        cout<<"Prenume: ";
        cin >>contact[i].prenume;
        cout<<"Telefon: ";
        cin >>contact[i].telefon;
        stivaContacte.push(contact[i]);
    }
    cout<< "AFisare contacte: ";
    for(int i=0;i<stivaContacte.size(); i++){
       cout<<contact[i].nume <<' '<<contact[i].prenume<<' '<<contact[i].telefon<<endl;
    }
    //while(!stivaContacte.empty()){

   // }

    return 0;
}
