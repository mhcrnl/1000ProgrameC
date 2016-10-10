/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *  What is the output of this C code?
        a) Same address is printed.
        b) Different address is printed.
        c) Compile time error
        d) Nothing
    R: a - Numele unui array este un pointer catre prima adresa.
 =================================================================*/
#include <stdio.h>
#include <stdlib.h>

#include "qarraypoint.h"

int main()
{
    printf("Hello world!\n");

    int a[3] = {1,2,3};
    int *p=a;
    printf("%p \t %p \n", p, a);

    question_1();
    question_2();
    question_3();
    question_4();
    question_5();
    question_6();
    question_7();
    question_8();

    return 0;
}
