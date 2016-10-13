/*
Cititi de la tastatura o valoarea intreaga reprezentand punctajul unui cursant.
Afisati un mesaj corespunzator in functie de nota.
*/


#include <stdio.h>

int main()
{
    int nota;

    printf("Introduceti nota: ");
    scanf ("%d", &nota);

    if (nota >= 8)
        printf("A\n");
    else if (nota >= 7)
        printf("B\n");
    else if (nota >= 6)
        printf("C\n");
    else if (nota >= 5)
        printf("D\n");
    else
        printf("E\n");

    return 0;
}

