/*
Declarati o structura persoana cu campurile nume (sir caractere), prenume (sir caractere) si varsta (tip int).
a) Cititi 5 astfel de structuri de la tastatura si scrieti-le intr-un fisier text;
b) Afisati continutul fisierelor pe ecran;
c) Cititi de la tastatura inca o structura de tipul definit anterior si verificati existenta sa in fisiere.
Daca nu exista, se va adauga. Afisati din nou continutul fisierelor pe ecran;
d) Calculati si afisati media de varsta a tuturor persoanelor din fisiere (se vor folosi, exclusiv, informatiile din fisiere!);
e) Sortati componentele existente in fisiere in functie de valorile campului varsta (crescator/descrescator, la alegere);
f) Eliminati din fisiere persoanele cu un anumit nume (precizat de la tastatura);
g) Verificati (prin vizualizare pe ecran) daca numele celei de-a 3-a persoane este scris corect in fisiere.
Daca nu, corectati numele in fisiere! (Se va afisa mesajul „Doriti sa modificati numele (D/N)?”, pentru ca utilizatorul sa isi exprime optiunea).

Autor: Iulia Iacob

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct
{
    char nume[10];
    char prenume[10];
    int varsta;
} PERSOANA;

// Functie care citeste de la tasttura un vector de structuri si il scrie intr-un fisier text al carui nume este dat ca parametru
void scrieInFisierText(char numeFisier[], PERSOANA a[],int n)
{
    FILE *fisier;
    int i;

    fisier=fopen(numeFisier,"wt"); /*deschidere fisier pentru scriere*/
    if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }

    for(i=0; i<n; i++)  /*citirea vectorului de structuri de la tastatura*/
    {
        printf("Inntroduceti datele persoanei  %d: \n", i);
        printf(" nume: ");
        scanf("%s",a[i].nume);
        printf(" prenume: ");
        scanf("%s",a[i].prenume);
        printf(" varsta: ");
        scanf("%d",&a[i].varsta);
        fprintf(fisier, "%s %s %d \n",a[i].nume, a[i].prenume, a[i].varsta);
        /*scrierea fiecarei structuri, pe randuri separate, in fisierul text */
    }

    fclose(fisier);
}

// Functie care afiseaza pe ecran continutul unui fiser text dat ca parametru
void afisareContinutFisierText(char numeFisier[], PERSOANA a[], int *n)
{
    FILE *fisier;
    int nr=0;
    char buffer[200];

    fisier=fopen(numeFisier,"rt"); /*deschidere fisier pentru citire*/
    if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }

    while (fgets(buffer,200,fisier)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        sscanf (buffer,"%s %s %d",a[nr].nume, a[nr].prenume, &a[nr].varsta);
        /* se citeste din buffer structura */
        printf ("[%d] %s %s %d \n",nr, a[nr].nume, a[nr].prenume, a[nr].varsta);
        /* si este afisata pe ecran */
        nr++; /* se incrementeaza numarul de linii / structuri din fisier */
    }

    *n=nr;
}

// Functie care citeste continutul unui fiser text dat ca parametru. Functia va fi folosita ulterior in alte functii
void citireContinutFisierText(char numeFisier[], PERSOANA a[], int *n)
{
    FILE *fisier;
    int nr=0;
    char buffer[200];

    fisier=fopen(numeFisier,"rt"); /*deschidere fisier pentru citire*/
    if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }

    while (fgets(buffer,200,fisier)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        sscanf (buffer,"%s %s %d",a[nr].nume, a[nr].prenume, &a[nr].varsta);
        /* se citeste din buffer structura */
        nr++;
    }

    *n=nr;
}

// Functie care adauga o structura de tip PERSOANA in fiserul text al carui nume este dat ca parametru
void adaugarePersoana(char numeFisier[], PERSOANA a[],int n, PERSOANA cautat)
{
    FILE *fisier;
    int i,exista=0;

    for(i=0; i<n; i++)
    {
        //printf("\n%s %s %d", a[i].nume, a[i].prenume, a[i].varsta);
        if(strcmp(a[i].nume,cautat.nume)==0 && strcmp(a[i].prenume,cautat.prenume)==0 && (a[i].varsta==cautat.varsta))
            exista=1; /* comparam structura "cautat" cu fiecare element al vectorului de structuri "a[]" pentru a determina daca aceasta apartine vectorului  */
    }                /* daca aceasta apartine vectorului contorul "exista" devine 1*/



    if(exista==0)  /* daca aceasta nu apartine vectorului contorul "exista" ramane 0*/
    {
        fisier=fopen(numeFisier,"at"); /*deschidere fisier pentru adaugare (la finalul fiserului) */
        if(fisier==NULL)
        {
            puts("nu");
            exit(1);
        }

        fprintf(fisier, "%s %s %d \n",cautat.nume, cautat.prenume, cautat.varsta);

        fclose(fisier);
    }

}

// Functie care calculeaza media de varsta a tuturor persoanelor din fisierul al carui nume e dat ca parametru
float medieText(char numeFisier[])
{
    FILE *fisier;
    int suma=0, nr=0;;
    float medie;
    char buffer[200];

    PERSOANA a; // flosesc o singura variabila de tip PERSONA pe care o suprascriu de fiecare data
    int n;

    fisier=fopen(numeFisier,"rt"); /*deschidere fisier pentru citire*/
    if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }


    while (fgets(buffer,200,fisier)!=NULL) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        sscanf (buffer,"%s %s %d",a.nume, a.prenume, &a.varsta);
        /* se citeste din buffer structura */
        suma =  suma + a.varsta;
        /* si se calculeaza suma tuturor varstelor */
        nr++; /* se incrementeaza numarul de linii / structuri din fisier */
    }

    fclose (fisier);

    medie = (float)suma/nr;

    return medie;
}

// Functie care sorteaza crescator dupa varsta componentele existente intr-un fisier al carui nume e dat ca parametru
void ordonare(char numeFisier[])
{
    FILE *fisier2;
    PERSOANA aux, a[10];
    int n, i,j;


    citireContinutFisierText(numeFisier, a,&n);  /* componentele din fisier sunt puse intr-un vector de structuri */

    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(a[i].varsta>a[j].varsta)  /* si sunt sortate */
            {
                aux=a[j];
                a[j]=a[i];
                a[i]=aux;
            }

    printf("Componentele ordonate: \n");
    for(i=0; i<n; i++)
    {
        printf(" %s %s %d / ",a[i].nume, a[i].prenume, a[i].varsta);

    }
}

// Functie care primeste ca parametru un nume ce trebuie eliminat din fisier. Numele fisierului este dat ca parametru
void EliminaElementDinFisierText(char numeFisier[], char numeEliminat[])
{
    FILE *fisier;
    int i,j,n, dimInitiala;
    PERSOANA a[10];

    citireContinutFisierText(numeFisier, a,&n); /* componentele din fisier sunt puse intr-un vector de structuri */

    dimInitiala=n;

    for(i=0; i<n; i++)
    {
        while(strcmp(a[i].nume,numeEliminat)==0 && i<n)  /* Cat timp numele este gasit in vector */
        {
            for(j=i; j<n; j++)
            {
                a[j]=a[j+1]; /* acesta este suprascris */
            }
            n--;
        }
    }

    if (dimInitiala==n) printf ("\nNumele nu a fost gasit\n"); /* daca dimensiunea initiala a vectorului coincide cu dimensiunea dupa stergere => numele nu a fost gasit */
    else
    {
        fisier=fopen(numeFisier,"wt"); /*deschidere fisier pentru scriere */
        if(fisier==NULL)
        {
            puts("nu");
            exit(1);
        }

        for(i=0; i<n; i++)
            fprintf(fisier, "%s %s %d \n",a[i].nume, a[i].prenume, a[i].varsta); /* rescriem vectorul in fisier */

        fclose(fisier);
    }

}

// Functie ce determina si returneaza persoana de pe o anumita pozitie din fisier
PERSOANA afisareDePePozitia(char numeFisier[], int pozitie)
{
    FILE *fisier;
    int nr=0;
    PERSOANA a;
    char buffer[200];

    fisier=fopen(numeFisier,"rt"); /*deschidere fisier pentru citire */
    if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }

    while (fgets(buffer,200,fisier)!=NULL && nr< pozitie) /* s-a presupus ca liniile scrise in fisier vor avea, fiecare, mai putin de 199 de caractere,
       ceea ce garanteaza faptul ca de pe fiecare linie se vor citi toate caracterele pana la intalnirea sfarsitului de linie*/
    {
        nr++; /* ne deplasam linie cu line in fisier pana ajungem la linia (pozitia) dorita */
    }

    sscanf (buffer,"%s %s %d",a.nume, a.prenume, &a.varsta);
    /* se citesc componentele structurii din buffer */

    fclose (fisier);

    return a;
}

// Functie care modifica stuctura de pe pozitia mentionata
void modificaDePePozitia(char numeFisier[], PERSOANA modificat, int pozitie)
{
    FILE *fisier;
    int i, n;
    PERSOANA a[100];

    citireContinutFisierText(numeFisier,a,&n); /* componentele din fisier sunt puse intr-un vector de structuri */


    fisier=fopen(numeFisier,"wt"); /*deschidere fisier pentru scriere */
           if(fisier==NULL)
    {
        puts("nu");
        exit(1);
    }
    a[pozitie] = modificat; /* modificam structura de pe pozitia dorita */

    for(i=0; i<n; i++)
    {
        fprintf(fisier, "%s %s %d \n",a[i].nume, a[i].prenume, a[i].varsta); /* rescriem structura in fisier */
    }

    fclose (fisier);
}

int main ()
{
    PERSOANA a[10],aux, cautat, modificat;
    int i,n, poz, ok=0;
    char numeEliminat[10], optiune, numeCorect[10], numeFisier[20];
    float med;

    printf ("Introduceti numele fiserului si extensia dorita (ex. persoane.txt): ");
    scanf ("%s", numeFisier);

    printf("Cate persoane doriti sa introduceti? ");
    scanf("%d",&n);

    printf("\n -------------- Punctul a + b  ---------------\n");

    scrieInFisierText(numeFisier,a,n);
    afisareContinutFisierText(numeFisier,a,&n);


    printf("\n\n -------------- Punctul c  ---------------\n");
    printf("Introduceti datele persoanei cautate: \n");
    printf("nume : ");
    scanf("%s",cautat.nume);
    printf("prenume :");
    scanf("%s",cautat.prenume);
    printf("varsta :" );
    scanf("%d",&cautat.varsta);

    adaugarePersoana(numeFisier,a,n,cautat);
    printf ("Continutul fisierului dupa adaugare: \n");
    afisareContinutFisierText(numeFisier,a,&n);


    printf("\n\n -------------- Punctul d  ---------------\n");
    med=medieText(numeFisier);
    printf("\Media de varsta a persoanelor din fisier %.2f",med);


    printf("\n\n -------------- Punctul e  ---------------\n");
    ordonare(numeFisier);


    printf("\n\n -------------- Punctul f  ---------------\n");
    printf("Introduceti numele ce trebuie sters: \n");
    scanf("%s", numeEliminat);
    EliminaElementDinFisierText(numeFisier,numeEliminat);
    printf ("\nContinutul fisierului dupa eliminare: \n");
    afisareContinutFisierText(numeFisier,a,&n);


    printf("\n\n -------------- Punctul g  ---------------\n");
    puts(" \n\nPentru ce pozitie doriti sa vizualizati informatiile");
    scanf("%d",&poz);
    modificat=afisareDePePozitia(numeFisier,poz);
    printf ("\n[%d]: %s %s %d", poz, modificat.nume, modificat.prenume, modificat.varsta);
    puts(" \nDoriti sa modificati numele (D/N?)");
    fflush(stdin);
    scanf ("%c", &optiune);
    if (optiune=='n' || optiune=='N') return 0;
    else if (optiune=='d' || optiune=='D')
    {
        printf("Introduceti numele corect: ");
        scanf ("%s", numeCorect);
        strcpy(modificat.nume,numeCorect);
        modificaDePePozitia(numeFisier, modificat, poz);
    }
    printf ("Continutul fisierului dupa modificarea numelui: \n");
    afisareContinutFisierText(numeFisier,a,&n);


    return 0;
}
