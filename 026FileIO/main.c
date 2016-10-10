#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("**FileIO **!\n");

    FILE *fp;
    fp=fopen("text.txt", "a+");
    if(fp==NULL){
        printf("Eroare la deschiderea filei.\n");
        exit(1);
    }

    fprintf(fp, "Acesta este textul scris cu fprintf....\n");
    fputs("Acesta este textul scris cu fputs...\n", fp);
    /**< Scrierea unui text */
    const char *text = "Scrie acest text in fila.";
    fprintf(fp, "Acesta este textul: %s \n", text);
    /**< Scrirea de int si float */
    int i = 2345;
    float f = 23.456789;
    fprintf(fp,"Integer: %d , Float: %f \n", i, f);
    /**< Scrierea unui caracter */
    char c = 'a';
    fprintf(fp, "Caracterul este: %c \n", c);
    /**< Scrierea de la tastatura */
    char str[50];
    printf("Scrie-ti un text de la tastatura:\n");
    scanf("%[^\n]s",str);
    fputs(str, fp);

    fclose(fp);
    return 0;
}
