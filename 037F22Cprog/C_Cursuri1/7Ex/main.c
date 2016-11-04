#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int a=5,b,c,i=10;
    b=a++;//=> b=5, a=6
    printf("a=%d, b=%d, c=%d \n", a,b,c);
    c=++b;//=> b=6, c=6
    printf("a=%d, b=%d, c=%d \n", a,b,c);
    printf("a=%d, b=%d, c=%d \n", a,b,c); //=> a=6, b=6, c=6

    printf("Initial i=10; => i,i++,i++ = %d,%d,%d\n",i,i++,i++);//operatii unare de la dreapta la stanga
    printf("i,++i,++i = %d,%d,%d\n",i,++i,++i);//operatii unare de la dreapta la stanga

    printf("1.%d\n",++i);//Realizeaza operatia ++ si apoi atribuie valoarea variabilei
	printf("2.%d\n",--i);
	printf("3.%d\n",i++);
	printf("4.%d\n",i--);
	printf("5.%d\n",-i++);
	printf("6.%d\n",-i--);
	printf("7.%d\n", +i);

    return 0;
}
