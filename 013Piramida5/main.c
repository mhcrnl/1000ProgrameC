#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Piramida din numere!\n");

    int i, spatiu, siruri, k=0, count=0, count1=0;

    printf("introduceti numarul de siruri: ");
    scanf("%d", &siruri);

    for(i=1; i<=siruri; i++){
        for(spatiu=1; spatiu<=siruri-i; ++spatiu){
            printf(" ");
            ++count;
        }
        while(k != 2*i-1){
            if(count<=siruri-1){
                printf("%d ", i+k);
                ++count;
            } else {
                ++count1;
                printf("%d ", (i+k-2*count1));
            }
            ++k;
        }
        count1=count=k=0;
        printf("\n");
    }

    return 0;
}
