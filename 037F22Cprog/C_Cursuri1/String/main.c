#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** String
 *  - sunt tablouri unidimensionale de caractere terminate cu caracterul NULL('\0')
 */

int main()
{
    printf("Hello world!\n");
    /**< declararea unui string */
    char myString[6] = {'S', 'a', 'l', 'u','t','\0'};
    char altString[] = "  din string";
    char str[20];

    /**< Afisarea string-urilor */
    printf("AFISARE STRING: %s %s \n",myString, altString);

    /**< Functia strcpy(str1, str2) */
    strcpy(str, myString);
    printf("Functia strcpy(str, myString): %s \n", str );

    /**< Concatenarea a doua stringuri */
    strcpy(str, altString);
    printf("strcat(str, altString): %s \n", str);

    /**< Lungimea unui string */
    int lungimeString;
    lungimeString = strlen(altString);
    printf("Lungimea stringului altString este de %d caratere.\n", lungimeString);

    return 0;
}
