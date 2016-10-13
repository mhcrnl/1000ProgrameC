#include <stdio.h>

int main ()
{
  FILE *pf;

  pf = fopen ("test.txt","wt");
  if (pf != NULL)
  {
    fputs ("Aceasta este o fraza de test pentru functia fopen. Enjoy :)",pf);
    fclose (pf);
  }

  return 0;
}
