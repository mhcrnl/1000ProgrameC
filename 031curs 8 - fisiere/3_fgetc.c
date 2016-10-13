#include <stdio.h>

int main ()
{
    FILE *pf;
    char c;
    int n=0;

    pf=fopen ("litere.txt","rt");
    if (pf == NULL){
        perror("Eroare");
        exit(1);
    }
    else {
        do {
            c = fgetc (pf);
            if (c=='a') n++;
        } while (c!= EOF);

    fclose (pf);

    printf ("Fisierul contine litera 'a' de %d ori \n",n);
    }

    return 0;
}
