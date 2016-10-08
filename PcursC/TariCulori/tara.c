/** ============================================================
 *  File:   tara.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.10  gcc
 * \return
 *
 =================================================================*/

#include "tara.h"

#define DIMENSIUNE 200
// tabloul de tari
tara tari[DIMENSIUNE];
// dimensiunea curenta a tabloului
int dim_curenta = 0;

void adauga (void)
{
    if(dim_curenta == DIMENSIUNE) {
        puts("ERORE: Tabloul este plin!");
        return;
    }

    tara t;
    printf("Introduce--ti numele tarii: ");
    gets(t.den_tara);
    printf("Introduce-ti numarul de locuitori: ");
    gets(t.populatie);
    printf("Introduce-ti o culoare de pe drapelul tarii: ");
    gets(t.culoare);

    tari[dim_curenta] = t;
    ++dim_curenta;

    printf("\nTara a fost adaugata.\n");
}

void afiseaza(int index)
{
    if(index<0 || index>=dim_curenta){
        puts("EROARE: indexul este invalid!");
        return;
    }
    tara t = tari[index];

    printf("TARA: %s \n", t.den_tara);
    printf("POPULATIE: %s \n", t.populatie);
    printf("CULOARE: %s \n", t.culoare);
}

void afiseazaTot(void){
    if(dim_curenta == 0){
        puts("EROARE: Vectorul este gol!");
        return;
    }
    int i;
    for(i=0; i<dim_curenta; i++){
        afiseaza(i);
        puts(" ");
    }
}

void salveazaInFila(void){
    FILE *fp;
    if((fp = fopen("tari.txt", "wb")) == NULL){
        puts("EROARE: Nu se poate crea fila.");
        return;
    }
    if(fwrite(&dim_curenta, sizeof(dim_curenta), 1, fp) != 1){
        puts("EROARE: datele nu pot fi salvare!");
        return;
    }
    if(fwrite(tari, sizeof(tari), 1, fp) != 1){
        puts("EROARE: datele nu pot fi salvate!");
        return;
    }
    puts("Vectorul tari a fost salvat!");
}

void citesteDinFila(void){
    FILE *fp;
    if((fp = fopen("tari.txt", "rb")) == NULL){
        puts("EROARE : Fisierul nu poate fi incarcat.");
        return;
    }
    if(fread(&dim_curenta, sizeof(dim_curenta),1, fp) != 1){
        puts("EROARE: datele nu pot fi citite!");
        return;
    }
    if(fread(tari, sizeof(tari),1, fp) != 1){
        puts("EROARE: datele nu pot fi citite!");
        return;
    }
}

void cautaCuloare(char cautaCuloare[]){
    int i;
    for (i=0; i<dim_curenta; i++){
        if((strcmp(cautaCuloare, tari[i].culoare))== 0){

        }
    }
}



