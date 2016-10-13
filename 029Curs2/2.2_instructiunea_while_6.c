/*
Scrieti un program care determina inversul unui numar

Ex. pentru 12345 => 54321

*/


#include <stdio.h>

int main()
{
    int numarul, suma=0;

    printf("Introduceti numarul: ");
    scanf ("%d", &numarul);

    while(numarul != 0){
        /**Ultima cifra a numarului se obtine prin numarul%10*/
        suma = suma*10 + numarul%10;
        //Aceasta este eliminata prin numarul/10;
        numarul = numarul/10;
    }
    printf("Suma cifrelor numarului este: %d.\n", suma);

    return 0;



}

