#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Jumatate de piramida cu litere mari!\n");

    int i,j;
    char input, litera='A';

    printf("Introduceti litera mare care incheie piramida: ");
    scanf("%c", &input);

    for(i=1; i<= (input-'A'+1);++i){
        for(j=1; j<=i; ++j){
            printf("%c", litera);
        }
        ++litera;
        printf("\n");
    }
    return 0;
}
