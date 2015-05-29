#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include <math.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_MAX_CODE 12

#define TAILLE_MAX_CHAINE 12

#define TAILLE_DICO 258
#define TAILLE_HASHMAP 4096


typedef struct cell cell;
struct cell {
char* string;
unsigned int code;
cell* next;
cell* down;
};


/*
typedef struct tab {
cell* down;
} tab;

tab Dico[258];
} cell_tab;
*/


typedef struct cell* TabCode[TAILLE_HASHMAP];

typedef cell* Dico[TAILLE_DICO];

// Variable global //
extern Dico dico;
extern TabCode hashmap;
extern int sizeOfDico = TAILLE_DICO;

// case 256: taille, case 257: EOF, case 258: bit clear (reset dico)

////////////////////////////////////////////////////////////////
// Author : Quentin
//
char* getCharByCode(unsigned int c);

////////////////////////////////////////////////////////////////
// Author : Quentin
//
unsigned int getCodeByChar(char* c);

////////////////////////////////////////////////////////////////
// Author : Coralie
//
void add(char* c);

////////////////////////////////////////////////////////////////
// Author : Coralie
//
int getSize();


////////////////////////////////////////////////////////////////
// Author : Quentin
// Spe : Initialise le dictionnaire
void init();


////////////////////////////////////////////////////////////////
// Author : Coralie
//
int isExist(char* c);


////////////////////////////////////////////////////////////////
// Author : Quentin
//
void reset();

#endif

