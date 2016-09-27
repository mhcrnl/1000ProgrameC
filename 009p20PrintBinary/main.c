#include <stdio.h>
#include <stdlib.h>

void printBinary( unsigned int numar){
     int i;

//    for(bit=1u<<sizeof bit -1; bit; bit>>=1){
//        printf("%c", numar&bit ? '1':'0');
//    }
    for(i=0;i<sizeof(int); i++){
        printf("%u", ((numar>>i)& 1));
    }

    printf("\n");
}

int main()
{
    printf("Hello world!\n");
    int a = 5;
    printBinary(a);
    int b = 6;
    printBinary(b);
    int c =a ^ b;
    printBinary(c);
    int d = c & b;
    printBinary(d);
    unsigned int e = c | d;
    printBinary(e);
    unsigned int f = ~e;
    printBinary(f);
    return 0;
}
