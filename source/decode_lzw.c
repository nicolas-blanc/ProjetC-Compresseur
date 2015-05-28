#include "dictionnaire.h"
#include <stdio.h>
#include <string.h>


void concat( char * dest, char reste)

{

char temp[2];
temp[0]=reste;
temp[1]="\n";
strcat(dest, temp);
return;
}

void decode()
{
	unsigned int c;
	int taille;
	unsigned int  code; //int pour gérér les codes >255
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * temp = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char)); 
	
	init_dico();
	taille= getSize();
	code = lire_code(taille); // TODO : fonction lire_code qui renvoie la valeur en int du code
	chaine = getCharByCode(code); 
	
	ecrire_char(chaine);
	while(code != 257)
	{	
		taille= getSize();
		code = lire_code(taille);

		
		if(getCharByCode(code)) == NULL)  // si temp n'est pas dans le dico
		
			entree = concat(chaine, chaine[0]);
			
		else
			entree = find_string(code);
			
		ecrire_char(entree);
		add( concat (chaine, entree[0]) );
		chaine = entree;
		
	}

return;

}
 
