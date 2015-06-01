#include "gestion_fichier.h"

#define MAX_BUFFER 32

static FILE* fin;
static FILE* fout;

static int fdf;

static uint32_t buffer;
static int nb_buf;

int init_fichier_compression(char * nom_fin, char * nom_fout) {
	#ifdef DEBUG
		printf("Debut init_fichier_compression\n");
	#endif
	
	fin = NULL;
	fout = NULL;
	fdf = -1;
	nb_buf = 0;
	buffer = 0x00000000;

	int e = 0;

	char * ajout_fin = malloc (sizeof(char) * (strlen(nom_fin) + 3));
	strcpy(ajout_fin,"../");
	char * ajout_fout = malloc (sizeof(char) * (strlen(nom_fout) + 3));
	strcpy(ajout_fout,"../");

	strcat(ajout_fin,nom_fin);
	strcat(ajout_fout,nom_fout);

	#ifdef DEBUG
		printf("Nom final du fichier fin : %s\n", ajout_fin);
		printf("Nom final du fichier fout : %s\n", ajout_fout);
	#endif

	fin = fopen(nom_fin,"r");
	fout = fopen(nom_fout,"wb+");

	if (fin == NULL || fout == NULL)
		e--;

	#ifdef DEBUG
		printf("Fin init_fichier_compression\n");
	#endif
		
	return e;
}

int init_fichier_decompression(char * nom_fin, char * nom_fout) {
	#ifdef DEBUG
		printf("Debut init_fichier_decompression\n");
	#endif
	
	fin = NULL;
	fout = NULL;
	fdf = -1;
	nb_buf = 0;
	buffer = 0x00000000;

	int e = 0;

	char * ajout_fin = malloc (sizeof(char) * (strlen(nom_fin) + 3));
	strcpy(ajout_fin,"../");
	char * ajout_fout = malloc (sizeof(char) * (strlen(nom_fout) + 3));
	strcpy(ajout_fout,"../");

	strcat(ajout_fin,nom_fin);
	strcat(ajout_fout,nom_fout);

	#ifdef DEBUG
		printf("Nom final du fichier fin : %s\n", ajout_fin);
		printf("Nom final du fichier fout : %s\n", ajout_fout);
	#endif

	fin = fopen(nom_fin,"rb");
	fout = fopen(nom_fout,"w+");

	if (fin == NULL || fout == NULL)
		e--;

	#ifdef DEBUG
		printf("Fin init_fichier_decompression\n");
	#endif
		
	return e;
}

void close() {
	fclose(fin);
	fclose(fout);
}

int eof() {
	return fdf;
}

void ecrire_char(char * chaine) {
	fputs(chaine, fout);
}

void ecrire_code(uint16_t code, int taille) { // Gestion de fin de fichier -> si le buffer est encore plein
	uint16_t write_buffer = 0x0000;
	uint32_t masque;

	#ifdef DEBUG
		printf("Buffer d'ecriture : %04x\n", write_buffer);
		printf("Code : %04x\n", code);
	#endif

	buffer = (buffer << taille) | code;

	nb_buf = nb_buf + taille;

	#ifdef DEBUG
		printf("Buffer : %08x et nb_buf = %d\n", buffer, nb_buf);
	#endif

	//int i;
	while (nb_buf >= 16) {
		nb_buf = nb_buf - 16;

		masque = 0x0000ffff << nb_buf;

		#ifdef DEBUG
			printf("Ecriture dans le fichier\n");
		#endif

		write_buffer = (buffer & masque) >> nb_buf;

		#ifdef DEBUG
			printf("Buffer : %08x et nb_buf = %d\n", buffer, nb_buf);
			printf("Buffer d'ecriture : %04x\n", write_buffer);
		#endif

		buffer = buffer & ~masque;

		#ifdef DEBUG
			printf("Buffer apres deplacement: %08x\n", buffer);
		#endif

		fwrite(&write_buffer,sizeof(uint16_t),1,fout);
	}

	#ifdef DEBUG
		printf("\n\n");
	#endif
}

void fin_de_fichier(uint16_t code, int taille) {
	uint16_t write_buffer = 0x0000;
	uint32_t masque;
	int dep;

	buffer = (buffer << taille) | code;

	nb_buf = nb_buf + taille;

	while(nb_buf > 0) {
		if (nb_buf >= 16) { nb_buf = nb_buf - 16; dep = 0; } else { dep = 16 - nb_buf; nb_buf = 0; }

		masque = 0x0000ffff << nb_buf;

		#ifdef DEBUG
			printf("Ecriture dans le fichier\n");
		#endif

		write_buffer = ((buffer << dep) & masque) >> nb_buf;

		#ifdef DEBUG
			printf("Buffer : %08x et nb_buf = %d\n", buffer, nb_buf);
			printf("Buffer d'ecriture : %04x\n", write_buffer);
		#endif

		buffer = buffer & ~masque;

		#ifdef DEBUG
			printf("Buffer apres deplacement: %08x\n", buffer);
		#endif

		fwrite(&write_buffer,sizeof(uint16_t),1,fout);
	}

	#ifdef DEBUG
		printf("\n\n");
	#endif

}

int lire_char() {
	int car = 0;
	if (fdf != 0) {
		car = fgetc(fin);
		
		if(car == EOF) { fdf = 0; car = -1; }
	
	} else { car = -1; }

	return car;
}

unsigned int lire_code(int taille) { // Rajout modification de fdf
	uint16_t reader_buffer = 0x0000;
	uint32_t masque = 0xffffffff;
	unsigned int code;

	if (nb_buf < taille) {

		fread (&reader_buffer,sizeof(uint16_t),1,fin);

		buffer = (buffer << 16) | reader_buffer;
		nb_buf = nb_buf + 16;

		#ifdef DEBUG
			printf("Buffer de lecture : %04x\n", reader_buffer);
			printf("Buffer : %08x et nb_buf = %d\n", buffer, nb_buf);
		#endif

		if (feof(fin)) {
			fdf = 0;
			#ifdef DEBUG
				printf("Arrive en fin du fichier, fdf = %d\n", fdf);
			#endif
		}

	}

	nb_buf = nb_buf - taille;

	masque = (~(masque << taille)) << nb_buf;

	code = (buffer & masque) >> nb_buf;

	buffer = buffer & ~masque;

	#ifdef DEBUG
		printf("Masque : %08x\n", masque);
		printf("Code obtenu : %04x\n", code);
		printf("Buffer : %08x et nb_buf = %d\n", buffer, nb_buf);
		printf("\n");
	#endif

	return code;
}
