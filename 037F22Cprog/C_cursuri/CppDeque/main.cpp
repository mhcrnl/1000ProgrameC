#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Hello world! From CppDeque." << endl;

    deque<int> dq;
    deque<int>::iterator it;
    int choise, item;

    while(1) {
        cout<<"\n------------------------------------------------"<<endl;
        cout<<" -------- Implementarea colectiei C++ deque ------"<<endl;
        cout<<"\n------------------------------------------------"<<endl;
        cout<<"    1. Inserare item la sfarsitul colectiei.      "<<endl;
        cout<<"    2. Inserare item la inceputul colectiei.      "<<endl;
        cout<<"    3. Stregerea ultimului element din colectie.  "<<endl;
        cout<<"    4. Stergerea primului element din colectie.   "<<endl;
        cout<<"    5. Primul element din colectie.               "<<endl;
        cout<<"    6. Ultimul element din colectie.              "<<endl;
        cout<<"    7. Numarul de elemente din colectie.          "<<endl;
        cout<<"    8. Afisarea elementelor din colectie.         "<<endl;
        cout<<"    9. Exit din program.                          "<<endl;
        cout<<" Introduce-ti alegerea dvs: ";
        cin >> choise;
        switch(choise){
        case 1:
            cout<< "Introduceti valoarea pentru a fi adaugata la sfarsit: ";
            cin>>item;
            dq.push_back(item);
            break;
        case 2:
            cout<< "Introduce-ti valoarea pentru a fi adaugata la inceput: ";
            cin>>item;
            dq.push_front(item);
            break;
        case 3:
            item = dq.back();;
            dq.pop_back();
            cout<<" Elementul "<<item<<" a fost sters."<<endl;
            break;
        case 4:
            item = dq.front();
            dq.pop_front();
            cout<<" Elementul "<<item<<" a fost sters."<<endl;
            break;
        case 5:
            cout<<" Primul element din colectie este: ";
            cout<<dq.front()<<endl;
            break;
        case 6:
            cout<<" Ultimul element din colectie este: ";
            cout<<dq.back()<<endl;
            break;
        case 7:
            cout<<" Numarul de elemente este: "<<dq.size()<<endl;
            break;
        case 8:
            cout<<" Elementele din colectie sunt: ";
            for(it=dq.begin(); it!=dq.end(); it++)
                cout<<*it<<" ";
            cout<<endl;
            break;
        case 9:
            exit(1);
            break;
        default:
            cout<< "Alegerea dvs. este gresita. " <<endl;

        }

    }


    return 0;
}
