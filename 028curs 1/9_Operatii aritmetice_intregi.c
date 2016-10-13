// operatii aritmetice in C

#include <stdio.h>  // directiva PREPROCESSOR

int main()
{
    int flori, ghivece; // 2 variabile de tip int

    printf("Introduceti numarul de flori: ");
    scanf ("%d", &flori);

    printf("Introduceti numarul de ghivece: ");
    scanf ("%d", &ghivece);

    printf("flori = %d ; ghivece = %d\n", flori, ghivece);
    printf("flori + ghivece = %d\n", flori + ghivece);
    printf("flori - ghivece = %d\n", flori - ghivece);
    printf("flori * ghivece = %d\n", flori * ghivece);
    printf("flori : ghivece = %d\n", flori / ghivece);
    printf("flori : ghivece = %f\n", flori / ghivece);

    return 0;
}
