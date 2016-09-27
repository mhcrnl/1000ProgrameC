#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int nr;
    int max = -100000;
    int cont;

    do{
        scanf("%d", &nr);
        if(nr != -1) cont++;
        if(nr>max) max=nr;
    }while(nr != -1);

    if(cont) printf("Cel mai mare numar este %d.\n", max);
    else printf("Glumesti? Nu ai introdus niciun numar.\n");
    return 0;
}
