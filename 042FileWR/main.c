#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    //Write to a file
    int nrNumere;
    int num;
    printf("Introduce-ti numarul de numere pe care doriti sa-l scrieti: ");
    scanf("%d", &nrNumere);

    FILE *fp;
    fp=fopen("file.txt", "w");
    if(fp==NULL){
        puts("Eroare fila nu a fost deschisa!");
    }

    int i;
    for(i=0; i<nrNumere; i++){
        printf("Introduce-ti numerele: ");
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);

    FILE *ofp;
    ofp = fopen("file.txt", "r");
    if(ofp == NULL){
        puts("Fila nu a fost deschisa!");
    }

    for(i=0; i<nrNumere; i++){
        fscanf(fp, "%d", &num);
        printf("%d\n", num);

        printf("%d / 2 = %f\n", num, (double)num/2);
    }

    fclose(ofp);

    return 0;
}
