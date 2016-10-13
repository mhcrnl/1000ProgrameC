#include<stdio.h>
#include<string.h>

// metoda de declarare gresita -> foloseste variabile globale
struct angajat {
    char nume[50];
    int varsta;
    int vechime;
} angajat1, angajat2;

int main()
{   //struct angajat angajat1, angajat2;

    // initializare structura prin accesarea fiecarui camp in parte
    angajat1.vechime = 19;
    angajat1.varsta = 51;
    // ne reaminim cum se atribuie stringurile
    strcpy(angajat1.nume, "Maria");
    printf("Angajatul %s are varsta %d si vechimea %d", angajat1.nume, angajat1.varsta, angajat1.vechime);


    printf("\nNumele angajatului este: ");
    scanf("%s", angajat2.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat2.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat2.vechime);

    printf("Angajatul %s are varsta %d si vechimea %d", angajat2.nume, angajat2.varsta, angajat2.vechime);

    return 0;

}
