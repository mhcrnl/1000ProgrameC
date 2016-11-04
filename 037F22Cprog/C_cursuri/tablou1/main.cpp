#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int tablou[100];
    int numar_elemente;
    cout << "Introduce-ti numarul de elemente pe care dotriți sa la adaugati: ";
    cin >> numar_elemente;
    for(int i=0;i<numar_elemente; i++){
        cout <<"tablou[" <<i<<"]=";
        cin>>tablou[i];
    }
    return 0;
}
