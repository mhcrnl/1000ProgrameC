#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int tablou[10];
    for(int i = 0; i<10;i++){
        tablou[i] = i+100;
    }
    cout<< "Elemente" <<setw(13)<< "Valori" <<endl;
    for(int j=0; j<10; j++){
        cout<< setw(7) << j << setw(13)<<tablou[j]<< endl;
    }

    return 0;
}
