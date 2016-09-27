#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int number;
    int max=-100000;
    scanf("%d", &number);

    while(number != -1){
        if(number>max) max=number;
        scanf("%d", &number);
    }
    printf("Cel mai mare numar este %d.\n", max);
    return 0;
}
