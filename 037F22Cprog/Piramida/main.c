#include <stdio.h>
#include <stdlib.h>
/**Programul afiseaza jumatate de piramida alcatuita din n siruri
de *. */

int main()
{
    printf("Jumatate de piramida cu *!\n");

    int i, j, siruri;

    printf("Introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=1; i<=siruri; i++){
        for(j=1; j<=i; ++j){
            printf("* ");
        }
        printf("\n");
    }
    printf("Programul s-a incheiat. Va urez o zi placuta!\n");

    return 0;
}
