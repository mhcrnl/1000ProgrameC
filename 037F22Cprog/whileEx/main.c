#include <stdio.h>
#include <stdlib.h>

/**Programul gaseste factorialul unui numar:
pentru un numar pozitiv factorial = 1*2*3*......n */

int main()
{
    printf("Factorialul unui numar!\n");

    int numar;
    long long factorial;

    printf("Introduceti un numar pozitiv: ");
    scanf("%d", &numar);

    factorial =1;
    while(numar>0){
        factorial *= numar;
        --numar;
    }

    printf("Factorialul este: %lld", factorial);

    return 0;
}
