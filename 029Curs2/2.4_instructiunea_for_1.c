/*
Folositi instructiunea for pentru a afisa un mesaj de 5 ori.
*/

#include <stdio.h>

int main ()
 {  int i;

    for (i=1; i<=5; i++) // i=i+2
    {
        printf ("Mesaj din bucla for \n");
        //printf ("[%d] Mesaj din bucla for \n ", i);
    }

    printf ("\nBucla for s-a incheiat \n");

    return 0;
 }
