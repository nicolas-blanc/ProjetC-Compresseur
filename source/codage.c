#include "../include/codage.h"

int codage() {
	char Cc[10] = premierCaractère();
	char Cn[1];
	char * concat[11];

	int tailleActuelle = getSize();

	while(Cc != 257) { // A modifier -> erreur
		Cn[0] = lectureCaractère();
		concat = strcat(Cc,Cn[0]); // Faux, Cn est modifié
		if(isExist(concat)) {
			Cc = concat;
		} else {
			ecrireCode(Cc);
			add(concat);
			Cc = Cn[0];
		}
	}

	ecrireCode(Cc);
}

void ecrireCode(char * chaine, int tailleActuelle) {
	int taille = getSize();

	if (tailleActuelle < taille) {
		
	}
}