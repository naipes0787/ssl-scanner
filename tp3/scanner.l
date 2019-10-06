%top{
	#include <stdio.h>
	#include "tokens.h"
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput

Letra  													[[:alpha:]]
Digito                      							[0-9]
LetraDigito                 							[[:alnum:]]
Blanco                      							[[:space:]]
Comentario                 								#.*
Otros                       							[^[:space:]();,+\-*/]

%%

programa					                            return PROGRAMA;
fin							                            return FIN;
variables					                            return VARIABLES;
codigo						                            return CODIGO;
definir						                            return DEFINIR;
leer						                            return LEER;
escribir 					                            return ESCRIBIR;
{Letra}{LetraDigito}*		                            return IDENTIFICADOR;
{Digito}+                                               return CONSTANTE;
\(                                                      return '(';
\)							                            return ')';
\;							                            return ';';
\,							                            return ',';
\+							                            return '+';
\-							                            return '-';
\*							                            return '*';
\/							                            return '/';
\<=							                            return ASIGNACION;
{Blanco}+						                        |
{Comentario}						                    ;
{Letra}{LetraDigito}*{Otros}({LetraDigito}|{Otros})*    printf("Error léxico: identificador inválido: %s\n", yytext);
{Digito}+{Letra}+{LetraDigito}*                         printf("Error léxico: constante inválida: %s\n", yytext);
{Otros}+                                                printf("Error léxico: cadena desconocida: %s\n", yytext);
