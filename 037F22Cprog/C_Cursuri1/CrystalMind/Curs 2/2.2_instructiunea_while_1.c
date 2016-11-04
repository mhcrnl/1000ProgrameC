/*
    Scrieti un program care afiseaza un mesaj de un anumit nr de ori
*/


#include <stdio.h>

int main()
{
    int a=0;

    while (a<5)
    {
        printf (" Mesaj din bucla while \n");
        //printf ("%d Mesaj din bucla while \n", a);
        a=a+1; //a++;
        //a=a+2;
    }

     printf("\nValoarea lui a dupa executia buclei while este %d \n",a);

    return 0;
}

