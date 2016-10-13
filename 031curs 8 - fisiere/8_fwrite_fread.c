#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct abonat {
    char nume[20],prenume[20],telefon[20];
    int varsta;
    }ABONAT;


int main()
{
    FILE *pf;
    ABONAT a, b;
    char sir[20], numeFisier[25];
    int pv;

    printf("Introduceti numele fisierului in care doriti sa introduceti datele: ");
    scanf("%s",numeFisier);

    // scriere in fisierul binar

    pf=fopen(numeFisier,"wb");
    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }
    else {
        puts("Fisier (binar) deschis in modul scriere ");
        strcpy(a.nume,"Popescu");
        strcpy(a.prenume,"Andrei");
        strcpy(a.telefon,"0215111222");
        a.varsta=20;

        fwrite(&a,sizeof(a),1,pf);
     }

    if(fclose(pf)!=0)
        puts("Eroare la inchiderea fisierului\n");


    printf("Introduceti numele fisierului din care doriti sa cititi datele: ");
    scanf("%s",numeFisier);

    // citire din fisierul binar

    pf=fopen(numeFisier,"rb");
    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }

    fseek(pf,0,SEEK_SET);

    printf("Datele din fisier:\n\n");

    fread(&b,sizeof(b),1,pf);
    printf("NUME: \t\t%s\n",b.nume);
    printf("PRENUME: \t%s\n",b.prenume);
    printf("Telefon: \t%s\n",b.telefon);
    printf("Varsta: \t%d\n",b.varsta);

    /*
    fread(sir,sizeof(a.nume),1,pf);
    printf("NUME: \t\t%s\n",sir);
    fread(sir,sizeof(a.prenume),1,pf);
    printf("PRENUME: \t%s\n",sir);
    fread(sir,sizeof(a.telefon),1,pf);
    printf("Telefon: \t%s\n",sir);
    fread(&pv,sizeof(a.varsta),1,pf);
    printf("Varsta: \t%d\n",pv);
    */

    fclose(pf);

}
