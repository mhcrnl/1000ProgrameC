/**
 * Se defineste un tip structura student cu campurile nume, nota1, nota2, nota3, care reprezinta numele
studentului si notele obtinute la 3 materii distincte (aceleasi 3 materii si in aceeasi ordine pentru toti
studentii).

Se cere:
Var 1:
a) Cititi de la tastatura datele pentru max 5 studenti de tipul struct student
b) Cautati un student dupa nume (precizat de la tastatura). Daca il gasiti, afisati toate informatiile
care il caracterizeaza; altfel, afisati un mesaj corespunzator;
c) Aflati care este cel mai bun student la o anumita materie (precizata de la tastatura) si afisati
numele sau. Daca exista mai multi astfel de studenti, afisati numele tuturor in ordine alfabetica.
d) Determinati si afisati numele studentilor nepromovati.

Var 2
a) Declarati un vector (tablou unidimensional) studenti de tipul struct student in care stocati
datele despre 5-6 studenti, citite de la tastatura;
b) Cautati un student dupa nume (precizat de la tastatura). Daca il gasiti, afisati toate informatiile
care il caracterizeaza; altfel, afisati un mesaj corespunzator;
c) Aflati care este cel mai bun student la o anumita materie (precizata de la tastatura) si afisati
numele sau. Daca exista mai multi astfel de studenti, afisati numele tuturor in ordine alfabetica.
d) Determinati premiantul/premiantii grupului de studenti (cel/cei cu media generala maxima si
afisati numele sau. Daca exista mai multi astfel de studenti, afisati numele tuturor.
e) Sortati vectorul studenti descrescator, in functie de valorea câmpului nota2.
f) Determinati si afisati numele studentilor nepromovati.
 */

 /** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *
 =================================================================*/

#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int main()
{
    printf("\t\t\tCatalog !\n");
    int selectie ;
    STUDENT studenti[10];
    char numeStudent[20];
    STUDENT studentCautat;

    while(1){
        selectie = meniu();

        switch(selectie){
            case 1:
               printf("\nIntroduce-ti numarul de studenti dorit:");
               int nr, i;
               scanf("%d", &nr);
               for (i=0; i<nr; i++){
               studenti[i] = citireStudent();
               }
               break;
            case 2:


                printf("Introduce-ti numele studentului cautat: ");
                scanf("%s", numeStudent);
                studentCautat = cautaStudent(studenti, numeStudent, nr);
                afisareStudent(studentCautat);
                break;
            case 3:
                for(i=0; i<nr; i++){
                    afisareStudent(studenti[i]);
                }

            case 5:
                exit(1);
            default:
               break;
        }

    }


    return 0;
}
