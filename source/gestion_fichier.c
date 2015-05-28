#include "gestion_fichier.h"

#define MAX_BUFFER 26

static File * fin;
static File * fout;

static int fdf;

static int buffer[MAX_BUFFER];
static int nb_buf;

int init_fichier_compression(char * nom_fin, char * nom_fout) {
	fin = NULL;
	fout = NULL;
	fdf = -1;
	nb_buf = 0;

	int e = 0;

	char * ajout_fin = "../";
	char * ajout_fout = "../";

	ajout_fin = strcat(ajout_fin,nom_fin);
	ajout_fout = strcat(ajout_fout,nom_fout);

	fin = fopen(nom_fin,"r");
	fout = fopen(nom_fout,"wb+");

	if (fin == NULL || fout == NULL)
		e--;
		
	return e;
}

int init_fichier_compression_decompression(char * nom_fin, char * nom_fout) {
	fin = NULL;
	fout = NULL;
	fdf = -1;
	nb_buf = 0;

	int e = 0;

	char * ajout_fin = "../";
	char * ajout_fout = "../";

	ajout_fin = strcat(ajout_fin,nom_fin);
	ajout_fout = strcat(ajout_fout,nom_fout);

	fin = fopen(nom_fin,"rb");
	fout = fopen(nom_fout,"w+");

	if (fin == NULL || fout == NULL)
		e--;
		
	return e;
}

void close() {
	fclose(fin);
	fclose(fout);
}

int EOF() {
	return fdf;
}

void ecrire_char(char * chaine) {
	fputs(chaine, fout);
}

void ecrire_code(unsigned int code, int taille) {
	char write_buffer[2];
	
	int masque = 0x0001;

	for (int j = 0; j < taille; j++) {
		buffer[nb_buf+j] = masque & code;
		masque = masque << 2;
	}

	nb_buf = nb_buf + taille;

	while (nb_buf >= 15) {
		for (int i = 0; i < 16; i++)
			write_buffer[abs(i/8)] = write_buffer[abs(i/8)] | (buffer[i] << pow(2,i));

		for (i; i < MAX_BUFFER; i++)
			buffer[i-16] = buffer[i];

		nb_buf = nb_buf - 16;

		fwrite(write_buffer,sizeof(char),2,fout);
	}
}

int lire_char() {
	int car = fgetc(fin);
	
	if(car == EOF) {
		fdf = 0;
		car = -1;
	}

	return car;
}

unsigned int lire_code(int taille) {

}