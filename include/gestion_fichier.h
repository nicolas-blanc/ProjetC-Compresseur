#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h> // Attention, rajouter -lm à la fin de la commande de compilation

/*
 * Ouvre le fichiers d'entrée en lecture et en mode texte et le fichier de sortie en écriture et en mode binaire, écrase les données du fichier si il existe, sinon le créé
 */
int init_fichier_compression(const char * nom_fin, const char * nom_fout);

/*
 * Ouvre le fichiers d'entrée en lecture et en mode binaire et le fichier de sortie en écriture et en mode texte, écrase les données du fichier si il existe, sinon le créé
 */
int init_fichier_decompression(const char * nom_in, const char * nom_out);

/*
 * Ferme les fichiers d'entrée et de sortie
 */
void close();

/*
 * Retourne vrai (0) si le pointeur dans le fichier d'entrée est à la fin du fichier, -1 sinon
 */
int eof();

/*
 * Ecris la chaine de caractère dans le fichier de sortie
 */
void ecrire_char(char * chaine);

/*
 * Ecris le code dans le fichier de sortie en fonction de la taille du code (en bits)
 */
void ecrire_code(uint16_t code, int taille);

/*
 * Vide le buffer en ecrivant les derniers code présent dans le buffer dans le fichier de sortie
 */
void fin_de_fichier(uint16_t code, int taille); // A modifier en mettant fin de fichier (code de fin de fichier à renseigner -> void fin_de_fichier(uint16_t code, int taille))

/*
 * Retourne le caractère lu dans le fichier d'entrée, ou -1 si le pointeur dans le fichier est à la fin du fichier (End_Of_File)
 */
int lire_char();

/*
 * Retourne le code lu dans le fichier d'entrée en fonction du nombre bit donné par la taille, ou 257 si le pointeur est à la fin du fichier (End_Of_File)
 */
unsigned int lire_code(int taille);
