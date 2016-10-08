/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 *
 =================================================================*/


#include <stdio.h>
#include <stdlib.h>

#include "cpointer.h"

int main()
{
    printf("Hello world!\n");
    puts("Introduce-ti cate numere doriti pt a fi comparate si gasit\
         numarul cel mai mare pt a inchide introd. -1");


    int number;
    int max=-100000;
    scanf("%d", &number);

    while(number != -1){
        if(number>max) max=number;
        scanf("%d", &number);
    }
    printf("Cel mai mare numar este %d.\n", max);

    pointerC();
    return 0;
}
