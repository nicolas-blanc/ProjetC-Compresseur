#include <stdio.h>
#include "lire_char.h"

char lire_caractere(FILE * f){

char res;
res = fread(&res,1,NB_TO_READ,f);
return res;

}
