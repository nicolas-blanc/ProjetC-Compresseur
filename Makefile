EXECS_TEST=code_lzw decode_lzw #testCodage testDecodage
EXECS=lumino_lzw

CC=gcc -g 
OPT= -O3
CFLAGS= -I include/ 
OPTION=#-DDEBUG

all: $(EXECS)

test_unit: $(EXECS_TEST)

%.o: source/%.c
	$(CC) $(OPTION) $(CFLAGS) -c $^
	
code_lzw: code_lzw.o gestion_fichier.o dictionnaire.o include/dictionnaire.h 
	$(CC) $(OPTION) $(OPT) -o $@ $^ -lm
	
decode_lzw: decode_lzw.o gestion_fichier.o dictionnaire.o include/dictionnaire.h 
	$(CC) $(OPTION) $(OPT) -o $@ $^ -lm

lumino_lzw: lzw.o code_lzw.o decode_lzw.o gestion_fichier.o dictionnaire.o include/dictionnaire.h
	$(CC) $(OPTION) $(OPT) -o $@ $^ -lm
	
clean_execs:
	rm -f $(EXECS) $(EXECS_TEST)

clean_o:
	rm -f *.o

clean_z:
	rm -f *.z

clean: clean_execs clean_o

clean_all: clean clean_z



#-l lib à prendre
#-L chemin
#-I
# code_lzw: ./source/code_lzw.c gestion_fichier.o dictionnaire.o
# 	gcc $(OPTIONS) ./source/code_lzw.c gestion_fichier.o dictionnaire.o -o code_lzw -lm

# decode_lzw: ./source/decode_lzw.c gestion_fichier.o dictionnaire.o
# 	gcc $(OPTIONS) ./source/decode_lzw.c gestion_fichier.o dictionnaire.o -o decode_lzw -lm

# testCodage: testCodage.c gestion_fichier.o
# 	gcc $(OPTIONS) testCodage.c gestion_fichier.o -o testCodage -lm

# testDecodage: testDecodage.c gestion_fichier.o
# 	gcc $(OPTIONS) testDecodage.c gestion_fichier.o -o testDecodage -lm

# gestion_fichier.o: ./source/gestion_fichier.c
# 	gcc $(OPTIONS) -c ./source/gestion_fichier.c -lm

# dictionnaire.o: ./source/dictionnaire.c
# 	gcc $(OPTIONS) -c ./source/dictionnaire.c -lm
