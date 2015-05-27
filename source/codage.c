#include "../include/codage.h"

int codage() {
	char * Cc[10] = premierCaractère();
	char Cn[10];
	char * concat[20];

	while(Cc != 257) {
		Cn = lectureCaractère();
		concat = strcat(Cc,Cn);
		if(isExist(concat)) {
			Cc = concat;
		} else {
			ecrireCode(Cc);
			add(concat);
			Cc = Cn;
		}
	}

	ecrireCode(Cc);
}

void ecrireCode(char * chaine) {
	//test sur taille du dictionnaire 
}