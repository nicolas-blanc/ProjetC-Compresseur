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
    for (i=0, i <= sizec, i++){
        for (j=0, j < 259, j++) {
            if (d[j]-> car == c[i]){
                 if (nbcar == 1) {
                     return 1;
                 }
                 else if (d[j]->down == NULL) {
                     return 0;
                 }
                 else /*(d[j]->down != NULL)*/ {
                     //recursion avec c privé du premier élément
                 }
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
