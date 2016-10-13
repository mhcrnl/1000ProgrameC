// operatorul cast

#include <stdio.h>

int main()
{
   int nr1, nr2, nr3 = 9;

    // adunarea a 2 valori reale,
    // rezultatul este convertit la intreg
    nr1 = 19.99 + 11.99; // 31.98

    // conversie la int - operator cast
    nr2 = (int) 19.99 + (int) 11.99;

    printf("nr1 = %d, nr2 = %d, nr3 = %f", nr1, nr2, (float)nr3/5);


    char ch = 'A';
    int i = ch;
    printf("\n\nCodul ASCII pentru  %c  este %d", ch, i);    // afisare ca caracter si apoi ca intreg
    printf("\n\nCodul ASCII pentru  %c  este %d", ch, (int)ch);    // afisare ca caracter si apoi ca intreg

    return 0;
}
