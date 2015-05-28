#define TAILLE_MAX_CODE 12

typedef struct cell {
char* string;
unsigned int code;
struct cell* next;
struct cell* down;
} cell;


typedef struct tab {
char car;
unsigned int code;
cell* down;
} tab;


tab Dico[258];
// case 256: taille, case 257: EOF, case 258: bit clear (reset dico)

////////////////////////////////////////////////////////////////
// Author : Coralie
//
int get(char c);

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
//
void growSize();

////////////////////////////////////////////////////////////////
// Author : Quentin
//
void init();

////////////////////////////////////////////////////////////////
// Author : Coralie
//
int isExist(char c);



