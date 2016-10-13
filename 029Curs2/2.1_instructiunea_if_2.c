/*
Cititi de la tastatura o valoarea intreaga reprezentand nota unui cursant.
Verificati daca cursantul a promovat examenul.
Afisati un mesaj corespunzator.
*/


#include <stdio.h>

int main()
{
    int nota;

    printf("Introduceti nota: ");
    scanf ("%d", &nota);

    if (nota >= 5)
    {
        printf("Felicitari!\n");
        printf("Ai promovat!\n");
    }
    else

        printf("Nu ai promovat :((((.\n");


    printf("Mai incercam\n");

    return 0;
}

