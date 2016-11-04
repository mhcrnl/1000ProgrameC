#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Date{
    int i;
    float f;
    char str[34];
} date;

int main()
{
    printf("***************UNIUNI*********************!\n");

    printf("Memoria ocupata de uniunea date: %d biti .\n", sizeof(date));

    date.i = 1234;
    date.f = 23.456767;
    strcpy(date.str, "Java de la 0 la expert");
    /**< Memoria este corupta si se afiseaza valori false pt ca date nu poate pastra decat o valaoare */
    printf("Afisare date.i = %d \n", date.i);
    printf("Afisare date.f = %f \n", date.f);
    printf("Afisare date.str = %s \n", date.str);

    date.i = 34;
    printf("Valoarea lui date.i = %d \n", date.i);

    date.f = 90.341234;
    printf("Valoarea lui date.f = %f \n", date.f);

    strcpy(date.str, "Programare in C") ;
    printf("Valoarea lui date.str = %s", date.str);


    return 0;
}
