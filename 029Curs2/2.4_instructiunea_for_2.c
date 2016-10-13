/*
Folositi instructiunea for pentru a afisa crescator valorile intregi din intervalul [1,n], n este citit de la tastatura.
*/

#include <stdio.h>

int main ()
{
    int s,f, i;

    printf ("Introduceti valoarea lui s: ");
    scanf ("%d",&s);
    printf ("Introduceti valoarea lui f: ");
    scanf ("%d",&f);

    for (i=s; i<=f; i++)
        printf("i = %d\n", i);

    printf ("Valoarea finala dupa bucla for este: %d", i);

    return 0;
}
