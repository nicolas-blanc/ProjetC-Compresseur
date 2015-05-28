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
	char taille;
	unsigned int  code; //int pour gérér les codes >255
	char * chaine = malloc( TAILLE_MAX_CHAINE * sizeof(char));
	char * entree = malloc( TAILLE_MAX_CHAINE * sizeof(char)); 
	dico d;
	init_dico(d);
	taille= getSize();
	code = lire_code(taille); // TODO: fonction lire_code qui lit (taille) bits correspondant aux bits significatifs du code et renvoie la valeur en int du code
	chaine = find_string(code);
	
	ecrire_caractere(chaine);
	while(code != 257)
	{	
		taille= getSize();
		code = lire_code(taille);
		if(!isExist(code)) // TODO : fonction isExistcode qui prend un unsigned int et renvoie 1 si code existe dans D
		
			entree = concat(chaine, chaine[0]);
		else
			entree = find_string(code);
			
		ecrire_caractere(entree);
		add( concat (chaine, entree[0]) );
		chaine = entree;
		
	}

return;

}
 
