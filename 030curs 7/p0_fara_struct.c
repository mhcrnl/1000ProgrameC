/**
 * Scrieti un program care pentru citirea de la tastatura a informatiilor
 * despre 3 angajati a unei companii.
 * Un angajat este definit prin: varsta, vechime si nume
 */

#include <stdio.h>

int main()
{
    // pentru fiecare angajat trebuie sa declaram cate 3 variabile
    int angajat1Varsta, angajat1Vechime;
    char angajat1Nume[50];
    int angajat2Varsta, angajat2Vechime;
    char angajat2Nume[50];
    int angajat3Varsta, angajat3Vechime;
    char angajat3Nume[50];

    // citim primul anagajat
    printf("Numele angajatului este: ");
    scanf("%s", angajat1Nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat1Varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat1Vechime);

    // citim al doilea anagajat
    printf("Numele angajatului este: ");
    scanf("%s", angajat2Nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat2Varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat2Vechime);

    // citim al treilea anagajat
    printf("Numele angajatului este: ");
    scanf("%s", angajat3Nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat3Varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat3Vechime);


     // afisam angajatii
     printf("\nAngajatul %s are varsta %d si vechimea %d", angajat1Nume, angajat1Varsta, angajat3Varsta);
     printf("\nAngajatul %s are varsta %d si vechimea %d", angajat2Nume, angajat2Varsta, angajat3Varsta);
     printf("\nAngajatul %s are varsta %d si vechimea %d", angajat3Nume, angajat3Varsta, angajat3Varsta);

    return 0;
}
