#include "dictionnaire.h"
#include "gestion_fichier.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void concat_decode( char * dest, char reste) {
	strcat(dest,&reste);
}

void decode()
{

	int taille;
	uint16_t code; //int pour gérér les codes >255
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * temp = malloc( TAILLE_MAX_CHAINE * sizeof(char));

	init();
	taille= getSize();
	code = lire_code(taille); // TODO : lire_code : ok
	chaine = getCharByCode(code);

	ecrire_char(chaine);
	while(code != 257)
	{
		#ifdef DEBUG
			printf("-------------------- Nouvelle boucle --------------------\n");
		#endif

		taille= getSize();
		code = lire_code(taille);

		if(code != 257) //pour pas écrire le EOF
		{
			if(getCharByCode(code) == NULL)  {// si temp n'est pas dans le dico
				strcpy(temp,chaine);
				concat_decode(temp, chaine[0]);
				strcpy(entree,temp);
			}
			else
				entree = getCharByCode(code);

			#ifdef DEBUG
				printf("Chaine a ecrire dans le fichier : %s/\n\n", entree);
			#endif

			ecrire_char(entree);
			concat_decode(chaine, entree[0]);

			#ifdef DEBUG
				printf("Chaine ajoute dans le dico : %s/\n", chaine);
			#endif

			if (code != 257) {
                add(chaine);
                chaine = malloc(sizeof(char)*TAILLE_MAX_CHAINE);
			}

			strcpy(chaine,entree);
		}

		#ifdef DEBUG
			printf("\n---------------------------------------------------------\n\n");
		#endif

	}
	//free(chaine);
	//free(entree);
	//free(temp);

}

/*
int main(int argc, char* argv[]){


    // Lecture des arguments sur la ligne de commande

    if ( argc != 3 ){
        fprintf(stderr,"vous n'avez pas saisi les bons arguments :\n\ex: decode_lwz sortie fichier.txt\n");
        exit(EXIT_FAILURE);
    }

    if(init_fichier_decompression(argv[1], argv[2]) < 0)
    {
        fprintf(stderr,"Erreur lors de l'ouverture de fichier \n");
        exit(1);
    }
    else
    	decode();

    close();

   return 0;

}
*/
