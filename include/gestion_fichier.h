#include <stdio.h>
#include <stdlib.h>

int lecture_fichier(char * nom_in, char * nom_out);

void ecriture_fichier (char * nom_in, char * nom_out);

void close();

int non_EOF();

void ecrire_char(char * chaine, int taille);

void ecrire_code(unsigned int code, int taille);

char lire_char();

unsigned int lire_code(int taille);

