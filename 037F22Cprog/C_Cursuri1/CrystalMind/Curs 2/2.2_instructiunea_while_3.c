/*
    Scrieti un program care citeste caractere pana la intalnirea caracterului "#".
*/


#include <stdio.h>

int main()
{
    char ch;
    int nr_caractere=0;

    printf ("Introduceti caractere. Pentru a renunta introduceti caracterul #\n");

    while (ch != '#')
    {
        printf ("\nintroduceti un caracter ");
        fflush(stdin);
        scanf ("%c", &ch);
        nr_caractere++;
        printf ("\nAti intodus: %c", ch);
    }

    printf("\nAu fost citite %d caractere \n",nr_caractere);

    return 0;
}

