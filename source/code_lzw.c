#include "dictionnaire.h"
#include "gestion_fichier.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void concat( char * dest, char reste)

{

char temp[2];
temp[0]=reste;
temp[1]='\n';
strcat(dest, temp);

}

void code(){

	#ifdef DEBUG
		printf("Début de l'initialisation\n");
	#endif

	init();

	#ifdef DEBUG
		printf("Fin de l'initialisation\n");
	#endif

	char c;
	int taille;
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char)); 
	char * temp = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	uint16_t code;
	
	c = lire_char();
	sprintf(temp, "%c",c);
	strcpy(chaine,temp);
	
	while(eof() != 0)
	{
		c = lire_char();
		strcpy(temp,chaine);
		concat(temp, c);
		if (isExist(temp) >= 0)
			chaine = temp;
		else
		{
			taille = getSize();
			code = getCodeByChar(chaine);
			ecrire_code(code,taille);
			concat(chaine, c);
			add(chaine);
			sprintf(chaine, "%c",c);
		
		} 
		
		#ifdef DEBUG
			printf("\n\n");
		#endif
	
	}

	taille = getSize();
	code = getCodeByChar(chaine);
	ecrire_code(code,taille);	
	code = 257; 
	fin_de_fichier(code,taille);
	free(chaine);
	free(entree);
	free(temp);
	
	#ifdef DEBUG
		printf("Fin du programme\n");
	#endif

}


int main(int argc, char* argv[]){

    
    // Lecture des arguments sur la ligne de commande
    
    if ( argc != 3 ){
        fprintf(stderr,"vous n'avaez pas saisi les bons arguments :\n\tex: code_lwz fichier.txt sortie\n");
        exit(EXIT_FAILURE);
    }
    
    if(init_fichier_compression(argv[1], argv[2]) < 0)
    {
        fprintf(stderr,"Erreur lors de l'ouverture de fichier \n");
        exit(1);
    }
    else
    	code();
    	
    close();	
   return 0;

}
    



