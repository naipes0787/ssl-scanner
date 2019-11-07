%top{
#include <stdio.h>
#include <strings.h>
#include "parser.h"
char msg[120]; //para poder armar mensajes a enviar a yyerror
int yylexerrs;
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option noinput
%option nounput
%option yylineno

Letra                                                   [[:alpha:]]
Digito                                                  [[:digit:]]
LetraDigito                                             [[:alnum:]]
Blanco                                                  [[:space:]]
Comentario                                              #.*
Otros                                                   [[:punct:]]{-}[();,+*/#=>-]

%%

programa                                                return PROGRAMA;
fin                                                     return FIN;
codigo                                                  return CODIGO;
definir                                                 return DEFINIR;
leer                                                    return LEER;
escribir                                                return ESCRIBIR;
{Letra}{LetraDigito}*                                   {yylval = strdup(yytext); return IDENTIFICADOR;}
{Digito}+                                               {yylval = strdup(yytext); return CONSTANTE;}
\(                                                      return '(';
\)                                                      return ')';
\;                                                      return ';';
\,                                                      return ',';
\+                                                      return '+';
\-                                                      return '-';
\*                                                      return '*';
\/                                                      return '/';
\<=                                                     return ASIGNACION;
{Blanco}*                                            	|
{Comentario}						;
{Letra}{LetraDigito}*{Otros}({LetraDigito}|{Otros})*    {
								sprintf(msg, "Error léxico: identificador inválido: %s", yytext);
								yyerror(msg);
								yylexerrs++;
							}
{Digito}+{Letra}+{LetraDigito}*                         {
								sprintf(msg, "Error léxico: constante inválida: %s", yytext);
								yyerror(msg);
								yylexerrs++;
							}
{Otros}+                    							|
.                                                       {
								sprintf(msg, "Error léxico: cadena desconocida: %s", yytext);
								yyerror(msg);
								yylexerrs++;
							}
