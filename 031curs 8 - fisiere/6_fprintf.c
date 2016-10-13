#include<stdio.h>
/*
    int fprintf ( FILE * stream, const char * format, ... );

*/


int main()
{
    FILE *pf;
    char numeFisier[25], expresie[100];
    int i, n;

    printf("Introduceti numele fisierului: ");
    scanf("%s",numeFisier);
    // la introducere numelui NU trebuie specificata si extensia;

    pf=fopen(numeFisier,"wt");
    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }
    else{
        puts("Fisier deschis in modul scriere");
        puts("Cate espresii doriti sa introduceti in fisier?");
        scanf("%d", &n);
        for (i=0;i<n;i++){
            printf ("Introduceti expresia %d: ", i+1);
            fflush(stdin);
            gets (expresie);
            fprintf (pf, "Expresie %d: %s\n",i+1,expresie);
        }
    }

    if(fclose(pf)!=0)
        puts("Eroare la inchiderea fisierului\n");

    return 0;
}
