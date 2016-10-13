#include <stdio.h>

int main ()
{
    FILE *pf;
    char numeFisier[25], s[20];

    printf("Introduceti numele fisierului: ");
    scanf("%s",numeFisier); // la introducere numelui este obligatorie specificarea extensiei;

    pf=fopen(numeFisier,"r+t"); // sau  f=fopen(numeFisier,"rt+");
    // Fisierul trebuie sa existe!

    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }
    else{
        puts("Fisier deschis in modul citire + scriere");

        //fputs("Mesaj pentru a testa pozitionarea in fisiere text", pf); // comentati linia pentru a vedea cum functioaneaza fseek()

        fseek(pf,13,SEEK_SET); // daca deschidem fisierul in modul "a" sau "a+" scrierea se face la sfarsit;

        fputs("a vedea", pf);

        //fseek(pf, 0, SEEK_END); // comentati linia. ce se intampla?
        long df = ftell(pf)/sizeof(char);
        printf("Fisierul %s are %d Bytes\n", numeFisier, df);
    }

     if(fclose(pf)!=0)
        puts("Eroare la inchiderea fisierului\n");

    return 0;
}
