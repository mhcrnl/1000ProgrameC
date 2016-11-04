#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**< Structurile permit combinarea/stocarea datelor de diferite tipuri  */

struct Carte {
    char titlu[50];
    char autor[50];
    char subiect[100];
    int idCarte;
} carti;

/**< Declararea functiei  */
void afiseazaCarte(struct Carte carte);

/**< Declararea functiei afiseaza carte cu pointer */
void afiseazaCartePointer(struct Carte *carte);

/**<  Declararea functiei returnCarte(void) cu tip de returnare struct carte */
struct Carte returnCarte(void);

/**< Declararea unei functii struct Carte returnCarte(struct Carte carte) */
struct Carte returnCarte1(struct Carte carte);

int main()
{
    printf(" **** Structuri **** !\n");

    /**< Accesarea membrilor unei structuri */
    struct Carte carte1;
    struct Carte carte2;

    /**< Definirea unui pointer catre o structura */
    struct Carte *pcarte;
    pcarte = &carte1;

    strcpy(carte1.titlu, "Programarea in C");
    strcpy(carte1.autor, "Denis Ritchy");
    strcpy(carte1.subiect, "Ajutor pentru a invata C");
    carte1.idCarte = 12345;

    /**< Afisarea carti 1 */
    printf("Titlul: %s \n", carte1.titlu);
    printf("Autor: %s \n", carte1.autor);
    printf("Subiect: %s \n", carte1.subiect);
    printf("Id carte: %d \n", carte1.idCarte);

    /**< Utilizarea functiei afiseazaCarte(struct Carte carte) */
    afiseazaCarte(carte1);

    /**< Utilizarea functiei void afiseazaCartePointer(struct Carte *carte) */
    afiseazaCartePointer(pcarte);

    /**< Utilizarea functiei struct Carte returnCarte(void) */
    carte2 = returnCarte();
    afiseazaCarte(carte2);

    /**< Utilizarea functiei struct Carte returnCarte1( struct Carte carte) */
    struct Carte carte3;
    carte3 = returnCarte1(carte3);
    afiseazaCarte(carte3);
    return 0;
}

/**< Definirea functiei struct Carte returnCarte1(struct Carte carte) */
struct Carte returnCarte1(struct Carte carte){
    printf("\n functia returnCarte1 ********************\n");
    printf("Introduce-ti titlul cartii: ");
    scanf("%s", &carte.titlu);

}

/**< Definirea functiei struct Carte *returnCarte(void) */
struct Carte returnCarte(void){

    const struct Carte retCarte;
    char titlul[50];
    /**< ??? Probleme nu se pot introduce mai multe cuvinte in titlul cartii??? */
    printf("Introduce-ti titlul cartii: ");
    scanf("%s", &titlul);
    //scanf("%s", &titlu);
    //gets(titlu);
    strcpy(retCarte.titlu, titlul);
    printf("Introduce-ti autorul cartii: ");
    scanf("%s", &retCarte.autor);
    printf("Introduce-ti subiectul cartii: ");
    scanf("%s", &retCarte.subiect);
    printf("Introduce-ti id-ul cartii: ");
    scanf("%d", &retCarte.idCarte);

    return retCarte;
}

/**< Definirea functiei void afiseazaCartePointer(struct Carte *carte) */
void afiseazaCartePointer(struct Carte *carte){
    printf("\n Afisarea datelor din functia void afiseazaCartePointer(struct Carte *carte). \n");
    printf("Titlul: %s \n", carte->titlu);
    printf("Autor: %s \n", carte->autor);
    printf("Subiect: %s \n", carte->subiect);
    printf("Id Carte: %d \n", carte->idCarte);
}

/**< Definirea functiei afiseaza carte */
void afiseazaCarte(struct Carte carte){
    printf("\n Afisarea datelor din functia void afiseazaCarte(struct Carte carte). \n");
    printf("Titlul: %s \n", carte.titlu);
    printf("Autor: %s \n", carte.autor);
    printf("Subiect: %s \n", carte.subiect);
    printf("Id Carte: %d \n", carte.idCarte);
}

