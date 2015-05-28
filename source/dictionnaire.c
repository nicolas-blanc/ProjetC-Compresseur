#include ../include/dictionnaire.h
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

