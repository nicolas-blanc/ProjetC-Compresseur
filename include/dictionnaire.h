#include <math.h>
#include <string.h>
#define TAILLE_MAX_CODE 12
#define TAILLE_DICO 259



typedef struct cell {
char* string;
unsigned int code;
struct cell* next;
struct cell* down;
} cell;

/*
typedef struct tab {
cell* down;
} tab;

tab Dico[258];
} cell_tab;
*/

typedef struct cell* TabCode[4096];

typedef cell* Dico[TAILLE_DICO];
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


// Variable global //
Dico dico;
TabCode hashmap;
int sizeOfDico = 258;
