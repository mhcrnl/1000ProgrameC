#include <stdio.h>
#include <stdlib.h>

int fact(int);

int main()
{
    //printf("Hello world!\n");
    int t;
    int number;
    scanf("%d", &t);
    while(t-->0){
        scanf("%d", &number);
        printf("%d\n", fact(number));
    }
    return 0;
}

int fact(int n){
    int j =0;
    while(n>=5){
        n=n/5;
        j=j+n;
    }
    return j;
}
