#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    printf("%d biti sunt utilizati pt stocarea char.\n", sizeof(char));
    printf("%d biti sunt utilizati pt stocarea short int.\n", sizeof(short int));

    printf("%d biti sunt utilizati pt stocarea int.\n", sizeof(int));
    printf("%d biti sunt utilizati pt stocarea int*.\n", sizeof(int*));
    printf("%d biti sunt utilizati pt stocarea long int.\n", sizeof(long int));

    return 0;
}
