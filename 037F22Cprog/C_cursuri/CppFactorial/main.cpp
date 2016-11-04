#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ll long long

/**< Gasitrea factorialului unui numar utilizand recursivitatea */
ll fact_recurs(int n){
    if(n==0 || n == 1)
        return 1;
    else return n*fact_recurs(n-1);
}

int main()
{
    cout << "Hello world!" << endl;
    int n;
    while(1){
        cout<<"----1. Factorial cu utilizarea recursivitatii ---"<<endl;

        cout<<"----9. Iesirea din program. ---------------------"<<endl;
        cout<<" Introduce-ti alegerea dvs. : ";
        cin>>n;
        switch(n){
        case 1:
            cout<<" Introduce-ti numarul pt. compunerea factorialului(0 pt exit) :";
            int fact;
            cin >> fact;
            //if(fact==0) break;
            cout << fact_recurs(fact)<<endl;
            break;
        case 9:
            exit(1);
            break;
        default:
            cout<<" Alegerea dvs. este eronata, verificati meniul! ";
        }




    }

    return 0;
}
