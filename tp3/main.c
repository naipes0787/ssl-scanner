/********************************************
 * TP3 - 2019                               *
 *  Título: TP3 - Flex                      *
 *  Número de grupo: 2                      *
 *                                          *
 *  Integrantes:                            *
 *      Costa, Leandro (151.787-9)          *
 *      Khalil, Javier (163.455-0)          *
 *      Sfara, Lucas (149.776-5)            *
 *      Szkuaron, Leandro (143.980-7)       *
 *                                          *
 * Al programa se le podrían pasar archivos *
 * por consola o desde el CodeBlocks desde  *
 * Project -> Set programs arguments        *
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main() {
	// Los demás son de un único caracter, por lo que mostramos el caracter directamente
	const char* keywords[] = { "Fin de Archivo", "Programa", "Fin", "Variables", "Código", 
		"Definir", "Leer", "Escribir", "Identificador", "Asignación", "Constante" };

	TOKEN token;
	do {
		token = yylex();
		if(token <= CONSTANTE) {
			if (token == IDENTIFICADOR || token == CONSTANTE) 
				printf("Token: %s\tlexema: %s\n", keywords[token], yytext);
			else
				printf("Token: %s\n", keywords[token]);
		}
		else {
			printf("Token: '%c'\n", token);
		}		
	} while (token != FDT);

	return EXIT_SUCCESS;
}
