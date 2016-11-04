#include <stdio.h>
#include <stdlib.h>
#include "print.h"

//void printSalut(void){
//    printf("Salut din primul program in C. \n");
//}

int Inmultire(void) {
    int a,b,c;
    printf("Introduce-ti cele doua numere pt. a fi inmultite: ");
    scanf("%d%d", &a, &b);
    c = a * b;
    printf("%d * %d = %d", a,b,c);
    return c;
}

int main()
{
    printf("Hello world!\n");

    printSalut();
    Inmultire();

    return 0;
}
