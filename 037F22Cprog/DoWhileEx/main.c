#include <stdio.h>
#include <stdlib.h>
/** Programul aduna numerele pana cand utilizatorul introduce
0 */
int main()
{
    printf("do...while!\n");

    double numar, suma =0;

    do{
        printf("Introduceti un numar: ");
        scanf("%lf", &numar);
        suma += numar;
    }while(numar != 0.0);

    printf("Suma = %.2lf", suma);

    return 0;
}
