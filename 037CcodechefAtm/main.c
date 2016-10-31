#include <stdio.h>
#include <stdlib.h>

float atm(int x, float y){
    float ret;
    if(x%5==0 && x<=y-0.50){
        ret = y-x-0.50;
    } else{
        ret = y;
    }
    return ret;
}

int main()
{
    //printf("Hello world!\n");
    int x;
    float y;
    scanf("%d %f", &x, &y);
    printf("%.2f", atm(x,y));
    return 0;
}
