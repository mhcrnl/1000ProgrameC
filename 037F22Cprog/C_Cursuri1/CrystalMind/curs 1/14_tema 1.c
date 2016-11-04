/*
Scrieti un program pentru afisarea codurilor ASCII al urmatoarelor caractere ‘A’, ‘a’, ‘Z’, ‘z’ .
Puteti folosi urmatorul apel al functiei printf: printf("%c = %d ", caracter, caracter).

*/


#include <stdio.h>

int main()
{
    char a = 'a';
    char A = 'A';
    char z='z';
    char Z ='Z';

    printf("%c = %d \n", a, (int)a);
    printf("%c = %d \n", A, A);
    printf("%c = %d \n", z, z);

    printf("%c = %d \n", Z, Z);


    return 0;
}

