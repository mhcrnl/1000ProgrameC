/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 *  Program:    Citeste din fisierul nr.in, un numar natural n (0<n<=100)
 *          si apoi n valori naturale si afiseaza in fisierul de iesire nr.out
 *          numerele citite descompuse in factori primi, pe fiecare linie fiind
 *          scris cate un numar urmat de perechi de forma (d, p), indicand divizorul
 *          si puterea lui.
 =================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "copiereFisier.h"

int main()
{
    printf("Hello world!\n");

    int n, i, d, p, er;
    unsigned long x;
    FILE *fin = fopen("nr.in", "r");
    if(!fin){
        printf("Eroare la citirea fisierului nr.in\n");
        return 1;
    }

    FILE *fout = fopen("nr.out", "w");
    er = fscanf(fin, "%d", &n);
    if(!er || n>100 ||n<0){
        printf("Numarul de valori este incorect\n");
        return 2;
    }
    for (i=0; i<n; i++){
        er = fscanf(fin, "%10lu ", &x);
        if(!er){
            printf("Eroare la citirea valorilor\n");
            return 3;
        }
        fprintf(fout, "%10lu ", x);
        d=2;
        while(x>1){
            p=0;
            while(x%d==0){
                p++;
                x/=d;
            }
            if (p) fprintf(fout, "(%d, %d)", d, p);
            d++;
        }
        fprintf(fout, "\n");
    }
    fclose(fout);

    copiereFisier("main.c", "mainout.c");
    return 0;
}
