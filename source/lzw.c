#include "dictionnaire.h"
#include "gestion_fichier.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if ( argc != 4 ) {
		printf("Logiciel de compression et decompression de fichier contenant essentiellement des caractères ASCII avec la methode LZW\nCe programme prend trois arguments :\n");
		printf("\t- 'c' ou 'd' : En fonction de ce que dois faire le programme :\n\t\t'c' : Indique au programme de compresser le premier fichier dans le deuxieme fichier\n\t\t'd' : Indique au programme de decompresser le premier fichier dans le deuxieme fichier\n");
		printf("\t- Premier fichier : Entree le nom du fichier. C'est sur celui-ci que s'appliquera la fonction. (Mettre si le fichier est a compresser, sinon mettre seulement le nom de l'archive (sans l'extension '.z'))\n");
		printf("\t- Deuxieme fichier : Entree le nom du fichier. C'est le fichier final que rend la fonction. Attention, si le fichier existe, il sera ecrase. (Mettre l'extension si le fichier est a decompresser, sinon seulement le nom de l'archive)\n");
	} else {
		//if ( access(argv[2], 0) )
			if ( argv[1][0] == 'c' ) {

				#ifdef DEBUG
					printf("fin : %s // fout : %s\n", argv[2], argv[3]);
				#endif

				if(init_fichier_compression(argv[2], argv[3]) < 0) {
					fprintf(stderr,"Erreur lors de l'ouverture de fichier \n");
					exit(EXIT_FAILURE);
				}
				code();
				close();
			} else if ( argv[1][0] == 'd' ) {

				#ifdef DEBUG
					printf("fin : %s // fout : %s\n", argv[2], argv[3]);
				#endif

				if(init_fichier_decompression(argv[2], argv[3]) < 0) {
					fprintf(stderr,"Erreur lors de l'ouverture de fichier \n");
					exit(EXIT_FAILURE);
				}
				decode();
				close();
			} else {
				printf("Vous n'avez pas preciser la compression ou decompression\n\tAjouter 'c' ou 'd' pour indiquer ce que dois faire le programme en premier argument\n\t\t'c' : Indique au programme de compresser le premier fichier\n\t\t'd' : Indique au programme de decompresser le premier fichier\n");
			}
		//else
		//	printf("Le fichier saisi en entree n'existe pas\n");
	}

	return EXIT_SUCCESS;
}
