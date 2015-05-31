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

/**

////////////////////////////////////////////////////////////////
// Author : Quentin
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

*/

////////////////////////////////////////////////////////////////
// Author : Coralie
// toutes les chaines de caractere unitaires sont deja dans le dictionnaire, on ne peut ajouter que des chaines de longueur >1
// on ne peut ajouter une chaines de longueur n uniquement si le debut de chaine de longueur n-1 est deja dans le dictionnaire

void add(char* c) {

    if (c != NULL) {

        int sizec = strlen(c); //permet de recuperer la taille de la chaine
        int i, j;
        cell* currentCell = malloc(sizeof(cell)); // pointeur vers une cellule
        char* newc = malloc(sizeof(char)*sizec); // chaine de caractere formee peu a peu a partir de c
        newc[0] = c[0];

        // On prepare notre nouvelle cell pour l'ajout dans le dictionnaire
        cell* newCell = malloc(sizeof(cell));
        newCell->string = c;
        newCell->code = sizeOfDico;
        newCell->next = NULL;
        newCell->down = NULL;

        for (i=0; i < sizec; i++){

            /**On parcourt le tableau pour trouver le premier caracteres*/
            for (j=0; j < TAILLE_DICO; j++) {

                // Si le premier caractere correspond a une case du tableau
                if (j == c[i]){
                    // Si le caractere est l'unique caractere de la chaine : le caractere appartient deja au dictionnaire
                     if (sizec == 1) {
                        printf("ERREUR : le caractere appartient deja au dictionnaire\n");
                        return;
                     }
                     // Si le pointeur est null et sizec==2 : on fait pointer la case vers une nouvelle cellule contenant le caractere
                     else if (dico[j] == NULL && sizec == 2) {
                         /** On dans la case du dictionnaire */
                        dico[j] = newCell;
                        sizeOfDico++;
                        return;
                     }
                     // Si le pointeur n'est pas null et sizec > 2 : on poursuit la recherche dans la liste chainee
                     else if (dico[j] != NULL && sizec > 2){
                        currentCell = dico[j]; //on recupere un pointeur vers la bonne liste chainee
                        break ; // on sort de la boucle for(j=0, j < 259, j++)
                     }
                     // Dans les autres cas : le caractere ne peut pas etre ajoute car le debut de cette chaine n'appartient pas au dictionnaire ou alors cette chaine appartient deja au dictionnaire
                     else {
                        printf("ERREUR : la chaine de caractere ne peut etre ajoute car elle y appartient deja ou alors le debut de cette chaine n'appartient pas au dictionnaire\n");
                        return;
                     }
                }

                // Si on n'a pas trouve le premier caractere dans le tableau de 259 elements, on ne peut pas l'ajouter
                else if (j != c[i] && j == TAILLE_DICO ) {
                    printf("ERREUR : on n'a pas trouve le premier caractere dans le tableau de 259 elements : la chaine ne peut pas etre ajoute\n");
                    return;
                }

                //Si le premier caractere ne correspond pas a la case courante du tableau <259, on poursuit le parcours du tableau en passant a l'iteration suivante
                else if (j != c[i]){
                    continue ;
                }

            }


            /**On parcours les listes chaines pour trouver la chaine de caractere (apres parcours du tableau)*/
            newc = strcat(newc, &c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee

            //Si la chaine de caractere ne correspond pas au champ string on poursuit la recherche tant que next pointe vers la suite de la liste chainee
            while (!(strcmp(currentCell->string,newc) == 0) && currentCell->next != NULL) {
                currentCell = currentCell->next;
            }
            //Si la chaine de caractere ne correspond pas au champ string et que le champ next point vers NULL : on ajoute la chaine de caractere en next
            if(!(strcmp(currentCell->string,newc) == 0) && currentCell->next == NULL) {
                /** On insert en next */
                currentCell->next = newCell;
                sizeOfDico++;
                return;
            }
            //Si la chaine de caractere correspond au champ string et que sa longueur est egale a la longueur de la chaine initialement : la chaine appartient deja au dictionnaire
            else if ((strcmp(currentCell->string,newc) == 0) && strlen(newc)==sizec) {
                printf("ERREUR : la chaine de caractere appartient deja au dictionnaire\n");
                return;
            }
            //Si la chaine de caractere correspond au champ string et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
            else if ((strcmp(currentCell->string,newc) == 0) && currentCell->down != NULL) {
                currentCell = currentCell->down;
                continue; //on passe a l'itération suivante
            }
            //Si la chaine de caractere correspond au champ string, que le champ down pointe vers NULL et que c a un caractere de plus que newc : on ajoute la chaine de caractere en down
            else if ((strcmp(currentCell->string,newc) == 0) && currentCell->down == NULL /*&& (sizec - strlen(newc)) == 1*/) {
                /** On insert en down */
                currentCell->down = newCell;
                sizeOfDico++;
                return;
            }
            //Sinon on ne peut ajouter le caractere
            else  {
                printf("ERREUR : la chaine de caractere ne peut pas etre ajoute car le debut de cette chaine n'appartient pas au dictionnaire\n");
                return;
            }
        }
    }
    else {
        printf("ERREUR : l'argument est nul \n");
        return;
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
// Author : Coralie
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

            // Si le premier caractere correspond a une case du tableau
            if (j == c[i]){
                // Si le caractere est l'unique caractere de la chaine : on retourne le code
                 if (sizec == 1) {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et celui ci est l'unique caractere de la chaine : on retourne le code\n");
                    }
                    return j;
                 }
                 // Si le pointeur est null  : la chaine ne se trouve pas dans le dictionnaire
                 else if (dico[j] == NULL) {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et le pointeur est null : la chaine ne se trouve pas dans le dictionnaire\n");
                    }
                    return -1;
                 }
                 // Si le pointeur n'est pas null : on poursuit la recherche dans la liste chainee
                 else {
                    if(_DEBUG == 1)
                    {
                        printf("on trouve le premier caractere et  le pointeur n'est pas null : on poursuit la recherche\n");
                    }
                    newdico = dico[j]; //on recupere un pointeur vers la bonne liste chainee
                    break ; // on sort de la boucle for(j=0, j < 259, j++)
                 }
            }

            // Si on n'a pas trouve le premier caractere dans le tableau de 259 elements, alors la chaine ne se trouve pas dans le dictionnaire
            else if (j != c[i] && j == TAILLE_DICO ) {
                if(_DEBUG == 1)
                {
                    printf("on n'a pas trouve le premier caractere dans le tableau de 259 elements : la chaine ne se trouve pas dans le dictionnaire\n");
                }
                return -1;
            }

            //Si le premier caractere ne correspond pas a la case du tableau <259, on poursuit le parcours du tableau en passant a l'iteration suivante
            else if (j != c[i]){
                if(_DEBUG == 1)
                {
                    printf("on ne trouve pas le premier caractere dans la case du tableau (<259) : on poursuit le parcours du tableau\n");
                }
                continue ;
            }
        }

        /**On parcours les listes chaines pour trouver la chaine de caractere (apres parcours du tableau)*/
        newc = strcat(newc, &c[i+1]); //on recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
        if(_DEBUG == 1)
        {
            printf("On recupere la nouvelle chaine : %s\n",newc);
        }
        //Si la chaine de caractere ne correspond pas au champ string on poursuit la recherche tant que next pointe vers la suite de la liste chainee
        while (!(strcmp(newdico->string,newc) == 0) && newdico->next != NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere ne correspond pas au champ car on poursuit la recherche\n");
            }
            newdico = newdico->next;
        }
        //Si la chaine de caractere ne correspond pas au champ string et que le champ next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
        if(!(strcmp(newdico->string,newc) == 0) && newdico->next == NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere ne correspond pas au champ car et le champ next point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire\n");
            }
            return -1;
        }
        //Si la chaine de caractere correspond au champ string et que sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
        else if ((strcmp(newdico->string,newc) == 0) && strlen(newc)==sizec) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere correspond au champ car et sa longueur est egale a la longueur de la chaine initialement recherche : on renvoie le code correspondant\n");
            }
            return newdico->code;
        }
        //Si la chaine de caractere correspond au champ string et que le champ down pointe vers la suite de la liste chainee on poursuit la recherche
        else if ((strcmp(newdico->string,newc) == 0) && newdico->down != NULL) {
            if(_DEBUG == 1)
            {
                printf("la chaine de caractere correspond au champ car et le champ down pointe vers la suite de la liste chainee : on poursuit la recherche\n");
            }
            newdico = newdico->down;
            continue; //on passe a l'itération suivante
        }
        //Si la chaine de caractere ne correspond pas au champ string et que le champ down point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
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
