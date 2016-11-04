#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int Password, Number=0, price = 58, i=0;
    printf("==== Ghiciti numarul =====\n");
    while(Password != 1234){
        if(i>3) return 0;
        i++;
        puts("Va rog introduce-ti parola: ");
        scanf("%d", &Password);
    }
    i=0;
    while(Number != price){
        do{
            puts("Va rog introduce-ti un numar intre 1 si 100:");
            scanf("%d", &Number);
            printf("A-ti introdus numarul %d\n", Number);
        }while(!(Number>=1 && Number<=100));

        if(Number>=90){
            printf("Prea mare! Apasati orice tasta pt. a incerca din nou.");
        }
        else if(Number>=70 && Number<90){
            printf("Prea mare!");
        }
        else if(Number>=1 && Number<=30){
            printf("prea mic!");
        }
        else if(Number>30 && Number<=50){
            printf("Mic mai incearca!");
        }
        else {
            if(Number == price){
                printf("OK A-ti ghicit! La revedere!\n");
            }
            else if(Number < price){
                printf("Scuze prea mic! Apasati o tasta.\n");
            }
            else if(Number > price){
                printf(" Sorry, Only a little bigger! Press any key to try again!\n");
            }
        }
    }
    return 0;
}
