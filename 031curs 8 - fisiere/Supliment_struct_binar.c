/*
Declarati o structura persoana cu campurile nume (sir caractere), prenume (sir caractere) si varsta (tip int).
a) Cititi 5 astfel de structuri de la tastatura si scrieti-le intr-un fisier binar;
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

// Functie care citeste de la tasttura un vector de structuri si il scrie intr-un fisier binar al carui nume este dat ca parametru
void scrieInFisierBinar(char numeFisier[], PERSOANA a[],int n)
{
    FILE *fp;
    int i;

    fp=fopen(numeFisier,"wb"); /*deschidere fisier pentru scriere*/
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    for(i=0; i<n; i++)    /*citirea vectorului de structuri de la tastatura*/
    {
        printf("Inntroduceti datele persoanei  %d: \n", i);
        printf(" nume: ");
        scanf("%s",a[i].nume);
        printf(" prenume: ");
        scanf("%s",a[i].prenume);
        printf(" varsta: ");
    }

    fwrite(a,sizeof(PERSOANA),n,fp); /*scrierea vectorului de structuri in fisierul binar */

    fclose(fp);

}

// Functie care afiseaza pe ecran continutul unui fiser binar dat ca parametru
void afisareContinutFisierBinar(char numeFisier[], PERSOANA a[], int *n)
{
    FILE *fp;
    int i;

    fp=fopen(numeFisier,"rb"); /*deschidere fisier pentru citire*/
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    fseek(fp,0,2);  /* ne pozitionam la inceputul fisierului */
    *n=ftell(fp)/sizeof(a[0]); /* pentru a determina cate elemete de tip structura sunt in fisier */
    fseek(fp,0,0); /* ne pozitionam la inceputul fisierului pentru a citi continutul fisierului */

    for(i=0; i<*n; i++)
    {
        fread(&a[i],sizeof(a[0]),1,fp); /* citim din fisier fiecare structura, o punem intr-un vector*/
        printf("\n%s %s %d", a[i].nume, a[i].prenume, a[i].varsta); /* si afisam campurile structurii pe ecran */
    }

    fclose (fp);
}

// Functie care citeste continutul unui fiser binar dat ca parametru. Functia va fi folosita ulterior in alte functii
void citireContinutFisierBinar(char numeFisier[], PERSOANA a[], int *n)
{
    FILE *fp;
    int i;

    fp=fopen(numeFisier,"rb"); /*deschidere fisier pentru citire*/
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    fseek(fp,0,2); /* ne pozitionam la inceputul fisierului */
    *n=ftell(fp)/sizeof(a[0]); /* pentru a determina cate elemete de tip structura sunt in fisier */
    fseek(fp,0,0); /* ne pozitionam la inceputul fisierului pentru a citi continutul fisierului */

    for(i=0; i<*n; i++)
    {
        fread(&a[i],sizeof(a[0]),1,fp); /* citim din fisier fiecare structura si o punem intr-un vector*/
    }

    fclose (fp);
}

// Functie care adauga o structura de tip PERSOANA in fiserul binar al carui nume este dat ca parametru
void adaugarePersoana(char numeFisier[], PERSOANA a[],int n, PERSOANA cautat)
{
    FILE *fp;
    int i,exista=0;

    for(i=0; i<n; i++)
    {
        //printf("\n%s %s %d", a[i].nume, a[i].prenume, a[i].varsta);
        if(strcmp(a[i].nume,cautat.nume)==0 && strcmp(a[i].prenume,cautat.prenume)==0 && (a[i].varsta==cautat.varsta))
            exista=1;  /* comparam structura "cautat" cu fiecare element al vectorului de structuri "a[]" pentru a determina daca aceasta apartine vectorului  */
    }                /* daca aceasta apartine vectorului contorul "exista" devine 1*/

    if(exista==0) /* daca aceasta nu apartine vectorului contorul "exista" ramane 0*/
    {
        fp=fopen(numeFisier,"ab"); /*deschidere fisier pentru adaugare (la finalul fiserului) */
        if(fp==NULL)
        {
            puts("nu");
            exit(1);
        }

        fwrite(&cautat,sizeof(PERSOANA),1,fp); /* scriem structura in fisier */

        fclose(fp);
    }

}

// Functie care calculeaza media de varsta a tuturor persoanelor din fisierul al carui nume e dat ca parametru
float medieBinar(char numeFisier[])
{
    FILE *fp;
    int i;
    int suma=0;
    float medie;
    PERSOANA a; // flosesc o singura variabila de tip PERSONA pe care o suprascriu de fiecare data
    int n;

    fp=fopen(numeFisier,"rb"); /*deschidere fisier pentru citire*/
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    fseek(fp,0,2); /* ne pozitionam la inceputul fisierului */
    n=ftell(fp)/sizeof(PERSOANA); /* pentru a determina cate elemete de tip structura sunt in fisier */
    fseek(fp,0,0); /* ne pozitionam la inceputul fisierului pentru a citi continutul fisierului */

    for(i=0; i<n; i++)
    {
        fread(&a,sizeof(PERSOANA),1,fp); /* folosesc o singura variabila de tip PERSONA pe care o suprascriu de fiecare data */
        suma =  suma + a.varsta;  /* pentru a calcula suma tuturor varstelor */
    }

    fclose (fp);

    medie = (float)suma/n;

    return medie;
}

// Functie care sorteaza crescator dupa varsta componentele existente intr-un fisier al carui nume e dat ca parametru
void ordonare(char numeFisier[])
{
    PERSOANA aux, a[10];
    int n, i,j;

    citireContinutFisierBinar(numeFisier,a,&n);  /* componentele din fisier sunt puse intr-un vector de structuri */

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
        printf(" %s %s %d ",a[i].nume, a[i].prenume, a[i].varsta);

}

// Functie care primeste ca parametru un nume ce trebuie eliminat din fisier. Numele fisierului este dat ca parametru
void EliminaElementDinFisierBinar(char numeFisier[], char numeEliminat [])
{
    FILE *fp;
    int i,j,n, dimInitiala;
    PERSOANA a[10];

    citireContinutFisierBinar(numeFisier,a,&n); /* componentele din fisier sunt puse intr-un vector de structuri */

    dimInitiala=n;

    for(i=0; i<n; i++)
    {
        while(strcmp(a[i].nume,numeEliminat)==0 && i<n) /* Cat timp numele este gasit in vector */
        {
            for(j=i; j<n; j++)
            {
                a[j]=a[j+1];   /* acesta este suprascris */
            }
            n--;
        }
    }

    if (dimInitiala==n) printf ("\nNumele nu a fost gasit"); /* daca dimensiunea initiala a vectorului coincide cu dimensiunea dupa stergere => numele nu a fost gasit */
    else
    {
        fp=fopen(numeFisier,"wb"); /*deschidere fisier pentru scriere */
        if(fp==NULL)
        {
            puts("nu");
            exit(1);
        }

        fwrite(a,sizeof(PERSOANA),n,fp); /* rescriem vectorul in fisier */

        fclose(fp);
    }

}

// Functie ce determina si returneaza persoana de pe o anumita pozitie din fisier
PERSOANA afisareDePePozitia(char numeFisier[], int pozitie)
{
    FILE *fp;
    int i;
    PERSOANA a;

    fp=fopen(numeFisier,"rb"); /*deschidere fisier pentru citire */
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    fseek(fp,pozitie*sizeof(PERSOANA),0); /* ne pozitionam pe pozitia dorita */

    fread(&a,sizeof(PERSOANA),1,fp);  /* citim structura de pe pozita dorita */
    printf("\nPersoana de pozitia %d: %s %s %d\n", pozitie, a.nume, a.prenume, a.varsta); /* si afisam informatiile pe ecran */

    fclose (fp);

    return a;
}

// Functie care modifica stuctura de pe pozitia mentionata
void modificaDePePozitia(char numeFisier[], PERSOANA modificat, int pozitie)
{
    FILE *fp;
    int i;

    fp=fopen(numeFisier,"r+b"); /*deschidere fisier pentru citire + scriere */
    if(fp==NULL)
    {
        puts("nu");
        exit(1);
    }

    fseek(fp,pozitie*sizeof(PERSOANA),0); /* ne pozitionam pe pozitia dorita */

    fwrite(&modificat,sizeof(PERSOANA),1,fp); /* suprascriem sturctura in fisier */

    fclose (fp);
}

int main()
{
    PERSOANA a[10],aux, cautat, modificat;
    int i,n, poz;
    char numeFisier[20], numeEliminat[10], optiune, numeCorect[10];
    int v,exista=0;
    float med;

    printf ("Introduceti numele fiserului si extensia dorita (ex. persoane.out): ");
    scanf ("%s", numeFisier);

    printf("Cate persoane doriti sa introduceti? ");
    scanf("%d",&n);

    printf("\n -------------- Punctul a + b  ---------------\n");

    scrieInFisierBinar(numeFisier,a,n);
    afisareContinutFisierBinar(numeFisier,a,&n);

    printf("\n\n -------------- Punctul c  ---------------\n");
    printf("Introduceti datele persoanei cautate: \n");
    printf("nume : ");
    scanf("%s",cautat.nume);
    printf("prenume :");
    scanf("%s",cautat.prenume);
    printf("varsta :" );
    scanf("%d",&cautat.varsta);

    adaugarePersoana(numeFisier,a,n,cautat);
    printf ("Continutul fisierului dupa adaugare: ");
    afisareContinutFisierBinar(numeFisier,a,&n);

    printf("\n\n -------------- Punctul d  ---------------\n");
    med=medieBinar(numeFisier);
    printf("\n media de varsta a persoanelor din fisier %.2f",med);


    printf("\n\n -------------- Punctul e  ---------------\n");
    ordonare(numeFisier);

    printf("\n\n -------------- Punctul f  ---------------\n");
    printf("Introduceti numele ce trebuie sters: \n");
    scanf("%s", numeEliminat);
    EliminaElementDinFisierBinar(numeFisier,numeEliminat);
    printf ("\nContinutul fisierului dupa eliminare: ");
    afisareContinutFisierBinar(numeFisier,a,&n);

    printf("\n\n -------------- Punctul g  ---------------\n");
    puts(" Pentru ce pozitie doriti sa vizualizati informatiile");
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
        modificaDePePozitia(numeFisier,modificat, poz);
    }
    printf ("Continutul fisierului dupa modificarea numelui: ");
    afisareContinutFisierBinar(numeFisier,a,&n);

    return 0;
}
