#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* Să se realizeze un program care:
a) citeşte caracter cu caracter de la tastatură până la întâlnirea caracterului ‘$’ şi le trece într-un fişier text.
b) citeşte dintr-un fisier orice caracter ASCII şi afişează pe ecran conţinutul acestuia
c) calculează numarul de linii din fişier

  Autor: Iulia IACOB
*/

void scrieFisier (char numeFisier[])
{
    char c;
    FILE *fp;

    fp=fopen(numeFisier,"wt"); /*deschidere fisier pentru scriere*/
    //deschidem sau cream un fisier pt. scriere (eventual suprascriere)
    //cu "a" in loc de "w" am fi creat o adaugare la continutul existent la un moment dat in fisier
    if(fp==NULL)
    {
        perror("Eroare");
        exit(1);
    }
    else
    {
        puts("Fisier deschis in modul scriere.\n");
        puts ("Introduceti un text in fisier. Scriere se incheie la introducere caracterul '$'");

        c=getchar();
        while (c !='$')
        {
            putc(c,fp);  //in c se introduce un caracter citit de la tastatura
            c=getchar(); //se putea si fputc(c,fp);
        }
        getchar();
    }

    if(fclose(fp)!=0)
        puts("Eroare la inchiderea fisierului\n");
}

void citesteFisier(char numeFisier[])
{
    char c;
    FILE *fp;

    fp=fopen(numeFisier,"rt");	/*deschidere fisier*/
    if(fp==NULL)
    {
        perror("Eroare");
        exit(1);
    }

    c=fgetc(fp); 			//citeste un caracter din fisier sau c=getc(fp)
    while (c!=EOF) 			// test daca s-a ajuns la sfarsitul fisierului
    {
        putchar(c); 		//afiseaza un caracter pe ecran
        c=fgetc(fp);
    }
    fclose(fp);
}

void citesteFisier2(char numeFisier[])
{
    char *c, buffer[200];
    FILE *fp;

    fp=fopen(numeFisier,"rt");	/*deschidere fisier pentru citire*/
    if(fp==NULL)
    {
        perror("Eroare");
        exit(1);
    }

   while (fgets(buffer,200,fp)!=NULL)
    /* citeste cate o linie de max 199 caractere din fisier
    s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
    ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        printf("%s", buffer); //afiseaza cate o linie pe ecran
    }

    fclose(fp);
}

int numarLinii (char numeFisier[])
{
    char c;
    int linii=0;
    FILE *fp;

    fp=fopen(numeFisier,"rt");	/*deschidere fisier*/
    if(fp==NULL)
    {
        perror("Eroare");
        exit(1);
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) 			// test daca s-a ajuns la sfarsitul fisierului
        if(c == '\n')
            linii++;

    fclose(fp);

    return linii;
}

int numarLinii2 (char numeFisier[])
{
    FILE *fp;
    char c, buffer[200];
    int linii=0;

    fp=fopen(numeFisier,"rt");	/*deschidere fisier*/
    if(fp == NULL)
    {
        perror("Eroare");
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL)  linii++;

    fclose(fp);

    return linii;
}


int main()
{
    FILE *fisier;
    char numeFisier[20];

    printf ("Introduceti numele fiserului si extensia dorita (ex. litere.txt): ");
    scanf ("%s", numeFisier);

    fflush(stdin);
    scrieFisier (numeFisier);
    fflush(stdin);
    printf("\n Continut fisier:\n\n");
    citesteFisier (numeFisier);

    printf("\nFisierul are %d linii", numarLinii(numeFisier));

}
