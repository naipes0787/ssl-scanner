#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"

#define ID_MAX_LENGTH 10

void declarar(char *id) {
	agregar(id);
	printf("Declare %s,Integer\n", id);
}

char* get_temp(void) {
	static int temporales = 1;
	char *temp = malloc(ID_MAX_LENGTH);
	sprintf(temp, "Temp#%d", temporales++);
	declarar(temp);
	return temp;
}

void leer(char *id) {
	printf("Read %s,Integer\n", id);
}
void escribir(char *expr) {
	printf("Write %s,Integer\n", expr);
}
char* invertir(char *operando) {
  	char *var = get_temp();
	printf("NEG %s,,%s\n", operando, var);
	return var;
}
char* multiplicar(char *operando1, char *operando2) {
	char *var = get_temp();
	printf("MUL %s,%s,%s\n", operando1, operando2, var);
	return var;
}
char* sumar(char *operando1, char *operando2) {
	char *var = get_temp();
	printf("ADD %s,%s,%s\n", operando1, operando2, var);
	return var;
}
char* restar(char *operando1, char *operando2) {
	char *var = get_temp();
	printf("SUB %s,%s,%s\n", operando1, operando2, var);
	return var;
}

char* dividir(char *operando1, char *operando2) {
	char *var = get_temp();
	printf("DIV %s,%s,%s\n", operando1, operando2, var);
	return var;
}

void asignar(char *var1, char *var2) {
	printf("Store %s, %s \n", var1, var2);
}

void inicio(void) {
	printf("Load rtlib,\n");
}
void fin(void) {
	printf("Exit ,\n");
}
