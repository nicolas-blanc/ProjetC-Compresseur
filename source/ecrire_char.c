#include <stdio.h>
#include "ecrire_char.h"

void ecrire_char(char c, FILE *f)
{
	fwrite(&c,1,NB_TO_WRITE,f);
	fflush(f);
	return;
}
