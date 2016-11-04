#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    /**< Variabile locale */
    char ch, nch;
    int count;
    int k;

    printf("Introduce-ti un string cu # la final: \n");
    scanf("%c", &ch);
    while(ch != '#'){ // echivalent cu (ch==0)
        // daca este numar intra in if
        if(ch>='0' && ch<='9'){
            printf("Rulez in if");
            count = ch -'0'+1;
            scanf("%c", &nch);
            for(k=0; k<count; k++)
                printf("%c", nch);
            }
            else {
                printf("Rulez in else.\n");
                printf("%c", ch);
            }
            printf(" ");
            scanf("%c", &ch);
    }
    printf("#\n");
    return 0;
}
