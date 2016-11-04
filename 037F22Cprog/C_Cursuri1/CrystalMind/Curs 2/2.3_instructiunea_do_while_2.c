/*
Scrieti numere de la tastatura pana la citirea unui numar negativ si calculeaza suma acestora.

*/


#include <stdio.h>

int main()
{
    int n, suma=0;

    do{
        printf ("n = ");
        scanf ("%d", &n);
        suma=suma+n;
        printf("suma este %d \n",suma);

    } while ( n>0);


    return 0;
}

