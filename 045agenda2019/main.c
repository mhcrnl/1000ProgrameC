#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda{
    char nume[30];
    char prenume[30];
    char nrTel[30];
} agenda ;

void agenda_init( agenda *self, char nume[], char prenume[], char nrTel[]){
    strcpy(self->nume, nume);
    strcpy(self->prenume, prenume);
    strcpy(self->nrTel, nrTel);
}

agenda* agenda_create(char nume[], char prenume[], char nrTel[]){
    agenda *age = (agenda*)malloc(sizeof(agenda));
    agenda_init(age, nume, prenume, nrTel);
    return age;
}

void agenda_print(agenda *self){
    printf("NUME:\t\t %s\n", self->nume);
    printf("PRENUME:\t %s\n", self->prenume);
    printf("NrTELEFON:\t %s\n", self->nrTel);
}

void agenda_reset(agenda *self){
    strcpy(self->nume, "");
    strcpy(self->prenume, "");
    strcpy(self->nrTel, "");
}

void agenda_destroy(agenda *self){
    if(self){
        agenda_reset(self);
        free(self);
    }
}

char* get_agenda_nume( agenda *self){
    return self->nume;
}

void set_agenda_nume( agenda *self, char nume[]){
    strcpy(self->nume, nume);
}

int main()
{
    printf("Hello world!\n");

    agenda *age = agenda_create("mihai", "cornel", "0722270796");
    set_agenda_nume(age, "Vasile");
    agenda_print(age);
    printf("%s\n", get_agenda_nume(age));
    agenda_destroy(age);
    agenda_print(age);

    return 0;
}
