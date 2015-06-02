#include "decode_lzw.h"

void concat_decode( char * dest, char reste) {
	char temp[2];
	temp[0] = reste;
	temp[1] = '\0';
	strcat(dest,temp);
}

void decode() {

    int taille = getSize('c');
    int nextCode;
    int code = lire_code(taille);
    //printf("On lit le code : %i en char : |%s\\0 avec une taille : %i\n",code,getCharByCode(code),taille);
    char* octet = malloc(sizeof(char)*2);
    char* chaine = malloc(sizeof(char)*TAILLE_MAX_CHAINE);

    strcpy(octet,getCharByCode(code));
    octet[1] = '\0';
    strcpy(chaine,octet);
    ecrire_char(chaine);
    while(code != CODE_EOF)
    {
        taille = getSize('d');
        nextCode = lire_code(taille);
        //printf("SizeOfDico : %i\nOn lit le code : %i en char : |%s\\0 avec une taille : %i\n",sizeOfDico,nextCode,getCharByCode(nextCode),taille);
        char* nextChaine = malloc(sizeof(char)*TAILLE_MAX_CHAINE);

        if(getCharByCode(nextCode) == NULL)
        {
            strcpy(nextChaine,getCharByCode(code));
            strcat(nextChaine,octet);
        } else {
            strcpy(nextChaine,getCharByCode(nextCode));
        }

        ecrire_char(nextChaine);
        octet[0] = nextChaine[0];
        chaine = strcat(chaine,octet);
        //if(code == 294){printf("On ajoute 296 ! |%s\\0\n",chaine);}
        add(chaine);
        chaine = malloc(sizeof(char)*TAILLE_MAX_CHAINE);
        code = nextCode;
        //printf("Le nouveau code est : %i\n",code);
        strcpy(chaine,getCharByCode(code));
    }
    //display();

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
