#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum { IDENTIFICADOR, CONSTANTE_ENTERA, FDT, ERROR } token;

/**
* @NAME: scanner
* @DESC: Funci—n principal del esc‡ner, recibe inputs y los analiza
*/
token scanner(void);

#endif // SCANNER_H_INCLUDED
