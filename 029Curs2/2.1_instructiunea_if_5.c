/*
Cititi de la tastatura un 3 numere intregi.
Verificati daca acestea reprezinta valorile 1,2,3 (nu conteaza ordinea).
Afisati un mesaj corespunzator.

Hint: 1+2+3 = 1*2*3
*/


#include <stdio.h>

int main()
{   int a;

    printf("Introduceti numarul: ");
    scanf ("%d", &a);

    if(a==1){
        printf("Numarul este 1");
    } else if(a==2){
        printf("numarul este 2");
    } else if(a==3){
        printf( "numarul este 3");

    } else {
        printf("Numarulnu corespunde cererii programului");
    }



    return 0;
}

