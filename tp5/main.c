/********************************************
 * TP4 - 2019                               *
 *  Título: TP5 - Compilador                *
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
#include "parser.h"
extern int semanticerrs;

int main() {
	switch(yyparse()){
	case 0:
		puts("Compilacion terminada con exito"); 
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semanticos: %d\n", yynerrs, yylexerrs, semanticerrs);
		return 0;
	case 1:
		puts("Errores de compilación");
		printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semanticos: %d\n", yynerrs, yylexerrs, semanticerrs);
		return 1;
	case 2:
		puts("Memoria insuficiente"); 
		return 2;
	}
	return 0;
}
