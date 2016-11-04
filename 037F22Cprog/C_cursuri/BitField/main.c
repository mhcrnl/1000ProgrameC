#include <stdio.h>
#include <stdlib.h>

struct {
    unsigned int bitField1;
    unsigned int bitField2;
} status1;

struct {
    unsigned int bitField1:1;
    unsigned int bitField2:1;
}status2;

/**< Poate stoca valori pana la 7 */
struct {
    unsigned int ani:3;
} varsta;

int main()
{
    printf("Bit Field ! \n");
    printf("Memoria alocata struct status1: %d \n", sizeof(status1));
    printf("Memoria alocata struct status2: %d \n", sizeof(status2));

    printf("Memoria alocata struct varsta: %d \n", sizeof(varsta));
    varsta.ani = 4;
    printf("Varsta stocata in structura varsta = %d \n", varsta.ani);
    varsta.ani=7;
    printf("Varsta stocata in struct varsata.ani = %d \n", varsta.ani);
    varsta.ani = 8;
    printf("varsta stocata in varsta.ani: %d \n", varsta.ani);

    return 0;
}
