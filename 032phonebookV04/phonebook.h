/** ============================================================
 *  File:   main.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc version 5.4.0
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 ================================================================*/
#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <tinyfiledialogs.h>

typedef struct user {
    char first_name[16];
    char last_name[16];
    char city[16];
    char phone_number[16];
    char street_address[32];
} USER;

int Num_Entries = 0;
int len_Entries = 0;

USER *Entries;
/**< 1. Meniul programului aceasta funcie este rulata in main.c */
void Phone();
/**< 2. Adaugarea unui utilizator  */
void add(USER *u);
/**< 3.  */
void clearScrean();
/**< 4.  */
void set_User(USER *user);
/**< 5. */
void Dynamic_Allocation();
/**< 6.  */
int place_finder(USER u);
/**< 7. */
void Shifter_Right(int index, int  num_element);
/**< 8. */
void readString(char *str);
/**< 9. */
void readNum(char *str);
/**< 10. */
void del_Entrys();
/**< 11. */
void deleteAll();
/**< 12. */
int Finder(char *last_name, char *first_name);
/**< 13. */
void print_user(USER u);
/**< 14. */
void Shifter_left(int index, int num_element);
/**< 16. */
void Modify();
/**< 17.  */
void Search();
/**< 18.  */
void printall();
/**< 19. */
void Load();
/**< 19(A). Load file cu tinyfiledialogs  */
int LoadV01();
/**< 20. */
void Save();


#endif // PHONEBOOK_H_INCLUDED
