#define TAILLE_MAX_CODE 12

typedef struct cell {
char * chaine;
unsigned int code;
cell * suite_mm_taille;
cell * suite_taille_plus1;

}cell;


typedef struct cell_tab {
char car;
unsigned int code_car;
cell suite_taille_plus1;
} cell_tab;


typedef cell_tab dico [259] dico;
// case 256: taille, case 257: EOF, case 258: bit clear (reset dico)

////////////////////////////////////////////////////////////////
int get(char c);

////////////////////////////////////////////////////////////////
void add(char c);

////////////////////////////////////////////////////////////////
int getSize();

////////////////////////////////////////////////////////////////
void growSize();

////////////////////////////////////////////////////////////////
int init_dico(dico d);

////////////////////////////////////////////////////////////////
bool isExist(char c);



