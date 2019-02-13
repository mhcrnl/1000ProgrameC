#include <stdio.h>
#include <stdlib.h>

void fun(int a){
    printf("Valoarea lui a este: %d\n", a);
}

int main()
{
    printf("Hello world!\n");

    void (*fun_ptr)(int) = &fun;
    (*fun_ptr)(99);

    return 0;
}
