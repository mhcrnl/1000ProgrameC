#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int numar;
    int max =-1000000;
    int cont;

    for( ; ; ){
        scanf("%d", &numar);
        if(numar==-1){
            break;
        }
        cont++;
        if(max<numar) max = numar;
    }
    if(cont) printf("Cel mai mare numar este %d.\n", max);
    else printf("Glumesti? Nu a-ti introdus niciun numar!");

    return 0;
}
