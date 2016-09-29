/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 * \return
 *
 =================================================================*/
#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int **creareMatrice(int sir, int col);

void afisareMatrice(int sir, int col, int **matriceA[sir][col]);


#endif // MATRICE_H_INCLUDED
