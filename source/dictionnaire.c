#include "../include/dictionnaire.h"
#include <string.h>

////////////////////////////////////////////////////////////////
int get(char * c){

}

////////////////////////////////////////////////////////////////
int getchaine(unsigned int c){

}

////////////////////////////////////////////////////////////////
void add(char c){

}

////////////////////////////////////////////////////////////////
int getSize(){

}

////////////////////////////////////////////////////////////////
void growSize(){

}

////////////////////////////////////////////////////////////////
int init_dico(){

}

////////////////////////////////////////////////////////////////
int isExist(char * c){
    int sizec = strlen(c); //convertion automatique de size_t en int
    int i, j;
    Dico * newdico = d;

    /**On parcours la chaine de caractere*/
    for (i=0; i < sizec; i++){

        /**On parcourt le tableau pour trouver le premier caracteres*/
        for (j=0; j < 259; j++) {

            if (d[j]->car == c[i]){
                // Si on trouve le premier caractere et que celui ci etait l'unique caractere de la chaine on retourne le code
                 if (sizec == 1) {
                     return d[j]->code;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down est null alors la chaine ne se trouve pas dans le dictionnaire
                 else if (d[j]->down == NULL) {
                     return -1;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down n'est pas null alors on poursuit la recherche
                 else {
                     newdico = d[j]->down; //on recupere un pointeur vers la bonne liste chainee
                     break ; // on sort de la boucle for(j=0, j < 259, j++)
                 }
            }

            /** Si on n'a pas trouve le premier caractere dans le tableau de 259 elements, alors la chaine ne se trouve pas dans le dictionnaire */
            if (j == 259 && d[j].car != c[i]) {
            return -1;
            }

            /**On parcours les listes chaines pour trouver la chaine de caractere*/
            char * newc = strcat(c[i], c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
                //Si la chaine de caractere ne correspond pas au champ car on poursuit la recherche tant que next pointe vers la suite de la liste chainee
                while (newdico->car != (*newc) && newdico->next != NULL) {
                    newdico = newdico->next ;
                }
                //Si la chaine de caractere ne correspond pas au champ car et que le champ next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
                if( newdico->car != (*newc) && newdico->next == NULL) {
                    return -1;
                }
                //Si la chaine de caractere correspond au champ car et que sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
                else if (newdico->car == (*newc) && strlen(newc)==sizec) {
                    return newdico->code;
                }
                //Si la chaine de caractere correspond au champ car et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
                else if (newdico->car == (*newc) && newdico->down != NULL) {
                    newdico = newdico->down;
                    Break; //on passe a l'itération suivante
                }
                //Si la chaine de caractere ne correspond pas au champ car et que le champ down point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
                else {
                    return -1;
                }
        }
    }
}
