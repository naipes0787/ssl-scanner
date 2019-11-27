#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 200

struct {
	char *buffer[DICTIONARY_SIZE];
	int indice;
} diccionario  =  { .indice = 0 };

void agregar(char *variable) {
    if(diccionario.indice >= DICTIONARY_SIZE){
        puts("ERROR: No queda espacio en el diccionario, abortando...");
        exit(1);
    }
    diccionario.buffer[diccionario.indice++] = variable;
}

int existe(char *variable) {
    for(int i = 0; i < diccionario.indice && i < DICTIONARY_SIZE; i++)
        if(strcmp(diccionario.buffer[i], variable) == 0)
            return 1;

    return 0;
}
