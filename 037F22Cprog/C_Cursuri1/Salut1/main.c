#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "salut.h"

int main()
{
    printf("Hello world!\n");


    salut();

    char filename[10] = "fila.txt";
    char text[20] ="Mihai Cornel";
    deschideFila(filename, text);


    return 0;
}
