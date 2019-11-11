%code top{
#include <stdio.h>
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"

int semanticerrs = 0;
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

%token PROGRAMA FIN CODIGO DEFINIR LEER ESCRIBIR IDENTIFICADOR CONSTANTE
%token ASIGNACION "<="

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG

%%

programa                : PROGRAMA {iniciar();} listaDeclaraciones codigo FIN {detener(); if (yylexerrs || yynerrs || semanticerrs ) YYABORT;}
listaDeclaraciones      : listaDeclaraciones variable
                        | variable
                        ;
variable                : DEFINIR IDENTIFICADOR';'    {printf("definir %s\n", $IDENTIFICADOR);}
                        | error';'
                        ;
codigo                  : CODIGO listaSentencias
                        ;
listaSentencias         : listaSentencias sentencia
                        | sentencia
                        ;
sentencia               : LEER '('listaIdentificadores')' ';'
                        | ESCRIBIR '('listaExpresiones')' ';'
                        | IDENTIFICADOR "<=" expresion ';'        {guardar($3,$1);}
                        | error';'
                        ;
listaIdentificadores    : listaIdentificadores',' IDENTIFICADOR {leer($1);}
                        | IDENTIFICADOR                         {leer($1);};
                        ;
listaExpresiones        : listaExpresiones',' expresion {escribir($1);}
                        | expresion                     {escribir($1);};
                        ;
expresion               : operando                      {$$=$1;}
                        | '-'operando %prec NEG         {$$ = invertir($2);}
                        | '('expresion')'               {$$ = $2;}
                        | expresion '+' expresion       {$$ = sumar($1, $3);}
                        | expresion '-' expresion       {$$ = restar($1, $3);}
                        | expresion '*' expresion       {$$ = multiplicar($1, $3);}
                        | expresion '/' expresion       {$$ = dividir($1, $3);}
                        ;
operando                : IDENTIFICADOR
                        | CONSTANTE
                        ;
%%

/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}
