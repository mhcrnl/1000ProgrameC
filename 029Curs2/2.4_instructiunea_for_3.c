/*
Folositi instructiunea for pentru a afisa descrescator valorile intregi din intervalul [n,1], n este citit de la tastatura.
*/

#include <stdio.h>

int main ()
{
    int n, i;

    printf ("Introduceti valoarea lui n: ");
    scanf ("%d",&n);

    for (i=n; i>=1; i--)
        printf("i = %d\n", i);

    printf ("Valoarea finala dupa bucla for este: %d", i);

    return 0;
}
