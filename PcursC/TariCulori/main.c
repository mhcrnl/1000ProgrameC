/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 * \return
 *
 =================================================================*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tara.h"

int main()
{
    int alegere;
    char culoare[10];

    while(1) {
       printf("Hello world from TariCulori!\n");
       puts("   1.  Creare fisier.");
       puts("   2.  Afisarea continutului fisierului.");
       puts("   3.  Adaugare informatii in fisier.");
       puts("   4.  Analiza continutului fisierului");
       puts("   5.  Cauta dupa culoare.");
       puts("   6.  Incheiere program");

       do {
            printf("Introduce-ti selectia dumneavoastra: ");
            //scanf("%d", &alegere);
            char selectie[4];
            gets(selectie);
            alegere = atoi(selectie);
       } while( alegere<1 || alegere>6 );

       switch(alegere) {
        case 1:
            salveazaInFila();
            break;
        case 2:
            afiseazaTot();
            break;
        case 3:
            adauga();
            break;
        case 4:
            citesteDinFila();
            break;
        case 5:

            printf("Introduce-ti culoarea cautata: ");
            scanf("%s", culoare);
            cautaCuloare(culoare);
            break;

        case 6:
            exit(0);
            break;
        default:
            break;
       }

    }



    return 0;
}
