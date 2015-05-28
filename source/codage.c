#include "../include/codage.h"

int codage() {
	char Cc[10] = premierCaractère();
	char Cn;
	char * concat[11];

	int tailleActuelle = getSize();

	while(Cc != 257) { // A modifier -> erreur
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

void ecrireCode(char * chaine, int tailleActuelle) {
	int taille = getSize();

	if (tailleActuelle < taille) {
		
	}
}