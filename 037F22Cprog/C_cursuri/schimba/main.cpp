#include <iostream>

using namespace std;

void schimba(int x, int y){
    int aux;
    aux = x;
    x=y;
    y=aux;
    cout << "x=" <<x <<" y="<<y<<endl;
}
/**< Transferul parametrilor prin pointer valabil in C si C++ */
void schimba_pointer(int *x, int *y){
    int aux;
    aux = *x;
    *x=*y;
    *y = aux;
    cout <<"x="<<x<<" y="<<y<<endl;
}
/**< Transmiterea parametrilor prin referinta doar C++  */
void schimba_referinta(int &x, int &y){
    int aux;
    aux =x;
    x = y;
    y=aux;
    cout<< "x="<<x<<" y="<<y<< endl;
}

int main()
{
    cout << "Hello world!" << endl;
    int x = 3, y =4;
    schimba(x,y);
    cout <<"x="<<x<<" y="<<y<<endl;
    schimba_pointer(&x, &y);
    //schimba_pointer(*x,*y);
    cout <<"x="<<x<<" y="<<y<<endl;
    int &rx = x, &ry =y;
    schimba_referinta(x,y);
    schimba_referinta(rx,ry);
    cout <<"x="<<x<<" y="<<y<<endl;
    return 0;
}
