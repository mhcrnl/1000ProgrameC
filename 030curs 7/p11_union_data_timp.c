#include <stdio.h>
#include <string.h>

union Exemplu {
   int i;
   float f;
   char str[20];
};

int main( ) {

   union Exemplu test;

   printf( "Memoria ocupata de catre exemplul nostru este : %d\n", sizeof(test));

   return 0;
}
