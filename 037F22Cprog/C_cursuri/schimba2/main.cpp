#include <iostream>

using namespace std;

void schimba(int *x, int *y){
    int aux;
    aux =*x;
    *x=*y;
    *y=aux;
    cout<<"VALORILE IN SCHIMBA: "<<"x="<<*x<<" y="<<*y<<endl;
}

int main()
{
    cout << "Hello world!" << endl;
    int x = 3, y=4;
    cout<<"Valorile inaintea intrarii in functia schimba: "<<"x="<<x<<" y="<<y<<endl;
    schimba(&x, &y);
    cout<<"Valorile dupa intrarea in functia schimba: "<<"x="<<x<<" y="<<y<<endl;
    return 0;
}
