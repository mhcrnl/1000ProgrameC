/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 * \return
 *
 =================================================================*/

#include "matrice.h"

int **creareMatrice(int sir, int col)
{
    int i, j;
    int matriceRet[sir][col];
    printf("Introduce-ti elementele matricei: \n");
    for(i=0; i<sir; i++){
        for(j=0; j<col; j++){
            scanf("%d", &matriceRet[i][j]);
        }
    }
    return *matriceRet;
}

void afisareMatrice(int sir, int col, int **matriceA[sir][col])
{
    int i, j;
    puts("Afisarea Elementelor Matricei: ");
    for(i=0; i<sir; i++){
        for(j=0; j<col; j++){
            printf("%d ,", matriceA[i][j]);
        }
    }
}
