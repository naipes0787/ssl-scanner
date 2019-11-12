%code top{
#include <stdio.h>
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"


void error_undeclared(const char *s); // Para mostrar error semantico por variable no declarada

int semanticerrs = 0;

char msg[120]; //para poder armar mensajes a enviar a yyerror
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
variable                : DEFINIR IDENTIFICADOR';'    {if(!existe($3)) declarar($3);
                                                       else{sprintf(msg, "Error semántico: identificador %s ya declarado", $3);yyerror(msg);semanticerrs++;YYERROR;}}
                        | error';'
                        ;
codigo                  : CODIGO listaSentencias
                        ;
listaSentencias         : listaSentencias sentencia
                        | sentencia
                        ;
sentencia               : LEER '('listaIdentificadores')' ';'
                        | ESCRIBIR '('listaExpresiones')' ';'
                        | IDENTIFICADOR "<=" expresion ';'        {if(!existe($1)){error_undeclared($1);YYERROR;} else guardar($3,$1);}
                        | error';'
                        ;
listaIdentificadores    : listaIdentificadores',' IDENTIFICADOR {if(!existe($1)){error_undeclared($1);YYERROR;} else leer($1);}
                        | IDENTIFICADOR                         {if(!existe($1)){error_undeclared($1);YYERROR;} else leer($1);}
                        ;
listaExpresiones        : listaExpresiones',' expresion {escribir($1);}
                        | expresion                     {escribir($1);}
                        ;
expresion               : operando                      {$$ = $1;}
                        | '-'operando %prec NEG         {$$ = invertir($2);}
                        | '('expresion')'               {$$ = $2;}
                        | expresion '+' expresion       {$$ = sumar($1, $3);}
                        | expresion '-' expresion       {$$ = restar($1, $3);}
                        | expresion '*' expresion       {$$ = multiplicar($1, $3);}
                        | expresion '/' expresion       {$$ = dividir($1, $3);}
                        ;
operando                : IDENTIFICADOR         {if(!existe($1)){error_undeclared($1);YYERROR;}}
                        | CONSTANTE
                        ;
%%

/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
        printf("línea #%d  %s\n", yylineno, s);
        return;
}

void error_undeclared(const char *s) {
    sprintf(msg, "Error semántico: identificador %s NO declarado", s);
    yyerror(msg);
    semanticerrs++;                             
}
