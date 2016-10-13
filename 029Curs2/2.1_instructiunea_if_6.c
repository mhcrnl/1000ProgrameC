/*
Scrieti un program care sa calculeze valorile functiei matematice:

                x*x-2 , daca x<0
F(x) =          3, daca x=0
                x+2, daca x>0


*/


#include <stdio.h>

int main()
{   int x;

    printf("Introduceti numarul: ");
    scanf ("%d", &x);

    if(x<0){
        printf("x*x -2 = %d", x*x-2);
    } else if(x==0){
        printf("F(x)=3");
    } else if(x>0){
        printf("F(x)= %d", x+2);
    }





    return 0;
}

