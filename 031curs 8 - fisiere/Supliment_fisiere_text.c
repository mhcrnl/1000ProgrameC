/*
Cititi mai multe propozitii (siruri de caractere formate din mai multe cuvinte) si scrieti-le pe toate intr-un
acelasi fisier text.
a) Afisati continutul fisierului pe ecran;
b) Introduceti un cuvant de la tastatura. Cautati cuvantul in fisier si afisati numerele liniilor din fisier
care contin cuvantul respectiv;
c) Calculati numarul de cuvinte si numarul de caractere din fisier;
d) Afisati linia (liniile) de lungime maxima.

Autor: Iulia Iacob

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Functie care primeste ca parametru numele unui fisier, citeste de la tastatura caractere pana la citirea caracterului "$"
 si le scrie in fiserul primit ca parametru */

void scrieInFisier (char numeFisier[])
{
    FILE *fp;
    char c;

    fp = fopen (numeFisier,"wt");  /*deschidere fisier pentru scriere*/
    if (fp==NULL)
    {
        perror("Eroare");
        exit(1);
    }
    else
    {
        puts("Fisier deschis in modul scriere.\n");
        puts ("Introduceti un text incheiat cu caracterul '$'");

        c=getchar();
        while (c !='$')  // cat timp nu s-a citit caracterul "$"
        {
            putc(c,fp); // in fisierul fp ese scris caracterul citit de la tastatura
            c=getchar();
        }
        getchar();
    }

    fclose(fp);
}

// Functie care citeste continutul fisierului al carui nume il primeste ca parametru si il afiseaza pe ecran
void citesteDinFisier(char numeFisier [])
{
    char *c, buffer[200];
    FILE *fp;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier pentru citire*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        printf("%s", buffer);
    }

    fclose(fp);
}


// Functie care determina si returneaza dimensiunea celei mai lungi linii din fisier
int lungimeLinii(char numeFisier [])
{
    char *c, buffer[200];
    FILE *fp;
    int lungimeLinie=0, lungimeMax=0;
    /* lungimeMax = dimensiunea celei mai lungi linii din fisier */

    fp = fopen (numeFisier,"rt");	/* eschidere fisier pentru citire */
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        lungimeLinie=strlen(buffer);  /* determinam lungimea liniei curente */
        if(lungimeLinie>lungimeMax)   /* si o comparam cu lungimea maxima depistata */
            lungimeMax=lungimeLinie;
    }

    fclose(fp);

    return lungimeMax;
}


// Functie care afiseaza linia ce are lungimea transmisa ca parametrul
void afisareLinieDeLungime(char numeFisier [], int lungLinie)
{
    char buffer[200];
    FILE *fp;
    int lungimeLinieCurenta;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier pentru citire*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        lungimeLinieCurenta=strlen(buffer); /* determinam lungimea liniei curente */
        if(lungimeLinieCurenta==lungLinie) /* si daca lungimea liniei curente este egala cu lungimea cautata, transmisa ca paramatru */
            printf (" %s", buffer);        /* linia este afisata pe ecran */
    }

    fclose(fp);
}

// Functie ce determina si returnaza numarul de linii dintr-un fisier
int numarLinii (char numeFisier [])
{
    FILE *fp;
    char c, buffer[200];
    int linii=0;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL)  linii++;

    fclose(fp);

    return linii;
}

// Functie ce determina si returnaza numarul de cuvinte dintr-un fisier
int numarCuvinte (char numeFisier [])
{
    FILE *fp;
    char *pch, buffer[200];
    int word=0;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {

        pch = strtok (buffer," ,.-");
        while (pch != NULL)
        {
            word++;
            pch = strtok (NULL, " ,.-");
        }
    }

    fclose(fp);

    return word;
}

// Functie ce determina si returnaza numarul de caractere dintr-un fisier
int numarCaractere (char numeFisier [])
{
    FILE *fp;
    char ch;
    int caractere=0;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while((ch=getc(fp))!=EOF)  /* cat timp nu s-a ajuns la sfarsitul fisierului */
    {
        if(isalpha(ch))
            caractere++;
    }

    fclose(fp);

    return caractere;
}

int cautareCuvantInFisier(char numeFisier[], char cuvantCautat[20])
{
    char *pch, buffer[200];
    FILE *fp;
    int gasitCuv=0, n, linie=0, gasit=0;

    fp = fopen (numeFisier,"rt");	/*deschidere fisier pentru citire*/
    if(fp == NULL)
    {
        printf ("Eroare");
        getch();
        exit(1);
    }

    while (fgets(buffer,200,fp)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        gasitCuv=0;
        pch = strtok (buffer," ,.-;\n");
        while (pch != NULL)
        {
            if(stricmp(pch,cuvantCautat)==0)
                gasitCuv=1;

            pch = strtok (NULL, " ,.-;\n");
        }

        linie++;

        if(gasitCuv==1)
        {
            printf(" %d ",linie);
            gasit = 1;
        }

    }

    fclose(fp);

    return gasit;
}

int main()
{
    char a[100],cuvant[10],buffer[200], ch, cuvantCautat[20];
    char *p, numeFisier[20];
    int word=0,line=1,caractere=0,lungimeMax, gasitCuvant;

    printf ("Introduceti numele fiserului si extensia dorita (ex. litere.txt): ");
    scanf ("%s", numeFisier);

    fflush(stdin);
    scrieInFisier (numeFisier);

    printf("\n Continut fisier:\n");
    citesteDinFisier (numeFisier);

    /*Introduceti un cuvant de la tastatura. Cautati cuvantul in fisier si afisati numerele liniilor din fisier
     care contin cuvantul respectiv; */
    printf("\n\n-------------- Punctul B -------------");
    printf("\n Introduceti cuvantul cautat: ");
    scanf("%s", cuvantCautat);
    printf("Cuvantul %s : ",cuvantCautat);
    gasitCuvant = cautareCuvantInFisier(numeFisier, cuvantCautat);
    if (gasitCuvant==0)  printf("nu se gaseste in fisier");

    /* Calculati numarul de cuvinte si numarul de caractere din fisier */
    printf("\n\n-------------- Punctul c -------------");
    printf("\nNr de cuvinte din fisier %d",numarCuvinte(numeFisier));
    printf("\nNr de caractere din fisier %d",numarCaractere(numeFisier));

    /*Afisati linia (liniile) de lungime maxima */
    printf("\n\n-------------- Punctul D -------------");
    printf("\nFisierul are %d linii", numarLinii(numeFisier));
    lungimeMax=lungimeLinii(numeFisier);
    printf("\nLinia/Liniile de lungime lungimeMaxima: \n");
    afisareLinieDeLungime(numeFisier,lungimeMax);

    return 0;
}

