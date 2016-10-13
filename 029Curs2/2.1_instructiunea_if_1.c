/*
Cititi de la tastatura un numar intreg.
Verificati daca numarul respectiv este 0.
Afisati un mesaj corespunzator.
*/


#include <stdio.h>

int main()
{
    int a;

    printf("Introduceti valoarea lui a: ");
    scanf ("%d", &a);

    if (a==0) printf("Variabila a are valoarea 0");
    else printf("Variabila introdusa are o valoare diferita de 0");

    return 0;
}

