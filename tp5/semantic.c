#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"

#define ID_MAX_LENGTH 10

int temporales = 1;

void declarar(char *id){
	agregar(id);
	printf("Declare %s,Integer\n", id);
}

char* get_temp(){
	char *temp = malloc(ID_MAX_LENGTH);
	sprintf(temp, "Temp#%d", temporales++);
	declarar(temp);
	return temp;
}

void leer(char *id){
	printf("Read %s,Integer\n", id);
}
void escribir(char *id){
	printf("Write %s,Integer\n", id);
}
char* invertir(char *idEntrada){
  	char *idSalida = get_temp();
	printf("NEG %s,,%s\n", idEntrada, idSalida);
	return idSalida;
}
char* multiplicar(char *idEntrada1, char *idEntrada2){
	char *idSalida = get_temp();
	printf("MUL %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}
char* sumar(char *idEntrada1, char *idEntrada2){
	char *idSalida = get_temp();
	printf("ADD %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}
char* restar(char *idEntrada1, char *idEntrada2){
	char *idSalida = get_temp();
	printf("SUB %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}

char* dividir(char *idEntrada1, char *idEntrada2){
	char *idSalida = get_temp();
	printf("DIV %s,%s,%s\n", idEntrada1, idEntrada2, idSalida);
	return idSalida;
}

void guardar(char *idEntrada, char *idSalida){
	printf("Store %s, %s \n", idEntrada, idSalida);
}

void iniciar(){
	printf("Load rtlib,\n");
}
void detener(){
	printf("Exit ,\n");
}
