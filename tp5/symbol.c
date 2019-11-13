#include <string.h>

struct {
	char *buffer[200];
	int indice;
} diccionario  =  { .indice = 0 };

void agregar(char *variable) {
    diccionario.buffer[diccionario.indice++] = variable;
}

int existe(char *variable) {
    for(int i = 0; i < diccionario.indice; i++)
        if(strcmp(diccionario.buffer[i], variable) == 0)
            return 1;

    return 0;
}
