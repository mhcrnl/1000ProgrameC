#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
//#include <array>
//#include <apvector.h>
#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>
//#include <cstdbool>
using namespace std;
void AfisareVector(int[], int);
//Variabila globala initializata default cu 0
int a;
// Aduna doi intregi si returneaza un rezultat
int Adunare (int a, int b){
    return a + b;
}

double ArieCerc(){
    double r, arieCerc;
    cin >> r;
    cout << "Aria cerc = " << M_PI * r * r << endl;
    return arieCerc = M_PI*r*r;
}

void scrieInFila(){
    ofstream myFile;
    myFile.open("exemplu.txt");
    myFile << "Acest text este scris in fila. ";
    myFile.close();
}

void citesteDinFila(){
    ifstream myfile;
    string line;
    myfile.open("exemplu.txt");
    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout << line <<'\n';
        }
        myfile.close();
    }
    else cout << "Fila nu a fost deschisa.";
}

void scrieInFila(const char* file) {
    ofstream myfile;
    //Scrie in continuare in fila
    myfile.open(file, ios::app);
    if(myfile.is_open()){
        myfile << "Acesta este un text scris in fila\n";
        myfile << "A doua linie de text scrisa.\n";
        myfile.close();
    }
    else cout << "Fila nu a fost deschisa.\n";
}

void arrayToFile (const char *filename){
    int myArray[20] ;
    int i = 0;
    ofstream myfile(filename, ios::app);
    if(myfile.is_open()){
        for(i=0;i < 20; i++){
            myArray[i] = i;
            cout << myArray[i] << ' ';
            myfile << myArray[i] << ' ';
        }
        myfile.close();
    }
    else cout << "Fila nu a fost deschisa.";
}
/**< Tablouri - Vectori tablouri unidimensionale---------------------------  */
/**< CREAREA unui vector--------------------------------------------------- */
int* CreareVector( int numarElemente){
    int myVector[numarElemente];
    int i;
    //Crearea unui vector initializat cu elemente
    for(i=0; i<numarElemente; i++){
        myVector[i] = i;
    }
    AfisareVector(myVector, numarElemente);
    //return new int[numarElemente];
    return myVector;
}
/**< Afisarea unui vector----------------------------------------------- */
void AfisareVector(int myVector[], int length){
    int i;
    for(i=0; i<length; i++){
        cout <<"Vector index: "<< i << " VALOARE: "<< myVector[i] << ' '<<endl;
    }
}
/**< Determinarea elementului maxim dintr-un vector------------------------ */
int ElementulMaximVector(int myVector[], int length){
    int i;
    int maxim = myVector[0];
    for(i=0; i<length; i++){
        if(maxim < myVector[i]){
            maxim = myVector[i];
        }
    }
    return maxim;
}
/**< Determinarea elementului minim dintr-un vector ----------------------- */

int ElementulMinimVector(int myVector[], int length){
    int i;
    int minim = myVector[0];
    for(i=0; i<length; i++){
        if(minim > myVector[i]){
            minim = myVector[i];
        }
    }
    return minim;
}
/**< Random generate values for array------------------------------------- */
int * GetRandomValuesArray(){
    static int rand1[30];
    srand( (unsigned)time(NULL) );
    for(int i=0; i<30; ++i){
        rand1[i] = rand();
    }
    return rand1;
}
/**< Sort array ascending------------------------------------------------- */
void SortAscendingArray(int myArray[], int sizeOf){
    int iTemp=0;
    for (int i=0; i< sizeOf; i++){
        for(int j=i+1; j<= sizeOf; j++){
            if(myArray[j]<myArray[i]){
                iTemp = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = iTemp;
            }
        }
    }
    AfisareVector(myArray, sizeOf);
}
/**< Sort array ascending with swap()------------------------------------------------- */
void SortAscendingSwapArray(int myArray[], int index){
    for( int startIndex =0; startIndex< index; ++startIndex){
        int primulIndex = startIndex;
        for(int currentIndex = startIndex +1; currentIndex<index; ++currentIndex){
            if(myArray[currentIndex] < myArray[primulIndex]){
                primulIndex = currentIndex;
            }
            std::swap(myArray[startIndex], myArray[primulIndex]);
        }
    }
    //int myArrayLength = myArray.length();
}
/**< Compare function-------------------------------------------------------- */
int compare( const void *ap, const void *bp){
    const int *a = (int *) ap;
    const int *b = (int *) bp;
    if(*a<*b) return -1;
    else if (*a>*b) return 1;
    else return 0;
}

int main()
{
    cout << "Hello world!" << endl;
   // bool myBool = true;
    cout<< "Sorting ascending array------------------------------------------------------";
    const int index = 9;
    int myArray[index] = { 34, 45,23, 45,34,22,15 ,12,9};
    SortAscendingSwapArray(myArray, index);
    AfisareVector(myArray, index);

    int cautaValoare = 23;
    int *p1 = (int *) bsearch(&cautaValoare, myArray, index, sizeof(myArray[0]), compare);
    if(p1) cout<<"Valoarea: "<< cautaValoare<<" gasita: "<< p1-myArray <<'\n';
    else cout<<"Valoarea: "<< cautaValoare<< " nu a fost gasita.\n";

    int x1 = 2;
    int y2 = 4;
    std::cout << "Before swap: x = " << x1 << ", y = " << y2 << '\n';
    std::swap(x1, y2); // swap the values of x and y
    std::cout << "After swap:  x = " << x1 << ", y = " << y2 << '\n';
    cout<< "Utilizare vectori --------------------------------------" <<endl;
    /**< Random array--------------------------------------------------- */
    int *randomArray;
    randomArray = GetRandomValuesArray();
    AfisareVector(randomArray, 30);
    //std::sort(std::begin(randomArray), std::end(randomArray));
    //sort(randomArray.begin(), randomArray.end());
    SortAscendingArray(randomArray, 30);
    AfisareVector(randomArray, 30);
    /**< Pointer de int catre un vector---------------------------------- */
    int *myVector;
    myVector = CreareVector(100);
    AfisareVector(myVector,100);
    cout << "Elementul Maxim: " << ElementulMaximVector(myVector, 100) <<endl;
    cout << "Elementul Minim: " << ElementulMinimVector(myVector, 100) <<endl;

    cout<<"\nEnd Vector example----------------------------------------"<<endl;

    string fila2 = "Arraytext.txt";
    const char *a = fila2.c_str();
    arrayToFile(a);
    // Conversie din string in char pt ca functia sa accepte parametrul
    string fila = "textFile.txt";
    const char* c = fila.c_str();
    scrieInFila(c);

    scrieInFila();
    citesteDinFila();
    ArieCerc();
    int x, y;
    cout<<"x = ";cin >> x;
    cout<<"y = ";cin >> y;
    cout << "Adunare x + y = " << Adunare(x,y) << endl;
    cout << "Sizeof x = " << sizeof(x) << endl;
    //Radacina patrata a lui x
    cout << "Radacina lui " << x << " este "<<sqrt(x);
    cout << "\nValoarea lui a este : "<< a << endl;
    int variabila;
    scanf("%d", &variabila);
//    char cor = getche();

    return 0;
}
