#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int i, k, j;
    i=2, k= 4;
    printf("Proioritate: j = 2*i++; j =%d; i = %d \n", j=2*i++, i);
    printf("Proioritate: j = 2*++i; j =%d; i = %d \n", j=2*++i, i);

    printf("Proioritate: j = 2*++2; j =%d; i =  \n", j=2*(++i));


    return 0;
}
