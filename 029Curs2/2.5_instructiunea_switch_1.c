/*
  Folositi instructiunea switch pentru a afisa zilele saptamanii in functie de o valoarea numerica introdusa de la tastatura.

  1. luni
  2. marti
  ....
  7. duminica

*/


#include <stdio.h>


int main ()
{
    //int a, b, rez;

    int opt;

    printf ("Introduceti un numar in intervalul [1,7]: ");
    scanf ("%d",&opt);

    switch (opt)
    {
    case 0:
    case 1:
        printf("Este prima zi a saptamanii\n");
        printf("Este luni\n");
        break;
    case 2:
        printf("Este marti\n");
        break;
    case 3:
        printf("Este miercuri\n");
        break;
    case 4:
        printf("Este joi\n");
        break;
    case 5:
        printf("Este vineriiiiii!!!!!\n");
        break;
    case 6:
        printf("Este sambata\n");
        break;
    case 7:
        printf("Este duminica\n");
        break;
    default:
        printf("Numarul introdus nu este in intervalul [1,7]\n");
    }
    return 0;

}

