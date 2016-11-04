#include <iostream>
#include <cstring>

using namespace std;

class Fibonacci {
private:
    int fibar[20];
public:
    Fibonacci();
    void create_nums(int);
    void show(int);
};

void Fibonacci::show(int n){
    for (int i=0; i<n; i++) cout << fibar[i] << '\n';
}

Fibonacci::Fibonacci(){
    memset(fibar, 0, sizeof(int)*20);
    fibar[1] = 1;
}

void Fibonacci::create_nums(int n){
    for(int i=2; i<n; i++)
        fibar[i] = fibar[i-2] +fibar[i-1];
}

int main()
{
    cout << "Hello world! Fibonacci series ... " << endl;
    Fibonacci obj;
    int num;
    cout << "give N: ";
    do {
        cin >> num;
    } while(num>20 || num<0);
    obj.create_nums(num);
    obj.show(num);
    return 0;
}
