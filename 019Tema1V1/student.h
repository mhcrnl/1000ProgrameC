/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *
 =================================================================*/
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matematica{
    int nota1;
    int nota2;
    int nota3;
} MATE;

typedef struct literatura{
    int nota1;
    int nota2;
    int nota3;
} LITER;

typedef struct fizica{
    int nota1;
    int nota2;
    int nota3;
} FIZI;

typedef struct stud{
    char nume[20];
    MATE mat;
    LITER lit;
    FIZI fiz;
} STUDENT;

STUDENT citireStudent();

int meniu(void);

void afisareStudent(STUDENT stud);

STUDENT cautaStudent(STUDENT studenti[], char numeStudent[], int nrElemente);

#endif // STUDENT_H_INCLUDED
