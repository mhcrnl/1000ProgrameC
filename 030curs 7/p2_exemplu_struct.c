#include<stdio.h>
#include<string.h>

// vom folosi o structura
// structura incapsuleaza toate proprietatile angajatului.
struct angajat {
    char nume[50];
    int varsta;
    int vechime;
};



int main()
{
    // initializare structura direct, declarand direct membrii ei
    struct angajat angajat1 = {"Vlad", 43, 10};
    //struct test angajat1;

    printf("Angajatul %s are varsta %d si vechimea %d\n", angajat1.nume, angajat1.varsta, angajat1.vechime);

    // initializare structura prin accesarea fiecarui camp in parte
    struct angajat angajat2;

    angajat2.vechime = 19;
    angajat2.varsta = 51;
    // ne reaminim cum se atribuie stringurile
    strcpy(angajat2.nume, "Maria");
    printf("Angajatul %s are varsta %d si vechimea %d\n", angajat2.nume, angajat2.varsta, angajat2.vechime);

    // initializare structura prin citirea de la tastatura
    struct angajat angajat3;

    printf("Numele angajatului este: ");
    scanf("%s", angajat3.nume);
    printf("Varsta angajatului este: ");
    scanf("%d", &angajat3.varsta);
    printf("Vechimea angajatului este: ");
    scanf("%d", &angajat3.vechime);

    printf("Angajatul %s are varsta %d si vechimea %d", angajat3.nume, angajat3.varsta, angajat3.vechime);

    return 0;

}
