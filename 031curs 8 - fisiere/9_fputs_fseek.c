#include <stdio.h>

int main ()
{
    FILE *pf;
    char c;

    //pf = fopen ("demo.txt","at"); //=> atentie la folosirea functiei fseek()
    pf = fopen ("demo.txt","a+t"); //=> atentie la folosirea functiei fseek();

    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }
    else
        puts("Fisier deschis in modul citire + scriere");

    fseek(pf,13,SEEK_SET); // daca deschidem fisierul in modul "a" sau "a+" scrierea se face la sfarsit;

    fputs("a vedea", pf);

    fclose (pf);

    return 0;
}
