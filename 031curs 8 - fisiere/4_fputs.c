#include <stdio.h>

int main ()
{
    FILE *pf;
    char s[100];

    pf = fopen ("demo.txt","wt");
    if (pf==NULL){
        perror("Eroare "); // Afiseaza o eroare ce descrie problema aparuta
        exit(1);
    }
    else {
        puts("Fisier deschis in modul scriere.");
        puts("Introduceti o fraza de la tastatura. Fraza va fi scrisa in fisier.");
        gets (s);
        fputs(s, pf);
  }

  fclose (pf);

  return 0;
}
