#include<stdio.h>

int main()
{
    FILE *pf;
    char numeFisier[25], s[20];
    int d;

    printf("Introduceti numele fisierului: ");
    scanf("%s",numeFisier);
    // la introducere numelui NU este obligatorie specificarea extensiei;

    pf=fopen(numeFisier,"wt+"); // sau  f=fopen(numeFisier,"w+t");
    if (pf==NULL){
        perror("Eroare");
        exit(1);
    }
    else{
        puts("Fisier deschis in modul scriere + citire");
        fprintf (pf, "%d %s", 2014, "Anul");

        fseek(pf,0,SEEK_SET); // sau rewind(pf)

        fscanf (pf, "%d %s", &d, s);
    }

    if(fclose(pf)!=0)
        puts("Eroare la inchiderea fisierului\n");

    printf ("Datele citite din fisier sunt: %s - %d", s, d);

    return 0;
}
