#include "dictionnaire.h"
#include <stdio.h>
#include <string.h>


void concat( char * dest, char reste)

{

char temp[2];
temp[0]=reste;
temp[1]="\n";
strcat(dest, temp);

}


void decode()
{
	unsigned int c;
	int taille;
	unsigned int  code; //int pour gérér les codes >255
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char)); 
	
	init_dico();
	//taille= getSize();
	code = lire_code(); // TODO: fonction lire_code qui lit (taille) bits correspondant aux bits significatifs du code et renvoie la 		valeur en int du code
	chaine = find_string(code); //TODO: find_string qui renvoie la chaine qui correspond au code dans le dico
	
	ecrire_char(chaine);
	while(code != 257)
	{	
		//taille= getSize();
		code = lire_code();
		if(!isExist(code)) // TODO : fonction isExistcode qui prend un unsigned int et renvoie 1 si code existe dans D
		
			entree = concat(chaine, chaine[0]);
		else
			entree = find_string(code);
			
		ecrire_char(entree);
		add( concat (chaine, entree[0]) );
		chaine = entree;
		
	}

return;

}
 
