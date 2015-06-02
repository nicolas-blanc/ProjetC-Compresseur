#ifndef DEF_DICOH // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_DICOH // On définit la constante pour que la prochaine fois le fichier ne soit pas inclus

#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_MAX_CODE 12
#define TAILLE_MAX_CHAINE 12
#define TAILLE_DICO 256
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

void display();

void displaySSCell(cell* ssdico);

#endif
