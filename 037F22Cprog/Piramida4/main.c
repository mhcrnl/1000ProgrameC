#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Piramida intreaga cu stelute!\n");

    int i, spatiu, siruri, k=0;

    printf("Introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=1; i<=siruri; ++i, k=0)
    {
        for(spatiu=1; spatiu<=siruri-i; ++spatiu)
        {
            printf("  ");
        }
        while(k != 2*i-1)
        {
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    printf("Programul s-a incheiat!");

    return 0;
}
