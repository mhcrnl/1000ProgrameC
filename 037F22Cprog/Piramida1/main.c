#include <stdio.h>
#include <stdlib.h>
/**Programul afiseaza jumatate de piramida cu numere.*/
int main()
{
    printf("Jumatate de piramida cu numere!\n");

    int i,j, siruri;

    printf("Introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=1; i<=siruri; i++){
        for(j=1; j<=i; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("Programul s-a incheiat. Va Multumim pt. intelegere!\n");

    return 0;
}
