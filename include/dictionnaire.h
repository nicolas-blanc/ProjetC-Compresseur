#include <cmath>
#include <string.h>
#define TAILLE_MAX_CODE 12



typedef struct cell {
char* string;
unsigned int code;
cell* next;
cell* down;
} cell;

/*
typedef struct tab {
cell* down;
} cell_tab;
*/

typedef struct cell* TabCode[4096]

typedef cell* Dico[258];


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
void add(char c);

////////////////////////////////////////////////////////////////
// Author : Coralie
//
int getSize();

////////////////////////////////////////////////////////////////
// Author : Quentin
// Spe : Initialise le dictionnaire
void init();

////////////////////////////////////////////////////////////////
// Author : Quentin
//
bool isExist(char c);

////////////////////////////////////////////////////////////////
// Author : Quentin
//
void reset();

// Variable global //
Dico dico = init();
TabDico hashmap;
int sizeOfDico = 258;
