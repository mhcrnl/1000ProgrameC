#include <stdio.h>
#include <stdlib.h>
//adunare, scadere, inmultire, inpartire
void adunare(int a, int b){
    printf("Adunare: %d+%d=%d\n", a,b,a+b);
}
void scadere(int a, int b){
    printf("Scadere: %d-%d=%d\n", a,b,a-b);
}
void inmultire(int a, int b){
    printf("Inmultire: %d*%d=%d\n", a,b,a*b);
}
void impartire(int a, int b){
    printf("Impartire: %d/%d=%d\n", a,b,a/b);
}


int main()
{
    printf("Hello world!\n");

    void (*fun_ptr_arr[])(int, int) = {adunare, scadere, inmultire, impartire};
    unsigned int ch, a = 15, b = 10;
    printf("Introduceti: 0 pt. adunare, 1 pt scadere, 2 pt inmultire, 3 pt impartire\n");
    scanf("%d", &ch);
    if(ch > 4) return 0;
    (*fun_ptr_arr[ch])(a,b);

    return 0;
}
