#include "../include/dictionnaire.h"
#include "../include/gestion_fichier.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void concat( char * dest, char reste)

{

char temp[2];
temp[0]=reste;
temp[1]='\n';
strcat(dest, temp);

}

void decode()
{
	unsigned int c;
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
		taille= getSize();
		code = lire_code(taille);

		if(code != 257) //pour pas écrire le EOF
		{
			if(getCharByCode(code) == NULL)  {// si temp n'est pas dans le dico
				strcpy(temp,chaine);
				concat(temp, chaine[0]);
				strcpy(entree,temp);
			}
			else
				entree = getCharByCode(code);
			
			ecrire_char(entree);
			concat (chaine, entree[0]);
			add(chaine);
			strcpy(chaine,entree);
		}
	}

}
 
