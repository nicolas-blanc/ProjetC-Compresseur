#include <stdio.h>
#include <stdlib.h>

int init_fichier(char * nom_in, char * nom_out);

void close();

void ecrire_char(char * chaine);

void ecrire_code(unsigned int code);

char lire_char();

unsigned int lire_code(int taille);