/*
Cititi de la tastatura un numar intreg.
Verificati daca numarul respectiv este par sau impar.
Afisati un mesaj corespunzator
*/


#include <stdio.h>

int main()
{   int a;

    printf("Introduceti nunarul: ");
    scanf ("%d", &a);

    if(a%2 == 0){
        printf("Este numar par");
    }
    else printf("numarul este impar");





    return 0;
}

