#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int a, b, c, d = 0;
    puts("Insert tow numbers 1.cate numere se impart la nr2");
    scanf("%d %d", &a, &b);
    int i;
    for(i=0; i<a; i++){
        scanf("%d", &c);
        if(c%b == 0) d++;
    }
    printf("%d", d);
    return 0;
}
