/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *
 =================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "addVector.h"
//vector variabila globala
int arr[10] = {12, 34,56,78,90,56,23,45, 34,23};

int main()
{
    printf("Hello world!\n");
    // utilizarea functiei sumaElementeVector cu valoare returnata
    int suma;
    suma = sumaElementeVector(arr, 10);
    printf("Suma elementelor vectorului este: %d\n", suma);
    //Afisarea elementelor din vector cu ajutorul sizeof
    printf("Suma elementelor vectorului cu sizeof: %d\n", sumaElementeVector(arr, sizeof(arr)/sizeof(int)));

    printf("\nAfisarea Elementelor din array: ");
    int i;
    for(i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }

    sortareCrescatoare(arr, 10);

    printf("\nAfisarea Elementelor din array dupa sortare: ");
    //int i;
    for(i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }


    return 0;
}
