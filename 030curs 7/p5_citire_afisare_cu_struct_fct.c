/**
 * Scrieti un program care pentru citirea de la tastatura a informatiilor
 * despre 3 angajati a unei companii.
 * Un angajat este definit prin: varsta, vechime si nume
 *
 * Implementare cu structuri
 */

#include <stdio.h>

// vom folosi o structura
typedef struct {
    char nume[50];
    int varsta;
    int vechime;
} ANGAJAT;

// functia poate returna o structura de tip angajat
ANGAJAT citireAngajat()
{
    ANGAJAT angj;

    printf("Numele angajatului este: ");
    scanf("%s", angj.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angj.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angj.vechime);

    return angj;
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
    ANGAJAT angajat1, angajat2, angajat3;

    // citim angajatii cu ajutorul unei functii
    angajat1 = citireAngajat();
    angajat2 = citireAngajat();
    angajat3 = citireAngajat();

    // afisam angajatii
    afisareAngajat(angajat1);
    afisareAngajat(angajat2);
    afisareAngajat(angajat3);

    return 0;
}
