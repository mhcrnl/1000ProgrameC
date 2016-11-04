#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Piramida cu * inversata!\n");

    int i,j, siruri;

    printf("Introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=siruri; i>=1; --i){
        for(j=1; j<=i; ++j){
            printf("* ");
        }
        printf("\n");
    }

    printf("Pragramul v-a ureaza la revedere! ");

    return 0;
}
