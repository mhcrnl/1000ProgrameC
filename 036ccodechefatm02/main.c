#include <stdio.h>
#include <stdlib.h>

typedef struct atm{
    int x;
    float y;
} ATM;

//float fatm(ATM at);

int main()
{
    //printf("Hello world!\n");
    ATM at;


    scanf("%d %f", &at.x, &at.y);

    if(at.x+0.50<at.y &&  at.x%5==0) at.y= at.y-at.x-0.50;

    printf("%.2f",at.y );

    return 0;
}
