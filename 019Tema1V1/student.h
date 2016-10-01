#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct stud{
    char nume[20];
    int nota1;
    int nota2;
    int nota3;
} STUDENT;

STUDENT citireStudent();

#endif // STUDENT_H_INCLUDED
