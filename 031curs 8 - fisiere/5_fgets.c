#include<stdio.h>

/*
    char * fgets ( char * str, int num, FILE * stream );

    str = Pointer to an array of chars where the string read is copied.

    num = Maximum number of characters to be copied into str (including the terminating null-character).

    stream = Pointer to a FILE object that identifies an input stream.
             stdin can be used as argument to read from the standard input.


    Reads characters from stream and stores them as a C string into str until (num-1) characters have been read
    or either a newline or the end-of-file is reached, whichever happens first.

*/

int main()
{
    char *c, buffer[200],numeFisier[25];
    FILE *pf;

    printf("Introduceti numele fisierului impreuna cu extensia acestuia (ex. demo.txt; litere.txt): ");
    scanf("%s",numeFisier);
    // la introducere numelui trebuie specificata si extensia; ex. demo.txt; litere.txt

    pf=fopen(numeFisier,"rt");
    if (pf == NULL){
        perror("Eroare");
        exit(1);
    }
    else{
        puts("Fisier deschis in modul citire \n\nContinutul fisierului este:");

        while (fgets(buffer,200,pf)!=NULL) {
            printf("%s", buffer);

        }
        /* //sau
        do {
            c=fgets(buffer,100,pf); //functia fgets returneaza sirul la care pointeaza pointerul buffer
            if(c)
                printf("%s",buffer);
        } while(c); */
    }

    fclose(pf);

    return 0;
}
