#include "dictionnaire.h"

////////////////////////////////////////////////////////////////
// Author : Quentin
//
char* getCharByCode(unsigned int c){
    return hashmap[c]->string;
}

////////////////////////////////////////////////////////////////
// Author : Quentin
//
unsigned int getCodeByChar(char* c)
{
    return isExist(c);
}


////////////////////////////////////////////////////////////////
void add(char* c)
{
    if (c != NULL)
    {
        if(isExist(c)<0)
        {
            int currentNode = 1;
            int insert = 0;
            char* researchString = malloc(sizeof(c));
            researchString[0] = c[0];

            // on recupËre les cell pour le parcours
            cell* currentCell = dico[researchString[0]];
            cell* previousCell = currentCell;

            // On prepare notre nouvelle cell
            cell* newCell = malloc(sizeof(cell*));
            newCell->string = c;
            newCell->code = sizeOfDico;
            sizeOfDico++;
            newCell->next = NULL;
            newCell->down = NULL;

            if (currentCell == NULL)
            {
                // Il n'y aucune cellule, on rajoute directement la nouvelle cellule
                dico[researchString[0]] = newCell;
            } else {
                // Il existe deja des cellules, on cherche le bon emplacement
                while(currentNode < strlen(c) && insert == 0)
                {
                    strcat(researchString, &c[currentNode]);
                    currentNode++;
                    while(strcmp(researchString,currentCell->string)>0 && currentCell != NULL)
                    {
                        previousCell = currentCell;
                        currentCell = currentCell->next;
                    }
                    if (currentCell == NULL)
                    {
                        // On a trouve l'endroit ou inserer la cell, on insert forcement en next
                        if(strlen(c)>currentNode)
                        {
                            // L'insertion est impossible -> probleme dans l'execution
                            return;
                        } else {
                            // On insert en next
                            previousCell->next = newCell;
                            insert++;
                        }
                    } else {
                        // On verifie si la cellule courante correspond ‡ researchString
                        // Si c'est le cas on fait un down et on recherche plus bas
                        // Sinon, on doit faire une insertion.
                        if(strcmp(currentCell->string,researchString) == 0) {
                            // On recherche plus bas
                            if(currentCell->down == NULL) {
                                // Il n'existe pas de cell en bas, on fait donc l'insertion
                                currentCell->down = newCell;
                            } else  {
                                // Il existe des cell en bas, on recommence une recherche
                                currentCell = currentCell->down;
                            }

                        } else {
                            // On fait une insertion de la nouvelle cell dans la liste
                            newCell->next = currentCell;
                            previousCell->next = newCell;
                            insert++;
                        }

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
    return log(sizeOfDico)/log(2);
}

////////////////////////////////////////////////////////////////
// Author : Quentin
void init(){
    int i = 0;
    for(i;i<TAILLE_DICO;i++) {
        //dico[i].car = (i<256)?:char(i):null;
        dico[i] = malloc(sizeof(cell));
    }
}

////////////////////////////////////////////////////////////////
int isExist(char* c){
    int sizec = strlen(c); //convertion automatique de size_t en int
    int i, j;
    cell* newdico = malloc(sizeof(cell*));
    char* newc = malloc(sizeof(c));
    newc[0] = c[0];


    /**On parcours la chaine de caractere*/
    for (i=0; i < sizec; i++){

        /**On parcourt le tableau pour trouver le premier caracteres*/
        for (j=0; j < TAILLE_DICO; j++) {

            if (j == c[i]){
                // Si on trouve le premier caractere et que celui ci etait l'unique caractere de la chaine on retourne le code
                 if (sizec == 1) {
                     return j;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down est null alors la chaine ne se trouve pas dans le dictionnaire
                 else if (dico[j]->down == NULL) {
                     return -1;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down n'est pas null alors on poursuit la recherche
                 else {
                     newdico = dico[j]->down; //on recupere un pointeur vers la bonne liste chainee
                     break ; // on sort de la boucle for(j=0, j < 259, j++)
                 }
            }

            /** Si on n'a pas trouve le premier caractere dans le tableau de 259 elements, alors la chaine ne se trouve pas dans le dictionnaire */
            if (j == TAILLE_DICO && j != c[i]) {
            return -1;
            }

            /**On parcours les listes chaines pour trouver la chaine de caractere*/
            newc = strcat(newc, &c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
                //Si la chaine de caractere ne correspond pas au champ car on poursuit la recherche tant que next pointe vers la suite de la liste chainee
                while (newdico->string != (*newc) && newdico->next != NULL) {
                    newdico = newdico->next ;
                }
                //Si la chaine de caractere ne correspond pas au champ car et que le champ next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
                if( newdico->string != (*newc) && newdico->next == NULL) {
                    return -1;
                }
                //Si la chaine de caractere correspond au champ car et que sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
                else if (newdico->string == (*newc) && strlen(newc)==sizec) {
                    return newdico->code;
                }
                //Si la chaine de caractere correspond au champ car et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
                else if (newdico->string == (*newc) && newdico->down != NULL) {
                    newdico = newdico->down;
                    continue; //on passe a l'itération suivante
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

