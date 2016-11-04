#include <stdio.h>
#include "salut.h"

void salut(){
    printf("Salut din salut.c");
}
/**< Deschide fila filename si scrie text */
 void deschideFila(char *filename,const char *text){
    FILE *fp;
    fp = fopen(filename, "a+");
    fprintf(fp, "%s", text);
    /**< Inchide stream-ul */
    fclose(fp);
 }
