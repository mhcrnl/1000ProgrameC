#include <stdio.h>
#include <string.h>

union Exemplu {
   int i;
   float f;
   char str[20];
};

int main( ) {

   union Exemplu test;

   test.i = 10;
   printf( "test.i : %d\n", test.i);

   test.f = 220.5;
   printf( "test.f : %.2f\n", test.f);

   strcpy( test.str, "C Programming");
   printf( "test.str : %s\n", test.str);

   return 0;
}
