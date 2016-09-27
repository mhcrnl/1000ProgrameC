#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int numere[] = {9, 45,36,78, 34, 22};
    int i, aux, swapped;

    do{
        swapped = 0;
        for(i=0; i<=5; i++){
            if(numere[i]>numere[i+1]){
                swapped = 1;
                aux=numere[i];
                numere[i] = numere[i+1];
                numere[i+1]= aux;
            }
        }
    }while(swapped);

    printf("Tabloul sortat: \n");
    for(i=0; i<=5;i++){
        printf("%d ", numere[i]);
    }
    printf("\n");

    return 0;
}
