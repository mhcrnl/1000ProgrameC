#ifndef TARA_H_INCLUDED
#define TARA_H_INCLUDED
/** ======================================================================
 *  Fisier: tara.h
 *  Author: Mihai Cornel mhcrnl@gmail.com   0722270796
 * \param
 * \return
 *
 =========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TARA{
    char den_tara[20];
    char populatie[15];
    char culoare[15];
}tara;
/**< Adauga in vector taroile */
void adauga(void);
/**< Afiseaza din tari dupa indexul in care se afla in vector */
void afiseaza(int index);
/**< Afiseaza toate tarile din vector */
void afiseazaTot(void);
/**< Salveaza Vectorul intr-un fisier */
void salveazaInFila(void);

void citesteDinFila(void);

void cautaCuloare(char cautaCuloare[]);

#endif // TARA_H_INCLUDED
