/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 * \return
 *
 =================================================================*/
#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"

int main()
{
    printf("Hello world!\n");
    int *matriceA;
    matriceA = creareMatrice(3,4);
    afisareMatrice(3,4, matriceA);
    return 0;
}
