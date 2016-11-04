#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persoana {
    char nume[15];
    char prenume[15];
    int varsta;
} ;


int main()
{
    printf("Scriere structura intr-o fila!\n");

    struct persoana *pers = malloc(sizeof(struct persoana));
    strcpy(pers->nume, "mihai");
    strcpy(pers->prenume, "Cornel");
    pers->varsta = 40;
    /**< Scrierea structurii intr-o fila  */
    FILE *file = fopen("output", "wb");
    if(file != NULL){
        fwrite(pers, sizeof(struct persoana), 1, file);
        fclose(file);
    }

    struct persoana *pers1 = malloc(sizeof(struct persoana));
    FILE *file1 = fopen("output", "rb");
    if(file1 != NULL){
        fread(pers1, sizeof(struct persoana), 1, file1);
        fclose(file1);
    }
    printf("%s %s %d\n", pers1->nume, pers1->prenume, pers1->varsta);

    return 0;
}
