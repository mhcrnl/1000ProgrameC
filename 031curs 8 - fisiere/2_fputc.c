#include <stdio.h>

int main ()
{
    FILE *pf;
    char c;

    pf = fopen ("litere.txt","wt");
    if (pf == NULL){
        perror("Eroare");
        exit(1);
    }
    else {
        puts("Fisier deschis in modul scriere");

        for (c='a'; c <='z'; c++)
            fputc (c,pf);

        fclose (pf);
  }

  return 0;

}
