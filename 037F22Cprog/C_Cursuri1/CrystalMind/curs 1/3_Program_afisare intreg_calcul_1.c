// modificare variabila

#include <stdio.h>

int main()
{
    int flori;                   // declararea unei variabile intregi

    flori = 25;                  // atribuirea unei valori variabilei "flori"

    printf("Ana are");
    printf (" %d", flori);
    printf (" fructe.");       // afisare valoare variabila
    printf ("\n");

    flori = flori+1;             // modificam variabila

    printf("Ana are acum %d flori\n", flori);
    printf("\tMaria are %d flori", flori-7);


    return 0;
}
