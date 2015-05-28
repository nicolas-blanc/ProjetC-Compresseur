#include ../include/dictionnaire.h

////////////////////////////////////////////////////////////////
// Author : Quentin
//
char* getCharByCode(unsigned int c){
    return hashmap[c].string;
}

////////////////////////////////////////////////////////////////
// Author : Quentin
//
unsigned int getCodeByChar(char* c){
    return isExist(c);
}


////////////////////////////////////////////////////////////////
void add(char* c){
    if (c != null){
        if(isExist(c)<0){
            int currentNode = 1;
            char* researchString = malloc(sizeof(c));
            researchString = c[0];

            // on recupËre les cell pour le parcours
            cell* currentCell = dico[researchString];
            cell* previousCell = currentCell;

            // On prepare notre nouvelle cell
            cell* newCell = malloc(sizeof(cell*));
            newCell->string = c;
            newCell->code = sizeOfDico;
            sizeOfDico++;
            newCell->next = null;
            newCell->down = null;

            if (currentCell == null) {
                // Il n'y aucune cellule, on rajoute directement la nouvelle cellule
                dico[researchString] = newCell;
            } else {
                // Il existe deja des cellules, on cherche le bon emplacement
                while(currentNode < strlen(c)) {
                    strcat (researchString, c[currentNode]);
                    currentNode++;
                    while(strcmp(researchString,currentCell->String)>0 && currentCell != null) {
                        previousCell = currentCell;
                        currentCell = currentCell->next;
                    }
                    if (currentCell == null) {
                        // On a trouve l'endroit ou inserer la cell. Il nous faut determiner si on l'insert en next ou en down
                        if(strlen(c)>currentNode) {
                            // On insert en down
                            previousCell->down = newCell;
                        } else {
                            // On insert en next
                            previousCell->next = newCell;
                        }
                    } else {
                        // On verifie si la cellule courante correspond ‡ researchString
                        // Si c'est le cas on fait un down et on recherche plus bas
                        // Sinon, on doit faire une insertion.

                    }
                }
            }
        } else {
            // Le mot existe deja dans le dico
        }

    } else {
        // Argument null, on ne fait rien
    }

}

////////////////////////////////////////////////////////////////
// Author : Quentin
int getSize(){
    return log(sizeOfDico)/log(2)
}

////////////////////////////////////////////////////////////////
// Author : Quentin
void init();
    dico = malloc(sizeof(dico));
    int i = 0;
    for(i;i<259;i++) {
        //dico[i].car = (i<256)?:char(i):null;
        dico[i] = malloc(sizeof(cell));
    }
}

////////////////////////////////////////////////////////////////
int isExist(char * c){
    int sizec = strlen(c); //convertion automatique de size_t en int
    int i, j;

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
                     new Dico * newdico = d[j]->down; //on recupere un pointeur vers la bonne liste chainee
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

////////////////////////////////////////////////////////////////
// Author : Quentin
void reset(){
    int i = 0;
    for(i;i<sizeOfDico;i++){
        free(hashmap[i]);
    }
    init();
}

