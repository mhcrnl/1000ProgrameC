#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

/*

void assert (int expression);

expression  = This can be a variable or any C expression. If expression evaluates to TRUE, assert() does nothing.
             If expression evaluates to FALSE, assert() displays an error message on stderr
             (standard error stream to display error messages and diagnostics) and aborts program execution.

*/

typedef struct
{
    char nume[25];
    float medie;
} ELEV;

// creare fisier cu nume dat
void creare(char numeFisier[])
{
    FILE *pf;
    ELEV s;

    pf=fopen(numeFisier,"wb");
    assert (pf != NULL);
    printf ("Introduceti numele si media fiecarui student. Cand ati terminat apasati combinatia de taste CTRL+Z :\n");
    while ( scanf ("%s %f", s.nume, &s.medie) != EOF)
        fwrite (&s, sizeof(s), 1, pf);
    fclose (pf);
}

// afisare continut fisier pe ecran
void listare (char numeFisier[])
{
    FILE *pf;
    ELEV e;
    pf = fopen (numeFisier, "rb");
    assert (pf != NULL);
    printf ("Nume si medie: \n");
    while ( fread (&e, sizeof(e), 1, pf ) ==1 )
        printf ("%s %.2f \n", e.nume, e.medie);

    fclose (pf);
}

// adaugare articole la sfarsitul unui fisier existent
void adaugare (char numeFisier[])
{
    FILE *pf;
    ELEV e;
    pf = fopen (numeFisier, "ab");
    assert (pf != NULL);
    printf ("Adaugare nume si medie:\n");
    while (scanf ("%s%f", e.nume, &e.medie) != EOF)
        fwrite (&e, sizeof(e), 1, pf);
    fclose (pf);
}

void main()
{
    char numeFisier[20];

    printf ("Introduceti numele fiserului si extensia dorita (ex. student.dat): ");
    scanf ("%s", numeFisier);

    creare (numeFisier);
    listare (numeFisier);
    adaugare (numeFisier);
    listare (numeFisier);

    return 0;
}

