#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Numere pare sau impare!\n");

    int par=0, impar=0;
    int numar;

    scanf("%d", &numar);

    while(numar != 0){
        if(numar % 2) impar++;
        else par++;
        scanf("%d", &numar);
    }
    printf("Numere pare: %d", par);
    printf("Numere impare: %d", impar);

    return 0;
}
