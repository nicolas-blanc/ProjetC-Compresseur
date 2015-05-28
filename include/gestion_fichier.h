#include <stdio.h>
#include <stdlib.h>

static File * fin;
static File * fout;

static char * nom_fin;
static char * nom_fout;

int init_fichier(char * nom_in, char * nom_out);

void close();

void ecrire_char(char * chaine);

void ecrire_code(unsigned int code);

char lire_char();

unsigned int lire_code(int taille);