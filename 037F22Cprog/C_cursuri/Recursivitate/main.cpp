#include <iostream>
#include <string>

using namespace std;

string oglinda(string);

int main()
{
    cout << "Hello world! RECURSIVITATE" << endl;
    string str;
    cout << "Introduceti cuvantul : ";
    cin >> str;
    oglinda(str);
    cout << "Cuvantul inversat este : "<< oglinda(str);
    return 0;
}

string oglinda(string str){
    if(str.length()==1){
        return str;
    } else {
        return oglinda(str.substr(1, str.length())) + str.at(0);
    }
    //char *x = "doi";

    //if(x != ' ') oglinda();

}
