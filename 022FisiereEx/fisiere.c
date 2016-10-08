/** ============================================================
 *  File:   fisiere.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 *
 =================================================================*/
#include "fisiere.h"

void creare(char numeFisier[])
{
    FILE *fp;
    int numere[100];

    fp = fopen(numeFisier, "wb");
    assert(fp != NULL);
    puts("Introduce-ti numerele pe care le doriti. Pt a inchide aplicatia introduceti CTRL+Z(windows) sau CTRL+D (linux)");
    while(scanf("%d", numere) != EOF){
        fwrite(&numere, sizeof(numere), 1, fp);
    }
    fclose(fp);
}

void listare(char numeFisier[])
{
    FILE *fp;
    int nr[100];

    fp = fopen(numeFisier, "rb");
    assert(fp != NULL);
    puts("Acestea sunt numerele introduse: ");
    while(fread(&nr, sizeof(nr), 1, fp) == 1){
        //for(int i=0; i< sizeof(nr)/sizeof(int); i++){
            printf("%d ", *nr);
        //}

    }
    fclose(fp);
}

void adauga(char numeFisier[])
{
    FILE *fp;
    int numere[100];

    fp = fopen(numeFisier, "ab");
    assert(fp != NULL);
    puts("Introduce-ti numerele pe care le doriti. Pt a inchide aplicatia introduceti CTRL+Z(windows) sau CTRL+D (linux)");
    while(scanf("%d", numere) != EOF){
        fwrite(&numere, sizeof(numere), 1, fp);
    }
    fclose(fp);

}
