/*
    Citire repetata pana cand n ia o  valoare intre 1 si 1000
*/


#include <stdio.h>

int main()
{
    int n, cate_numere=0;

    do
    {
        cate_numere++;
        printf("Introdu n= ");
        scanf("%d",&n);
        printf("numarul introdus este: %d\n", n);
    } while (n>1000 || n<=0);

    printf("\nAu fost citite %d numere \n",cate_numere);

    return 0;
}

