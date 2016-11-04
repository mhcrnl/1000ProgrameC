#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persoana{
    char nume[20];
    char prenume[20];
    int varsta;
} Persoana;

#define TRUE 1
#define FALSE 0

int main()
{
    printf(" Typedef! \n");

    Persoana pers;
    strcpy(pers.nume, "Mihai");
    strcpy(pers.prenume, "Cornel");
    pers.varsta = 40;

    printf("Nume: %s \n Prenume: %s \n Varsta: %d .\n", pers.nume, pers.prenume, pers.varsta);

    printf("Valoarea lui TRUE: %d \n", TRUE);
    printf("Valoarea lui FALSE: %d \n", FALSE);


    return 0;
}
