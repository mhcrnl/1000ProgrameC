#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int tablou1[] = {67, 68, 90, 54,78,34,56,78};
    int nr_el = sizeof(tablou1)/sizeof(int);
    int tablou2[nr_el];
    for(int i=0;i<nr_el; i++){
        tablou2[i]=tablou1[i];
    }
    for(int i=0; i<nr_el;i++){
        cout<< tablou2[i]<< ' ';
    }
    return 0;
}
