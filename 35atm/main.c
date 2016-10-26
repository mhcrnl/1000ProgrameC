#include <stdio.h>
#include <stdlib.h>

int main()
{
    //printf("Hello world!\n");
    int x; float y;
    scanf("%d %f", &x, &y);
    if(x%5==0 && x<=y-0.50) y=y-x-0.50;
    printf("%.2f", y);
    return 0;
}
