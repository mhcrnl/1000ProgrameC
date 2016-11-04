#include <stdio.h>
#include <stdlib.h>

void showbits(unsigned int x)
    {
        int i;
        for(i=(sizeof(int)*8)-1; i>=0; i--)
            (x&(1u<<i))?putchar('1'):putchar('0');

    	printf("\n");
    }

void flip(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    //printf("Valoarea lui a=%d, Valoarea lui b = %d", (int)a, (int)b);
}
/**< Functia intoarce 0 pt false si 1 pentru true */
int is_power(int x){
    return !((x-1) & x);
}

    int main()
    {
       int j = 50, m, n;
        int a=8,b=6;
        //int *pa = &a, *pb=&b;
        printf("Puterea lui a = %d \n", is_power(a));
        flip(&a,&b);
        printf("Valoarea lui a=%d ; b=%d \n", a,b);
        printf("The decimal %d is equal to binary - ", j);
        /* assume we have a function that prints a binary string when given
           a decimal integer
         */
        showbits(j);

        /* the loop for right shift operation */
        for ( m = 0; m <= 5; m++ ) {
            n = j >> m;
            printf("%d right shift %d gives ", j, m);
            showbits(n);
        }
        return 0;
    }
