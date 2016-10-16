#include "texteditor.h"

void Create()
{
    fp1 = fopen("temp.txt", "w");
    printf("Introduce-ti textul si apasati '.' pt a salva.\n");
    while(1){
        c = getchar();
        fputc(c, fp1);
        if(c == '.'){
            fclose(fp1);
            printf("\n\tIntroduce-ti numele filei: ");
            scanf("%s", fn);
            fp1 = fopen("temp.txt", "r");
            fp2 = fopen(fn, "w");
            while(!feof(fp1)){
                c = getc(fp1);
                putc(c, fp2);
            }
            fclose(fp2);
            break;
        }
    }
}

void Display()
{
    printf("\n\tIntroduce-ti numele filei: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("Fila nu a fost gasita!\n");
        goto end1;
    }
    while(!feof(fp1)){
        c = getc(fp1);
        printf("%c",c);

    }
    end1:
    fclose(fp1);
    //printf("\n\tApasati orice tasta pt a continua.");
    //getchar();
}

void Delete()
{
    printf("\n\tIntroduce-ti numele filei: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("Fila nu a fost gasita!\n");
    }
    fclose(fp1);
    if(remove(fn) == 0){
        printf("\n\tFila a fost stearsa!");
    } else {
        printf("\n\tERROARE!!!");
    }
}

void Append()
{
    printf("\n\tIntroduce-ti numele filei: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("Fila nu a fost gasita!\n");
        goto end3;
    }
    while(!feof(fp1)){
        c = getc(fp1);
        printf("%c", c);
    }
    fclose(fp1);
    printf("\n\tIntroduce-ti '.' pt. a adauga text sau '!' pt a inchide.\n");
    fp1 = fopen(fn, "a");
    while(1){
        c =getchar();
        if(c == '!') goto end3;
        if(c == '.'){
            c ='\n';
            printf("\n\t");
            fputc(c, fp1);
        } else {
            printf("%c", c);
            fputc(c, fp1);
        }
    }
    end3: fclose(fp1);
}
