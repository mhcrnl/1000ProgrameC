/** ============================================================
 *  File:   copiereFisier.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 *
 =================================================================*/
#include "copiereFisier.h"
/**<===============================================================
    Copiaza fisierul fisierin intrun fisier nou fisierOut
    ===============================================================*/
int copiereFisier(char fisierIn[], char fisierOut[])
{
    FILE *fisin, *fisOut;
    char x;

    if(!(fisin = fopen(fisierIn, "r"))){
        printf("Eroare la deschiderea fisierului de intrare!\n");
        return 1;
    }

    if(!(fisOut = fopen(fisierOut, "w"))){
        printf("Eroare la deschiderea fisierului de iesire!\n");
        return 2;
    }

    while(!feof(fisin))
        if(fscanf(fisin, "%c", &x) != EOF)
            fprintf(fisOut, "%c", x);

    fclose(fisin);
    fclose(fisOut);
    return 0;
}
