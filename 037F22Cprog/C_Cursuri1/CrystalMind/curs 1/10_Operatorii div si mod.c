// utulizarea operatorilor "%" si "/"

#include <stdio.h>

int main()
{
    int nr;
    int imp;

    printf("Introduceti valoarea numarului: ");          // afisare mesaj
    scanf ("%d", &nr);                                   // citire valoare de la tastatura

    imp=nr;

    int cat = nr / imp;      // valoarea catului
    int rest = nr % imp;     // valoarea restului

    printf(" catul impartirii lui %d la %d este %d", nr, imp, cat);
    printf("\n restul impartirii lui %d la %d este %d", nr, imp, rest);

    // Calculati si afisati catul impartirii numarului "nr" la 2.
    printf("\n restul impartirii lui %d la 2 este %d", nr, nr/2);
    // Calculati si afisati restul impartirii numarului "nr" la 2.

    return 0;
}
