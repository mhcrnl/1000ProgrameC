#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WriteFile(const char *filename){
    FILE *fp;
    char ptr[] = "Functia writeFile(...) a functionat";
    fp = fopen(filename, "w+");

    fwrite(ptr, 1, sizeof(ptr), fp);
    fclose(fp);
}

int ReadFile(){
    FILE *fp;
    int c;
    fp = fopen("filePos.c", "r");
    if(fp==NULL){
        perror("ERROR opening file!");
        return(-1);
    }

    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}

void fileOpen(const char *filename){
    FILE *fp;
    fpos_t position;
    fp = fopen(filename, "a+");
    fgetpos(fp, &position);
    fputs("Salut din functia fileOpen().\n",fp);

    fclose(fp);
}

int main()
{
    printf("Hello world!\n");

    char filename1[10] = "text1.txt";
    //char str[] = "Functia writeFile(...) a functionat";
    WriteFile(filename1);

    char filename[10] = "file.txt";
    ReadFile();


    fileOpen(filename);

    int i,j,k;
    i=2;
    j=-2;
    if(i) i--;
    if(j) j++;
    k= i*j;
    printf("%d", k);

    return 0;
}
