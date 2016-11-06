/**
	Author:		Mihai Cornel	Romania			    mhcrnl@gmail.com
	System:		Ubuntu 16.04	Code::Blocks 13.12	gcc 5.4.0
                	Fedora 23	Code::Blocks 16.01	gcc
	Copyright:	@2016
	Problem:    https://education.cppinstitute.org/course_datas/display/68/251#
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!C Bublle sort\n");

    int numbers[5],i, aux, swapped;
    // utilizatorul introduce numerele
    for(i=0; i<5; i++){
        printf("Introduce-ti numerele #%i :", i+1);
        scanf("%d", &numbers[i]);
    }

    do {
        swapped =0;
        for(i=0; i<4; i++)
            if(numbers[i] > numbers[i+1]){
                swapped = 1;
                aux = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = aux;
            }
    } while (swapped);

    printf("Afisarea arrayului sortat:\n");
    for(i=0; i<5; i++){
        printf("%d\n", numbers[i]);
    }

    return 0;
}
