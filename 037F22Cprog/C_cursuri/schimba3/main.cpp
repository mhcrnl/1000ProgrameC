#include <iostream>

using namespace std;

void schimba(int &x, int &y){
    int aux;
    aux =x;
    x=y;
    y=aux;
    cout<<"VALORILE IN SCHIMBA: "<<"x="<<x<<" y="<<y<<endl;
}

int main()
{
    cout << "Hello world!" << endl;
    /**< Referinte valabil doar in C++ */
    int x=3, y=5;
    int &referinta_x = x;
    int &referinta_y = y;
    cout << x           <<endl;
    cout << referinta_x <<endl;

     cout<<"Valorile inaintea intrarii in functia schimba: "<<"x="<<x<<" y="<<y<<endl;
    schimba(referinta_x, referinta_y);
    cout<<"Valorile dupa intrarea in functia schimba: "<<"x="<<x<<" y="<<y<<endl;

    /**< Automat compilatorul va transmite referintele */
    cout<<"Valorile inaintea intrarii in functia schimba: "<<"x="<<x<<" y="<<y<<endl;
    schimba(x, y);
    cout<<"Valorile dupa intrarea in functia schimba: "<<"x="<<x<<" y="<<y<<endl;

    return 0;
}
