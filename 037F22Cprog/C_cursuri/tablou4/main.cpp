#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int tablou[] ={23,45,67,98,67,-78,567, 568, 234, 789, 45 };
    int nrEl = sizeof(tablou)/sizeof(int);
    int max = tablou[0];
    for(int i=0; i<nrEl;i++){
        if(max<tablou[i]) max=tablou[i];
    }
    cout << max<<endl;

    return 0;
}
