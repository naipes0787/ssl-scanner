#include "scanner.h"

enum caracter { LETRA, DIGITO, FDC, ESPACIO, OTRO } ;
const int IDENTIFICADOR_RECONOCIDO = 4;
const int CONSTANTE_RECONOCIDA = 5;
const int FDT_RECONOCIDO = 6;
const int ERROR_RECONOCIDO = 7;

const int tabla[4][5] =
{
    { 1, 2, 6, 0, 3 },
    { 1, 1, 4, 4, 4 },
    { 5, 2, 5, 5, 5 },
    { 7, 7, 7, 7, 3 }
    // El resto de estados no hace falta tenerlos, puesto que nunca se alcanzan.
};

/**
* @NAME: detenerse
* @DESC: Devuelve TRUE si el estado es > 3
*/
bool detenerse(int estado)
{
    return estado > 3;
}

/**
* @NAME: intepretar_caracter
* @DESC: Interpreta la lectura de los caractes y los mapea al tipo caracter
*/
enum caracter intepretar_caracter(char c)
{
    if(isalpha(c))
        return LETRA;
    if(isdigit(c))
        return DIGITO;
    if(c == EOF)
        return FDC;
    if(isspace(c))
        return ESPACIO;

    return OTRO;
}

/**
* @NAME: es_aceptor
* @DESC: Devuelve TRUE en caso de estados aceptores (4,5,6)
*/
bool es_aceptor(int estado)
{
    // Los estados aceptores son 4, 5 y 6.
    return (estado == IDENTIFICADOR_RECONOCIDO ||
            estado == CONSTANTE_RECONOCIDA ||
            estado == FDT_RECONOCIDO);
}

/**
* @NAME: es_centinela
* @DESC: Devuelve TRUE en caso de ser centinela (4,5,7)
*/
bool es_centinela(int estado)
{
    // Los identificadores, constantes y errores leen centinelas
    return (estado == IDENTIFICADOR_RECONOCIDO ||
            estado == CONSTANTE_RECONOCIDA ||
            estado == ERROR_RECONOCIDO);
}

/**
* @NAME: aceptar
* @DESC: Dependiendo del estado se acepta el token
*/
token aceptar(int estado)
{
    switch(estado) {
        case IDENTIFICADOR_RECONOCIDO:
            return IDENTIFICADOR;
        case CONSTANTE_RECONOCIDA:
            return CONSTANTE_ENTERA;
        case FDT_RECONOCIDO:
            return FDT;
    }
    return 0; // Nunca deberia alcanzarse esto
}

token scanner(void)
{
    int estado = 0;
    char c;
    while(!detenerse(estado)) {
        c = getchar();
        estado = tabla[estado][intepretar_caracter(c)];
    }
    if(es_aceptor(estado)) {
        if(es_centinela(estado))
            ungetc(c, stdin);
        return aceptar(estado);
    }
    return ERROR;
}
