#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int myint;
    // Crearea unei coai goale
    queue<int> coada;
    //Afisarea dimensiunii cozii
    cout << "Coada are incluse numarul de elementele: "<<coada.size()<<endl;
    // adaugarea de elemente in coada
    cout << "introduceti elemente in coada: 0 pt inchiderea aplicatiei :\n";
    do{
        cin >> myint;
        coada.push(myint);
    } while(myint);
    cout << "Coada are incluse numarul de elementele: "<<coada.size()<<endl;

    return 0;
}
