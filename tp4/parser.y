%code top{
#include <stdio.h>
#include "scanner.h"
}

%code provides {
void yyerror(const char *);
extern int yylexerrs;
extern int yynerrs;
}

%define api.value.type{char *}
%defines "parser.h"
%output "parser.c"
%define parse.error verbose

%token PROGRAMA FIN CODIGO DEFINIR LEER ESCRIBIR CONSTANTE IDENTIFICADOR
%token ASIGNACION "<="

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG

%%

programa 				: PROGRAMA listaDeclaraciones codigo FIN {if (yylexerrs || yynerrs) YYABORT;}
listaDeclaraciones 		: listaDeclaraciones variable
						| variable
						;
variable 				: DEFINIR IDENTIFICADOR';'	{printf("definir %s\n",$IDENTIFICADOR);}
						| DEFINIR error';'
						;
codigo 					: CODIGO listaSentencias
						;
listaSentencias : 		listaSentencias sentencia
                        | sentencia
						;
sentencia 				: LEER '('listaIdentificadores')' ';' 	{printf("leer\n");}
                        | ESCRIBIR '('listaExpresiones')' ';' 	{printf("escribir\n");}
                        | IDENTIFICADOR "<=" expresion ';'		{printf("asignacion\n");}
						| error';'
						;
listaIdentificadores 	: listaIdentificadores',' IDENTIFICADOR
                        | IDENTIFICADOR
						;
listaExpresiones 		: listaExpresiones',' expresion
                        | expresion
						;
expresion 				: operando
                        | '-'operando %prec NEG	 	{printf("inversion\n");}
                        | '('expresion')' 	  		{printf("paréntesis\n");}
                        | expresion '+' expresion	{printf("suma\n");}
                        | expresion '-' expresion 	{printf("resta\n");}
                        | expresion '*' expresion 	{printf("multiplicacion\n");}
                        | expresion '/' expresion 	{printf("division\n");}
						| '(' error ')'
						;
operando				: IDENTIFICADOR
                        | CONSTANTE
						;
%%

/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}
