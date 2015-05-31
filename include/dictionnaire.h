<<<<<<< HEAD
#ifndef DEF_DICO // Si la constante n'a pas ŽtŽ dŽfinie le fichier n'a jamais ŽtŽ inclus
#define DEF_DICO // On dŽfinit la constante pour que la prochaine fois le fichier ne soit pas inclus
=======
#ifndef __DICTIONNAIRE_H_INCLUDED
#define __DICTIONNAIRE_H_INCLUDED
>>>>>>> e3eca8987b29ba3fb8f3b8f0df2e9b0129393cab

#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_MAX_CODE 12
#define TAILLE_MAX_CHAINE 12
#define TAILLE_DICO 258
#define TAILLE_HASHMAP 4096

<<<<<<< HEAD
=======

<<<<<<< HEAD

>>>>>>> a458ce746eacb3ede08e7e373a7b0264f2da1e67
=======
>>>>>>> e3eca8987b29ba3fb8f3b8f0df2e9b0129393cab
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
Dico dico;
TabCode hashmap;
int sizeOfDico;

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

<<<<<<< HEAD
// Variable global //
Dico dico;
TabCode hashmap;
int sizeOfDico = 258;

#endif
=======
>>>>>>> e3eca8987b29ba3fb8f3b8f0df2e9b0129393cab
