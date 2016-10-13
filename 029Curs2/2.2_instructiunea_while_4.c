/*
    Scrieti un program care sa calculeze cel mai mare divizor comun (cmmdc) a 2 numere.
*/


#include <stdio.h>

int main()
{
    int a=18, b=12, r;

    while (a%b != 0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    printf("cmmdc este	%d \n",b);

    return 0;
}

