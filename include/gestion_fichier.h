#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h> // Attention, rajouter -lm à la fin de la commande de compilation


int init_fichier_compression(char * nom_fin, char * nom_fout);

int init_fichier_decompression(char * nom_in, char * nom_out);

void close();

/*
 * Retourne vrai (0) si le pointeur dans le fichier d'entrée est à la fin du fichier, -1 sinon
 */
int eof();

void ecrire_char(char * chaine);

void ecrire_code(uint16_t code, int taille);

void vider_buffer_code();

/*
 * Retourne le caractère lu dans le fichier d'entrée, ou -1 si le pointeur dans le fichier est à la fin du fichier (End_Of_File)
 */
int lire_char();

/*
 * Retourne le code lu dans le fichier d'entrée en fonction du nombre bit donné par la taille, ou 257 si le pointeur est à la fin du fichier (End_Of_File)
 */
unsigned int lire_code(int taille);