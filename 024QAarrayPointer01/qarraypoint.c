/** ============================================================
 *  File:   qarraypoint.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.10  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc
 *  Site:   http://www.sanfoundry.com/c-quiz-questions-pointers-arrays/
 =================================================================*/
#include "qarraypoint.h"

void question_1(){
    puts("Care este output-ul acestei functii?");

    char *s = "salut";
    char *p = s;

    printf("%p \t %p \n", s, p);
}

void question_2()
{
    puts("Care este output-ul acestui cod?");

    char *s = "salut!";
    char *p = s;
    printf("%c \t %c \n", s[0], p[1]);
}

void question_3()
{
    puts("Care este output-ul acestui cod?");

    char *s = "salut!";
    char *p = s;
    printf("%c \t %c \n", *(p+3), s[1]);
    /* *(p+3) = p[3] */
}

void question_4()
{
    puts("Care este output-ul acestui cod?");

    char *s = "salut!";
    char *p = s;
    printf("%c \t %c \n",1[p], s[1]);
}

void question_5()
{
    puts("Care este output-ul acestui cod?");
    int ary[4] = {1,2,3,4};
    int *p = ary+3; // ary+3 = ary[3] = p[3] = 4
    printf("%d \n", p[-2]);// p[3 - 2] = p[1] = 2
}

void question_6(){
    puts("Care este output-ul acestui cod?");
    int ary[4] = {1,2,3,4};
    int *p = ary+3; // ary+3 = ary[3] = p[3] = 4
    printf("%d %d \n", p[-2], ary[*p]);// p[3 - 2] = p[1] = 2 si garbagevalue
}

void question_7()
{
    puts("Care este output-ul acestui cod?");
    int i = 10;
    int *p = &i;
    printf("%d \n",  *p);
}

int *a()
{
    int *b = (int*) malloc(sizeof(int));
    *b = 1001;
    return b;
}
void question_8()
{
    puts("Care este output-ul acestui cod?");
    int *p = a();
    printf("%d \n", *p);
}
