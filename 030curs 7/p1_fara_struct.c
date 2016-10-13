/**
 * Scrieti un program care pentru citirea de la tastatura a informatiilor
 * despre 3 angajati a unei companii.
 * Un angajat este definit prin: varsta, vechime si nume
 */

#include <stdio.h>

// functiile nu pot returna mai multe variabile odata (atat numele, varsta si vechimea,
// deci trebuie sa folosim pointeri
void citireAngajat(int* angajatVarsta, int* angajatVechime, char angajatNume[50])
{
    printf("Numele angajatului este: ");
    scanf("%s", angajatNume);
    printf("Varsta angajatului este: ");
    scanf("%d", angajatVarsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", angajatVechime);

}

void afisareAngajat(int angajatVarsta, int angajatVechime, char angajatNume[50])
{
    printf("Numele angajatului este: %s\n", angajatNume);
    printf("Varsta angajatului este: %d\n", angajatVarsta);
    printf("Vechimea angajatului este: %d\n", angajatVechime);
}

int main()
{
    // pentru fiecare angajat trebuie sa declaram cate 3 variabile
    int angajat1Varsta, angajat1Vechime;
    char angajat1Nume[50];
    int angajat2Varsta, angajat2Vechime;
    char angajat2Nume[50];
    int angajat3Varsta, angajat3Vechime;
    char angajat3Nume[50];

    // citim primul anagajat in main
    printf("Numele angajatului este: ");
    scanf("%s", angajat1Nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat1Varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat1Vechime);

    // restul ii citim cu ajutorul unei functii
    citireAngajat(&angajat2Varsta, &angajat2Vechime, angajat2Nume);
    citireAngajat(&angajat3Varsta, &angajat3Vechime, angajat3Nume);

    // afisam angajatii
    afisareAngajat(angajat1Varsta, angajat1Vechime, angajat1Nume);
    afisareAngajat(angajat2Varsta, angajat2Vechime, angajat2Nume);
    afisareAngajat(angajat3Varsta, angajat3Vechime, angajat3Nume);

    return 0;
}
