#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int exponent;
    int putere =1;

    for(exponent=0; exponent<17; exponent++){
        printf("2 la puterea %d este %d.\n", exponent, putere);
        putere*=2;
    }
    return 0;
}
