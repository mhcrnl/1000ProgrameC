#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Input & Output !\n");
    int c;
    printf("Introduce-ti o valoare: ");
    c =getchar();
    printf("\ n A-ti introdus valoarea: ");
    putchar(c);

    char str[100];
    printf(" \n Introduce-ti o valoarea:  ");
    gets(str);
    printf("\n A-ti introdus valoarea: ");
    puts(str);

    return 0;
}
