#include <stdio.h>
#include <stdlib.h>

void printBinary(int num){
    int mask = 0x4000;
    if((num & 0x8000) == 0)
        printf("0");
    else
        printf("1");
    while(mask != 0){
        if((num & mask)==0) printf("0");
        else printf("1");
        mask = mask >>1;
    }
    printf("\n");
}

int main()
{
    printf("Hello world!\n");

    int a = 34;
    printBinary(a);
    int b = 43;
    printBinary(b);
    int c = a^b;
    printf("a^b------------------------------\n");
    printBinary(c);
    printf("a&b------------------------------\n");
    int d = a&b;
    printBinary(d);

    int e = a|b;
    printf("a|b------------------------------decimal=%d\n",e);
    printBinary(e);

    int f = a>>2;
    printf("a>>2------------------------------decimal=%d\n",f);
    printBinary(f);

    int g = a<<2;
    printf("a<<2------------------------------decimal=%d\n",g);
    printBinary(g);
    return 0;
}
