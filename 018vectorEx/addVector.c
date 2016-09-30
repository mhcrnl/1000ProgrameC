/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *
 =================================================================*/

#include "addVector.h"

int sumaElementeVector(int arr[], int elemente)
{
    if(elemente <= 0){
        return 0;
    }

    return arr[elemente-1] + sumaElementeVector(arr, elemente-1);
}

void sortareCrescatoare(int arr[], int elemente){
    int i, j, swap;
    for(i=0; i<elemente; i++){
        for(j=0; j<elemente-1; j++){
            if(arr[j] > arr[j+1]){
                swap       = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }

}
