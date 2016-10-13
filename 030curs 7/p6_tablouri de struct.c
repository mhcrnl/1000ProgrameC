/**
 * Scrieti un program care pentru citirea de la tastatura a informatiilor
 * despre n (n citit de la tastatura) angajati a unei companii.
 * Un angajat este definit prin: varsta, vechime si nume
 *
 * Implementare cu tablou de structuri
 */

#include <stdio.h>

// vom folosi o structura
typedef struct
{
    char nume[50];
    int varsta;
    int vechime;
} ANGAJAT;

// functia poate returna o structura de tip angajat
void citireAngajati( ANGAJAT angajat[], int n)
{
    int i;

    for (i=0; i<n; i++)
    {
        printf("Numele angajatului %d este: ", i);
        scanf("%s", angajat[i].nume);
        printf("Varsta angajatului este: ");
        scanf("%d", &angajat[i].varsta);
        printf("Vechimea angajatului este: ");
        scanf("%d", &angajat[i].vechime);
    }

}

void afisareAngajat(ANGAJAT angajat)
{
    printf("Numele angajatului este: %s\n", angajat.nume);
    printf("Varsta angajatului este: %d\n", angajat.varsta);
    printf("Vechimea angajatului este: %d\n", angajat.vechime);
}

int main()
{
    // declaram cei trei angajati
    ANGAJAT angajat[10]; // tabloul de angajati
    int n; // nr de angajati
    int i;

    printf("cati angajati vreti sa introduceti?");
    scanf("%d", &n);

    citireAngajati (angajat, n);

    // afisam angajatii
    printf ("\nAfisare angajati:\n");
    for (i=0; i<n; i++)
    {
        printf ("\Date anjajat %d:\n", i);
        afisareAngajat(angajat[i]);
    }

    return 0;
}
