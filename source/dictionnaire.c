#include "../include/dictionnaire.h"
#define _DEBUG 0
#include <stdio.h>

int sizeOfDico = TAILLE_DICO;

////////////////////////////////////////////////////////////////
// Author : Quentin
//
char* getCharByCode(unsigned int c)
{
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
            char* researchString = malloc(sizeof(char)*strlen(c));
            researchString[0] = c[0];
            if(_DEBUG == 1)
            {
                printf("On ajout : %s\nResearchString : %s\n",c,researchString);
            }
            // on recupËre les cell pour le parcours
            cell* currentCell = dico[(int)researchString[0]];
            if(_DEBUG == 1)
            {
                printf("researchString[0] = %c en (int) = %i",researchString[0],(int)researchString[0]);
                if(currentCell == NULL) {
                    printf("\nc'est null\n");
                } else {
                    printf("String : %s",currentCell->string);
                }
            }
            //cell* previousCell = currentCell;

            // On prepare notre nouvelle cell
            cell* newCell = malloc(sizeof(cell));
            newCell->string = c;
            newCell->code = sizeOfDico;
            newCell->next = NULL;
            newCell->down = NULL;

            if (currentCell == NULL)
            {
                // Il n'y aucune cellule, on rajoute directement la nouvelle cellule
                dico[(int)researchString[0]] = newCell;
                printf("La cell n'existe pas. J'ai insert %s dans le tableau position %i\n",c,(int)researchString[0]);
                sizeOfDico++;
            } else {
                // Il existe deja des cellules, on cherche le bon emplacement
                while(currentNode < strlen(c) && insert == 0)
                {
                    strcat(researchString, &c[currentNode]);
                    currentNode++;
                    if(_DEBUG == 1)
                    {
                        printf("currentCell : "); 
                       // printf(currentCell);
                        printf("\n");
                    }
                    while(currentCell->next != NULL && strcmp(researchString,currentCell->string)>0)
                    {
                        //previousCell = currentCell;
                        currentCell = currentCell->next;
                    }
                    if (currentCell->next == NULL)
                    {
                        if(strlen(c)==currentNode)
                        {
                             // On insert en next
                            currentCell->next = newCell;
                            printf("J'ai fait un insert de %s en fin de liste aprËs %s\n",c,currentCell->string);
                            sizeOfDico++;
                            insert++;
                        } else if(strlen(c)==currentNode+1 && strcmp(researchString,currentCell->string) == 0 )
                        {
                            // On insert en down
                            currentCell->down = newCell;
                            printf("J'ai insert %s dans le down de %s\n",c,currentCell->string);
                            sizeOfDico++;
                            insert++;
                        } else if (strcmp(researchString,currentCell->string) == 0 && strlen(c)>currentNode) {
                            if(currentCell->down != NULL) {
                                // On descend
                                currentCell = currentCell->down;
                            } else {
                                // La cell ne peux pas etre insert
                                return;
                            }
                        } else {
                            // Erreur
                            return;
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
                                printf("J'ai insert %s dans le down de %s\n",c,currentCell->string);
                                sizeOfDico++;
                                insert++;
                            } else  {
                                // Il existe des cell en bas, on recommence une recherche
                                currentCell = currentCell->down;
                            }

                        } else {
                            // On fait une insertion de la nouvelle cell dans la liste
                            newCell->next = currentCell;
                            currentCell->next = newCell;
                            printf("J'ai insert %s juste apres %s et mon suivant est %s\n",c,currentCell->string,newCell->next->string);
                            sizeOfDico++;
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
int getSize()
{
    return log(sizeOfDico)/log(2);
}

////////////////////////////////////////////////////////////////
// Author : Quentin
void init()
{
    int i;
    for(i=0;i<TAILLE_DICO;i++)
    {
        //dico[i] = malloc(sizeof(cell));
        dico[i] = NULL;
    }
}

////////////////////////////////////////////////////////////////
int isExist(char* c){
    int sizec = strlen(c); //convertion automatique de size_t en int
    int i, j;
    cell* newdico = malloc(sizeof(cell));
    char* newc = malloc(sizeof(char)*sizec);
    newc[0] = c[0];
    if(_DEBUG == 1)
    {
        printf("On recherche : %s\n",c);
    }

    /**On parcours la chaine de caractere*/
    for (i=0; i < sizec; i++){

        /**On parcourt le tableau pour trouver le premier caracteres*/
        for (j=0; j < TAILLE_DICO; j++) {

            if(_DEBUG == 1)
            {
                printf("Valeur de j : %i\nValeur de i : %i\nValeur de c[i] : %i",j,i,c[i]);
            }

            if (j == c[i]){
                // Si on trouve le premier caractere et que celui ci etait l'unique caractere de la chaine on retourne le code
                 if (sizec == 1) {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et celui ci est l'unique caractere de la chaine : on retourne le code\n");
                    }
                    return j;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down est null alors la chaine ne se trouve pas dans le dictionnaire
                 else if (dico[j] == NULL) {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et le pointeur vers down est null : la chaine ne se trouve pas dans le dictionnaire\n");
                    }
                    return -1;
                 }
                 // Si on trouve le premier caractere et que le pointeur vers down n'est pas null alors on poursuit la recherche
                 else {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et  le pointeur vers down n'est pas null : on poursuit la recherche\n");
                    }
                    newdico = dico[j]; //on recupere un pointeur vers la bonne liste chainee
                    break ; // on sort de la boucle for(j=0, j < 259, j++)
                 }
            }
            else if (j != c[i]){
                //Si le premier caractere ne correspond pas, on poursuit le parcours du tableau
                continue ;
            }

            /** Si on n'a pas trouve le premier caractere dans le tableau de 259 elements, alors la chaine ne se trouve pas dans le dictionnaire */
            else if (j == TAILLE_DICO && j != c[i]) {
<<<<<<< HEAD
            return -1;
            }

            /**On parcours les listes chaines pour trouver la chaine de caractere*/
            newc = strcat(newc, &c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
                //Si la chaine de caractere ne correspond pas au champ car on poursuit la recherche tant que next pointe vers la suite de la liste chainee
                while (!(strcmp(newdico->string, newc)==0) && newdico->next != NULL) {
                    newdico = newdico->next ;
                }
                //Si la chaine de caractere ne correspond pas au champ car et que le champ next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
                if(!(strcmp(newdico->string, newc)==0) && newdico->next == NULL) {
                    return -1;
                }
                //Si la chaine de caractere correspond au champ car et que sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
                else if ((strcmp(newdico->string, newc)==0) && strlen(newc)==sizec) {
                    return newdico->code;
                }
                //Si la chaine de caractere correspond au champ car et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
                else if ((strcmp(newdico->string, newc)==0) && newdico->down != NULL) {
                    newdico = newdico->down;
                    continue; //on passe a l'itération suivante
                }
                //Si la chaine de caractere ne correspond pas au champ car et que le champ down point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
                else {
                    return -1;
=======
                if(_DEBUG == 1)
                {
                    printf("on n'a pas trouve le premier caractere dans le tableau de 259 elements : la chaine ne se trouve pas dans le dictionnaire\n");
                }
                return -1;
            }

            /** Si on ne trouve pas le premier caractere dans la case du tableau (<259), on poursuit le parcours du tableau */
            else {
                if(_DEBUG == 1)
                {
                    printf("on ne trouve pas le premier caractere dans la case du tableau (<259) : on poursuit le parcours du tableau\n");
>>>>>>> e3eca8987b29ba3fb8f3b8f0df2e9b0129393cab
                }
                continue;
            }
        }
        /**On parcours les listes chaines pour trouver la chaine de caractere*/
        newc = strcat(newc, &c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
        if(_DEBUG == 1)
        {
            printf("On recupere la nouvelle chaine : %s\n",newc);
        }
        //Si la chaine de caractere ne correspond pas au champ car on poursuit la recherche tant que next pointe vers la suite de la liste chainee
        while (!(strcmp(newdico->string,newc) == 0) && newdico->next != NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere ne correspond pas au champ car on poursuit la recherche\n");
            }
            newdico = newdico->next;
        }
        //Si la chaine de caractere ne correspond pas au champ car et que le champ next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
        if(!(strcmp(newdico->string,newc) == 0) && newdico->next == NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere ne correspond pas au champ car et le champ next point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire\n");
            }
            return -1;
        }
        //Si la chaine de caractere correspond au champ car et que sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
        else if ((strcmp(newdico->string,newc) == 0) && strlen(newc)==sizec) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere correspond au champ car et sa longueur est egale a la longueur de la chaine initialement recherche : on renvoie le code correspondant\n");
            }
            return newdico->code;
        }
        //Si la chaine de caractere correspond au champ car et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
        else if ((strcmp(newdico->string,newc) == 0) && newdico->down != NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere correspond au champ car et le champ down pointe vers la suite de la liste chainee : on poursuit la recherche\n");
            }
            newdico = newdico->down;
            continue; //on passe a l'itération suivante
        }
        //Si la chaine de caractere ne correspond pas au champ car et que le champ down point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
        else {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere ne correspond pas au champ car et le champ down point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire\n");
            }
            return -1;
        }
    }
    if(_DEBUG == 1)
    {
        printf("On sort direct du for ma gueule\n");
    }
    return -1;
}

////////////////////////////////////////////////////////////////
// Author : Quentin
void reset(){
    int i;
    for(i=0;i<sizeOfDico;i++){
        free(hashmap[i]);
    }
    init();
}

