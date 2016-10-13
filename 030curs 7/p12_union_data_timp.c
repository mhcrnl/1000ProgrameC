#include <stdio.h>
#include <string.h>

union Exemplu {
   int i;
   float f;
   char str[20];
};

int main( ) {

   union Exemplu test;


   strcpy(test.str, "C Programming");
   test.f = 220.5;
   test.i = 10;

   printf( "test.i : %d\n", test.i);
   printf( "test.f : %f\n", test.f);
   printf( "test.str : %s\n", test.str);

   return 0;
}
