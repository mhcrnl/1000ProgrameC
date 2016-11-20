#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int testCases;
    int b, c, d = 0;

    FILE *fp;
    fp = fopen("file.txt", "w+");

    puts("Introduceti numarul de valori pe care doriti sa=l evaluati: ");
    scanf("%d", &testCases);



    int i;
    for(i=0; i<testCases; i++){

        puts("Introduceti numarul pe care il veti imparti: ");
        scanf("%d", &b);

        printf("Introduceti numarul la care doriti sa-l impartiti: ");
        scanf("%d", &c);
        if(b/c == 0) d++;
        fprintf(fp, "a:%d  b:%d c:%d  c/b=%d\n", testCases, b, c, d);
    }

    fclose(fp);

    printf("%d", d);
    return 0;
}
