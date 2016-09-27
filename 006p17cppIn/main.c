#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int numar;
    int max =-1000000;
    int cont;

    do{
        scanf("%d", &numar);
        if(numar == -1) continue;
        cont++;
        if(numar>max) max=numar;
    }while(numar != -1);

    if (cont)  printf("Cel mai mare numar este %d.\n", max);
    else printf("Glumesti? Nu a-ti introdus niciun numar.\n");

    return 0;
}
