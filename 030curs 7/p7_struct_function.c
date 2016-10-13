#include<stdio.h>
#include<string.h>

typedef struct {
    char nume[50];
    int varsta;
    int vechime;
} ANGAJAT;

// functie care ia ca parametri doi angajati si
// si returneaza angajatul cu vechime mai mare
ANGAJAT comparaAngajati(ANGAJAT a1, ANGAJAT a2)
{
    ANGAJAT rezultat;

    if (a1.vechime<a2.vechime)
    {
        rezultat = a2;
    }
    else
    {
        rezultat = a1;
    }

    return rezultat;
}

int main()
{
    ANGAJAT angajat1, angajat2;

    printf("Numele angajatului este: ");
    scanf("%s", angajat1.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat1.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat1.vechime);

    printf("Numele angajatului este: ");
    scanf("%s", angajat2.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat2.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat2.vechime);

    ANGAJAT celMaiVechiAngajat;
    celMaiVechiAngajat = comparaAngajati(angajat1, angajat2);

    printf("Angajatul cu cea mai mare vechime este: %s are varsta %d si vechimea %d", celMaiVechiAngajat.nume, celMaiVechiAngajat.varsta, celMaiVechiAngajat.vechime);

}
