#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world! FIBONACCI" << endl;

    int n, c, first =0, second = 1, next;
    cout<< "Introduceti numarul de valori pentru care doriti sa fie in sirul Fibonacci";
    cin>>n;
    cout<<"primul : " << n << "termenn din seria Fibonacci: " << endl;
    for(c=0;c<n;c++){
        if(c<=1) next = c;
        else {
            next = first+second;
            first = second;
            second = next;
        }
        cout<< next<< endl;
    }

    return 0;
}
