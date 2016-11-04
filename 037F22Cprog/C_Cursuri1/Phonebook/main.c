#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char nume[20];
    char prenume[20];
    char telefon[20];
};
/**----------------------------------------------------------------------------
        VARIABILE GLOBALE
-------------------------------------------------------------------------------*/
struct Contact Contacte[100];
int counter = 0;

int searchret(char nume[20], char prenume[20]){
    int x=0;
    int index = -1;
    for(x=0; x<counter; x++){
        if(strcmp(nume, Contacte[x].nume)==0)
            if(strcmp(prenume, Contacte[x].prenume)==0)
            index =x;
    }
    return index;
}

void sterge() {
    int x =0;
    int i =0;
    char stergeNume[20];
    char stergePrenume[20];

    printf("\n Nume: ");
    scanf("%s", stergeNume);
    printf("\n Prenume: ");
    scanf("%s", stergePrenume);

    if((x = searchret(stergeNume, stergePrenume)) != -1){
        for(i=x; i<counter-1; i++){
            strcpy(Contacte[i].nume, Contacte[i-1].nume);
            strcpy(Contacte[i].prenume, Contacte[i-1].prenume);
            strcpy(Contacte[i].telefon, Contacte[i-1].telefon);
        }
        printf("Contactul a fost sters.\n");
        --counter;
        return;
    }
    else printf("Contactul nu a fost gasit, incercati din nou. \n");
}

void adauga(){
    counter++;
    printf("\n Nume: ");
    scanf("%s", Contacte[counter-1].nume);
    printf("\n Prenume: ");
    scanf("%s", Contacte[counter-1].prenume);
    printf("\n Telefon: ");
    scanf("%s", Contacte[counter-1].telefon);
    getchar();
}

int main()
{
    printf("******************* AGENDA TELEFONICA *************************!\n");
    int selectie = 0;
    for(;;){
        printf("\n\t\t\t Optiunile agendei :\n");

        printf("\t\t\t 1. Adauga **\n");
        printf("\t\t\t 2. Sterge **\n");

        printf("\t\t\t 8. Inchide aplicatia. **\n");

        printf("\n\n Introduce-ti selectia dumneavoastra: ");
        scanf("%d", &selectie);

        switch(selectie){
        case 1:
            adauga();
            break;
        case 2:
            sterge();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            fprintf(stdout, "\n A-ti ales sa iesiti din aplicatie. \n");
            getchar();
            break;
        default:
            fprintf(stdout, "\n\t Afisati optiunile: %d \a\n", selectie);
            break;
        }
        if(selectie == 8) break;
    }
    return 0;
}
