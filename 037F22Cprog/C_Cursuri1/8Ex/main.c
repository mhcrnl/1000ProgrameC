#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int i,j,n;
    long sum=0, temp=0;

    printf("introduce-ti un numar pt variabila n: \n");
    scanf("%d", &n);
    if(n<1){
        printf("Nmarul trebuie sa fie mai mare ca 1.\n");
        return 0;
    }
    for(i=1; i<=n; i++){
        temp=0;
        for(j=1; j<=i; j++){
            temp+=j;
            printf("Temporar temp = %ld \n",temp);
        }

        sum+=temp;
        printf("Suma este: %ld.\n",sum);
    }
    printf("Suma secventei (%d) este %ld\n", n, sum);
    return 0;
}
