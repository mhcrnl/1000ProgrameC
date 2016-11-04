/*
Cititi de la tastatura o valoarea intreaga reprezentand punctajul unui cursant.
Verificati daca cursantul a promovat examenul.
Afisati un mesaj corespunzator.
*/


#include <stdio.h>

int main()
{
    int nota;

    printf("Introduceti nota: ");
    scanf ("%d", &nota);

    switch (nota)
    {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
    case 7:
        printf("B\n");
        break;
    case 6:
        printf("C\n");
        break;
    case 5:
        printf("D\n");
        break;
    default:
        printf("E\n");
        break;
    }

    return 0;
}

