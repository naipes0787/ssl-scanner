#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum { IDENTIFICADOR, CONSTANTE_ENTERA, FDT, ERROR } token;

/**
* @NAME: debo_parar
* @DESC: Devuelve TRUE si el estado es > 3
*/
bool detenerse(int estado);

/**
* @NAME: intepretar_caracter
* @DESC: Interpreta la lectura de los caractes y los mapea al tipo caracter
*/
enum caracter intepretar_caracter(char c);

/**
* @NAME: es_aceptor
* @DESC: Devuelve TRUE en caso de estados aceptores (4,5,6)
*/
bool es_aceptor(int estado);

/**
* @NAME: es_centinela
* @DESC: Devuelve TRUE en caso de ser centinela (4,5,7)
*/
bool es_centinela(int estado);

/**
* @NAME: aceptar
* @DESC: Dependiendo del estado se acepta el token
*/
token aceptar(int estado);

/**
* @NAME: scanner
* @DESC: Funci—n principal del esc‡ner, recibe inputs y los analiza
*/
token scanner(void);

#endif // SCANNER_H_INCLUDED
