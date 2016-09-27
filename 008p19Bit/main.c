#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world of BIT!\n");

    char x = -1;
    printf("%x \n", x>>1); //out: ffff ffff

    unsigned int m = 32;
    printf("%X \n", ~m); //out: FFFF FFDF

    printf("%x \n", -1<<3); //out: ffff fff8

    unsigned int a = 0xffff;
    ~a;
    printf("%x\n",a);

    unsigned char i =0x80;
    printf("%d \n", i<<1); //out: 256

    printf("%d>>%d  %d>>%d", 4>>1, 8>>1);

    //unsigned int a=7;
    //printf("a = %d si ~a = %x \n ", a, ~a);

    return 0;
}
