#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float a[10], s=0;
    int i, nr=0;
    for(i=0; i<10; i++){
        cin >>a[i];
    }
    for(i=0; i<10; i++){
        if(a[i]>0){
            s+=a[i], nr++;
        }
    }
    if(nr) cout<<setprecision(2)<<s/nr;
    else cout<<"nu exista numere strict pozitive";

    return 0;
}
