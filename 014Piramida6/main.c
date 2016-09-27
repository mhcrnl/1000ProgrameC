#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Piramida inversata cu * !\n");

    int siruri, i,j, spatiu;

    printf("Introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=siruri; i>=1; --i){
        for(spatiu = 0; spatiu<siruri-i; ++spatiu) printf("  ");
        for(j=i; j<= 2*i-1; ++j) printf("* ");
        for(j=0; j<i-1; ++j) printf("* ");
        printf("\n");
    }
    return 0;
}
