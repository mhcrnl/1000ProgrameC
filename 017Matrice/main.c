#include <stdio.h>
#include <stdlib.h>

double** createArray(int w, int h);
void initArray(double** p, int w, int h);
double** tranposenArray(double** p, int w, int h);
void printArray(double** p, int w, int h);
int compareArrays(double** p1, double** p2, int w,int h);

int main()
{
    int w = 5, h = 3;

    //создаем массив
    double** array = createArray(w, h);

    //присваиваем всем значениям массива нуль
    initArray(array, w, h);

    printf("nulls:\n");
    printArray(array, w, h);

    //Занумеровываем каждую ячейку массива
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            array[i][j] = i * w + j;

    printf("numbers:\n");
    printArray(array, w, h);

    //Транспонируем массив и выводим на экран
    printf("transposed:\n");
    printArray(tranposenArray(array, w ,h), h, w);

    //Сравнение массивов

    printf("----Compare----\n");

    printf("pair one:\n");
    double** another_array = createArray(w, h);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            another_array[i][j] = i * w + j;

    printArray(array, w, h);
    printArray(another_array, w, h);

    printf("%s", (compareArrays(array, another_array, w, h) == 0) ? "Inequal" : "Equal");

    printf("pair two:\n");
    another_array[0][0] = 3.6;

    printArray(array, w, h);
    printArray(another_array, w, h);

    printf("%s", (compareArrays(array, another_array, w, h) == 0) ? "Inequal" : "Equal");
    return 0;
}


double** createArray(int w,int h)
{
    double** p =(double**)malloc(sizeof(double*) * h + sizeof(double) * h * w);
    for(int i = 0; i < h; i++)
        p[i] = (double*)(p + h) + i * w;

    return p;
}

void initArray(double** p, int w, int h)
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            p[i][j] = 0;
}

double** tranposenArray(double** p, int w, int h)
{
    double** result = createArray(h, w);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            result[j][i] = p[i][j];
    return result;
}

void printArray(double** p, int w, int h)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            printf(" %f ", p[i][j]);
        printf("\n");
    }
    printf("\n");
}

int compareArrays(double** p1, double** p2, int w, int h)
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(p1[i][j] != p2[i][j])
                return 0;

    return 1;
}
