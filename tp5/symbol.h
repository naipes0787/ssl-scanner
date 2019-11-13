#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

/**
 * @NAME: agregar
 * @DESC: Agrega la variable al diccionario
 */
void agregar(char *variable);

/**
 * @NAME: existe
 * @DESC: Dada una variable, devuelve true si se encuentra cargada
 *        en el diccionario. False en caso contrario.
 */
int existe(char *variable);

#endif // SYMBOL_H_INCLUDED
