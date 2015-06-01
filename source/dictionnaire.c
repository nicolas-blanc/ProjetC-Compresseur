#include "dictionnaire.h"
#include <stdio.h>

int sizeOfDico = TAILLE_DICO;

////////////////////////////////////////////////////////////////
// Author : Quentin
//
char* getCharByCode(unsigned int c)
{
    if (c > 0 && c < 256)
    {
        return (char)c;
    } else if (c == 257)
    {
        return "\0";
    } else if (c > 257)
    {
        return hashmap[c]->string;
    } else
    {
        return "";
    }

}

////////////////////////////////////////////////////////////////
// Author : Quentin
//
unsigned int getCodeByChar(char* c)
{
	return isExist(c);
}



////////////////////////////////////////////////////////////////
// Author : Coralie
// toutes les chaines de caractere unitaires sont deja dans le dictionnaire, on ne peut ajouter que des chaines de longueur >1
// on ne peut ajouter une chaines de longueur n uniquement si le debut de chaine de longueur n-1 est deja dans le dictionnaire

void add(char* c) {

    if (c != NULL) {

        int sizec = strlen(c); //permet de recuperer la taille de la chaine
        int i=0;
        cell* currentCell = malloc(sizeof(cell)); // pointeur vers une cellule
        char* newc = malloc(sizeof(char)*sizec+1); // chaine de caractere formee peu a peu a partir de c
        char suitec[2]; //permettra de recuperer le prochain caractere sous forme de string
        newc[0] = c[0];

        // On prepare notre nouvelle cell pour l'ajout dans le dictionnaire
        cell* newCell = malloc(sizeof(cell));
        newCell->string = c;
        newCell->code = sizeOfDico;
        newCell->next = NULL;
        newCell->down = NULL;



        #ifdef DEBUG
        printf("TEST ADD \n");
        printf("longueur : %i \n", sizec);
        #endif

        /**On cherche le premier caractere dans le tableau*/

        #ifdef DEBUG
        printf("Valeur de i : %i\nValeur de c[i] : %i \n",i,c[i]);
        #endif

        // Si le premier caractere correspond a une case du tableau && est l'unique caractere de la chaine : le caractere appartient deja au dictionnaire
        if ((int)c[i] >= 0 && (int)c[i] <= (TAILLE_DICO - 1) && sizec == 1){
            #ifdef DEBUG
            printf("ERREUR : le caractere appartient deja au dictionnaire\n");
            #endif
            return;
        }

        // Si le premier caractere correspond a une case du tableau && le pointeur n'est pas null && sizec > 2 : on poursuit la recherche dans la liste chainee pointe
        else if ((int)c[i] >= 0 && (int)c[i] <= (TAILLE_DICO - 1) && dico[(int)c[i]] != NULL && sizec >= 2) {
            #ifdef DEBUG
            printf("on trouve le premier caractere, le pointeur n'est pas null et la longueur est superieure a 2 : on poursuit la recherche\n");
            #endif
            currentCell = dico[(int)c[i]]; //on recupere un pointeur vers la bonne liste chainee

            /**On parcours les listes chaines pour trouver la chaine de caractere (apres parcours du tableau)*/
            for (i=1; i < sizec; i++){

                // On recupere la nouvelle chaine de caractere a rechercher dans la suite de la liste chainee
                #ifdef DEBUG
                printf("Ancienne chaine : %s\n",newc);
                printf("Prochain caractere a concatener : %c \n",c[i]);
                #endif
                suitec[0] = c[i];
                suitec[1] = '\0';
                newc = strcat(newc, suitec);
                #ifdef DEBUG
                printf("Nouvelle chaine a rechercher : %s \n",newc);
                #endif

                //Si la chaine de caractere ne correspond pas au champ string  : on poursuit la recherche tant que next pointe vers la suite de la liste chainee
                while (!(strcmp(currentCell->string,newc) == 0) && currentCell->next != NULL) {
                    #ifdef DEBUG
                    printf("la chaine de caractere ne correspond pas au champ string : on poursuit la recherche tant que next pointe vers la suite de la liste chainee\n");
                    #endif
                    currentCell = currentCell->next;
                }

                //Si la chaine de caractere ne correspond pas au champ string && next point vers NULL : on ajoute la chaine de caractere en next
                if(!(strcmp(currentCell->string,newc) == 0) && currentCell->next == NULL) {
                    /** On insert en next */
                    #ifdef DEBUG
                    printf("la chaine de caractere ne correspond && next point vers NULL : Ajout en next \n");
                    #endif
                    currentCell->next = newCell;
                    sizeOfDico++;
                    hashmap[newCell->code]=newCell;
                    return;
                }

                //Si la chaine de caractere correspond au champ string && sa longueur est egale a la longueur de la chaine initialement recherche : la chaine appartient deja au dictionnaire
                else if ((strcmp(currentCell->string,newc) == 0) && strlen(newc)==sizec) {
                    #ifdef DEBUG
                    printf("ERREUR : la chaine de caractere appartient deja au dictionnaire\n");
                    #endif
                    return;
                }

                //Si la chaine de caractere correspond au champ string && down pointe vers la suite de la liste chainee : on poursuit la recherche
                else if ((strcmp(currentCell->string,newc) == 0) && currentCell->down != NULL) {
                    #ifdef DEBUG
                    printf("la chaine de caractere correspond && down pointe vers la suite de la liste chainee : on poursuit la recherche\n");
                    #endif
                    currentCell = currentCell->down;
                    continue; //on passe a l'itération suivante
                }

                //Si la chaine de caractere correspond au champ string, que le champ down pointe vers NULL et que c a un caractere de plus que newc : Ajout en down
                else if ((strcmp(currentCell->string,newc) == 0) && currentCell->down == NULL && (sizec - strlen(newc)) == 1) {
                    /** On insert en down */
                    #ifdef DEBUG
                    printf("la chaine de caractere ne correspond pas && down point vers NULL : Ajout en down \n");
                    #endif
                    currentCell->down = newCell;
                    sizeOfDico++;
                    hashmap[newCell->code]=newCell;
                    return;
                }
                //Sinon on ne peut ajouter le caractere
                else  {
                    printf("ERREUR : la chaine de caractere ne peut pas etre ajoute car le debut de cette chaine n'appartient pas au dictionnaire\n");
                    return;
                }
            }
        }

        // Si le premier caractere correspond a une case du tableau && le pointeur est null && sizec==2 : on fait pointer la case vers une nouvelle cellule contenant le caractere
        else if ((int)c[i] >= 0 && (int)c[i] <= (TAILLE_DICO - 1) && dico[(int)c[i]] == NULL && sizec==2) {
            #ifdef DEBUG
            printf("on trouve le premier caractere, le pointeur pointe vers null et la longueur est egale a 2 : on fait pointer la case vers une nouvelle cellule contenant le caractere\n");
            #endif
            dico[(int)c[i]] = newCell;
            sizeOfDico++;
            hashmap[newCell->code]=newCell;
            return;
        }

        // Si on n'a pas trouve le premier caractere dans le tableau, on ne peut pas ajouter la chaine de caractere
        else {
            #ifdef DEBUG
            printf("ERREUR : on n'a pas trouve le premier caractere dans le tableau : la chaine ne peut pas etre ajoute\n");
            #endif
            return;
        }
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
		cell* newCell = malloc(sizeof(cell));
	}
}

////////////////////////////////////////////////////////////////
// Author : Coralie
int isExist(char* c){
    int sizec = strlen(c); //convertion automatique de size_t en int
    int i=0;
    cell* currentCell = malloc(sizeof(cell)); //permettra de pointer vers la bonne liste chainee
    char* newc = malloc(sizeof(char)*sizec +1); //permet de modifier la chaine de caractere a chercher
    newc[0] = c[0];
    char suitec[2]; //permettra de recuperer le prochain caractere a concatener sous forme de string

    #ifdef DEBUG
    printf("TEST ISEXIST \n");
    printf("On recherche : %s\n",c);
    #endif

    /**On cherche le premier caractere dans le tableau*/

    #ifdef DEBUG
    printf("Valeur de i : %i\nValeur de c[i] : %i \n",i,c[i]);
    #endif

    // Si le premier caractere correspond a une case du tableau && est l'unique caractere de la chaine : on retourne le code
    if ((int)c[i] >= 0 && (int)c[i] <= (TAILLE_DICO - 1) && sizec == 1){
        #ifdef DEBUG
        printf("on trouve le premier caractere et celui ci est l'unique caractere de la chaine : on retourne le code\n");
        #endif
        return (int)c[i];
    }

    // Si le premier caractere correspond a une case du tableau && le pointeur n'est pas null : on poursuit la recherche dans la liste chainee
    else if ((int)c[i] >= 0 && (int)c[i] <= (TAILLE_DICO - 1) && dico[(int)c[i]] != NULL ) {
        #ifdef DEBUG
        printf("on trouve le premier caractere et le pointeur n'est pas null : on poursuit la recherche\n");
        #endif
        currentCell = dico[(int)c[i]]; //on recupere un pointeur vers la bonne liste chainee

        /**On parcours les listes chaines pour trouver la chaine de caractere (apres parcours du tableau)*/
        for (i=1; i < sizec; i++){

            // On recupere la nouvelle chaine de caractere a rechercher dans la liste chainee
            #ifdef DEBUG
            printf("Anciene chaine : %s\n",newc);
            printf("Prochaine caractere a concatener : %c\n",c[i]);
            #endif
            suitec[0] = c[i];
            suitec[1] = '\0';
            newc = strcat(newc, suitec);
            #ifdef DEBUG
            printf("On recupere la nouvelle chaine : %s\n",newc);
            #endif

            //Si la chaine de caractere ne correspond pas au champ string on poursuit la recherche tant que next pointe vers la suite de la liste chainee
            while (!(strcmp(currentCell->string,newc) == 0) && currentCell->next != NULL) {
                #ifdef DEBUG
                printf("la chaine de caractere ne correspond pas : on poursuit la recherche tant que next pointe vers la suite de la liste chainee\n");
                #endif
                currentCell = currentCell->next;
            }

            //Si la chaine de caractere ne correspond pas au champ string && next point vers NULL alors la chaine de caractere n'est pas presente dans le dictionnaire
            if(!(strcmp(currentCell->string,newc) == 0) && currentCell->next == NULL) {
                #ifdef DEBUG
                printf("la chaine de caractere ne correspond pas && next point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire\n");
                #endif
                return -1;
            }

            //Si la chaine de caractere correspond au champ string && sa longueur est egale a la longueur de la chaine initialement recherche on renvoie le code correspondant
            else if ((strcmp(currentCell->string,newc) == 0) && strlen(newc)==sizec) {
                #ifdef DEBUG
                printf("la chaine de caractere correspond et sa longueur est egale a la longueur de la chaine initialement recherche : on renvoie le code correspondant\n");
                #endif
                return currentCell->code;
            }

            //Si la chaine de caractere correspond au champ string && down pointe vers la suite de la liste chainee : on poursuit la recherche
            else if ((strcmp(currentCell->string,newc) == 0) && currentCell->down != NULL) {
                #ifdef DEBUG
                printf("la chaine de caractere correspond && down pointe vers la suite de la liste chainee : on poursuit la recherche\n");
                #endif
                currentCell = currentCell->down;
                continue; //on passe a l'itération suivante
            }

            //Si la chaine de caractere ne correspond pas au champ string && down point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire
            else {
                #ifdef DEBUG
                printf("la chaine de caractere ne correspond pas && down point vers NULL : la chaine de caractere n'est pas presente dans le dictionnaire\n");
                #endif
                return -1;
            }
        }
    }

    // Si le premier caractere correspond a une case du tableau && le pointeur pointe vers est null  : la chaine ne se trouve pas dans le dictionnaire
    else if ((int)c[i] <= 0 && (int)c[i] >= (TAILLE_DICO - 1) && dico[(int)c[i]] == NULL) {
        #ifdef DEBUG
        printf("on trouve le premier caractere et le pointeur est null : la chaine ne se trouve pas dans le dictionnaire\n");
        #endif
        return -1;
    }

    // Si on n'a pas trouve le premier caractere dans le tableau : la chaine ne se trouve pas dans le dictionnaire
    else {
        #ifdef DEBUG
        printf("on n'a pas trouve le premier caractere dans le tableau : la chaine ne se trouve pas dans le dictionnaire\n");
        #endif
        return -1;
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
