#include<stdio.h>
#include<string.h>

// declararea unei structuri in acest fel implica faptul ca de fiecare data
// trebuie sa scriem struct angajat pentru a declara un angajat nou.

// exista totusi o alternativa: intructiunea typedef
// aceasta are scopul de a redenumi un tip de date intr-un alt mod.

typedef struct angajat {
    char nume[50];
    int varsta;
    int vechime;
}ANGAJAT;

// ANGAJAT a1, a2, a3;

// in cazul structurilor, inlocuim declararea "struct nume_structura" cu una mai simpla

//typedef struct angajat ANGAJAT;

int main()
{
    ANGAJAT angajat0, angajat1, angajat2;

    printf("Numele angajatului este: ");
    scanf("%s", angajat0.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat0.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat0.vechime);

    printf("Angajatul %s are varsta %d si vechimea %d", angajat.nume, angajat.varsta, angajat.vechime);

}
