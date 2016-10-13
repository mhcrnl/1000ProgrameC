/*
    Scrieti un program care citeste numere pana la intalnirea unui numar negativ.
*/


#include <stdio.h>

int main()
{
    int n, cate_numere=0;

    printf ("Introduceti un numar. Pentru a renunta introduceti un numar negativ\n");

    while (n>0)
    {
        scanf ("%d", &n);
        printf ("Ati intodus valoarea: %d\n", n);
        if (n>0)
          {
               cate_numere++;
          }

    }

    printf("\nAu fost citite %d numere \n",cate_numere);

    return 0;
}

