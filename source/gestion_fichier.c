#include "gestion_fichier.h"

static File * fin;
static File * fout;

int init_fichier(char * nom_fin, char * nom_fout) {
	FILE* fopen(const char* nomDuFichier, const char* modeOuverture);

	char * nom_in = 
	nom_in = strcat("")

	fin = fopen(nom_fin,"r")
}

void close() {

}

void ecrire_char(char * chaine) {
/*	fwrite(&c,1,NB_TO_WRITE,f);
	fflush(f);
	return;*/

}

void ecrire_code(unsigned int code) {

}

char lire_char() {
/*	char res;
	res = fread(&res,1,NB_TO_READ,f);
	return res;
*/
}

unsigned int lire_code(int taille) {

}