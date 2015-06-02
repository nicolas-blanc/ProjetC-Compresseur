#include "code_lzw.h"

/*==============ALGO =======================
  initialize table: 0 to 255 = code for individual bytes
  string= get input symbols
  while theree are still input symbols
	symbol= get input symbol
	if STRING + SYMBOL is in TABLE:
		STRING = STRING + SYMBOL
	else:
		output the code for STRING
		add STRING + SYMBOL to TABLE
		STRING = SYMBOL
  output the code for STRING
//==========================================*/

void concat_code( char * dest, char reste) {
	char temp[2];
	temp[0] = reste;
	temp[1] = '\0';
	strcat(dest,&reste);
}

void code() {

	#ifdef DEBUG
		printf("Debut de l'initialisation\n");
	#endif

	init();

	#ifdef DEBUG
		printf("Fin de l'initialisation\n");
	#endif

	char c;
	int taille;
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	//char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * temp = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	uint16_t code;

	c = lire_char();
	sprintf(temp, "%c",c);
	strcpy(chaine,temp);

	while(eof() != 0)
	{
		#ifdef DEBUG
			printf("-------------------- Nouvelle boucle --------------------\n");
		#endif

		c = lire_char();
		//printf("Caractere lu : %c/\n", c);

			printf("Chaine : %s/\n", chaine);

			strcpy(temp,chaine);
			concat_code(temp, c);

			#ifdef DEBUG
				printf("c : %c/ // Concatener : %s/ // Chaine : %s/\n", c, temp, chaine);
			#endif

			if (isExist(temp) >= 0)
			{
				strcpy(chaine,temp);
				#ifdef DEBUG
					printf("Ancienne chaine : %s/ // Nouvelle Chaine : %s/\n", temp, chaine);
				#endif

			}
			else
			{
				taille = getSize();

				printf(" ------------------------- Chaine : %s/\n", chaine);

				code = getCodeByChar(chaine);

				#ifdef DEBUG
					printf("Chaine : %s/ ,Code a ecrire (hexa) : %04x, Code a ecrire (Decimal) : %d, taille : %d\n",chaine, code, code, taille);
				#endif

				ecrire_code(code,taille);
				concat_code(chaine, c);
				add(chaine);
                chaine =  malloc(TAILLE_MAX_CHAINE * sizeof(char));
				#ifdef DEBUG
					taille = getSize();
					code = getCodeByChar(chaine);
					printf("Chaine ajoute : %s/, nouvelle taille : %d\n",chaine, taille);
				#endif

				sprintf(chaine, "%c",c);
			}

			#ifdef DEBUG
				printf("\n---------------------------------------------------------\n\n");
			#endif
		//}
	}

	taille = getSize();
	code = getCodeByChar(chaine);

	#ifdef DEBUG
		printf("Code a ecrire : %04x, taille : %d\n", code, taille);
	#endif

//	ecrire_code(code,taille);

	fin_de_fichier(257,taille);
//	fin_de_fichier(CODE_EOF,taille);

	//free(chaine);
	//free(entree);
	//free(temp);

	#ifdef DEBUG
		display();
		printf("Fin du programme\n");
	#endif

}

/*
int main(int argc, char* argv[]){
    // Lecture des arguments sur la ligne de commande
    if ( argc != 3 ){
        fprintf(stderr,"vous n'avez pas saisi les bons arguments :\n\tex: code_lwz fichier.txt sortie\n");
        exit(EXIT_FAILURE);
    }
    if(init_fichier_compression(argv[1], argv[2]) < 0)
    {
        fprintf(stderr,"Erreur lors de l'ouverture de fichier \n");
        exit(1);
    }
    else
    	code();

    // display();
    close();
   return 0;
}
*/