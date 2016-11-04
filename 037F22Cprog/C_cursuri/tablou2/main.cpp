#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int tablou[] = {22, -3, 34, 78, -110, 45, 45 };
    for(int i =0; i<7; i++){
        cout << tablou[i] <<' ';
    }
    int tablou1[] = {23, 56,78,90,-34,56,78,90,23,14,52,34,56,67,98,76,54,-23,34,56,67};
    int dimensiunea_tabloului = sizeof(tablou1)/sizeof(int);
    cout<<endl;
    for(int i=0; i<dimensiunea_tabloului; i++){
        cout<<tablou1[i]<<' ';
    }

    return 0;
}
