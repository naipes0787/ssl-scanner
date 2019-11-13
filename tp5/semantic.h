#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

/**
 * @NAME: declarar
 * @DESC: Funcion para declarar variables
 */
void declarar(char *id);

/**
 * @NAME: inicio
 * @DESC: Funcion principal para cargar la biblioteca
 */
void inicio(void);

/**
 * @NAME: sumar
 * @DESC: Funcion para la suma de operandos
 */
char* sumar(char *operando1, char *operando2);

/**
 * @NAME: restar
 * @DESC: Funcion para la resta de operandos
 */
char* restar(char *operando1, char *operando2);

/**
 * @NAME: multiplicar
 * @DESC: Funcion para la multiplicacion de operandos
 */
char* multiplicar(char *operando1, char *operando2);

/**
 * @NAME: dividir
 * @DESC: Funcion para la división de operandos
 */
char* dividir(char *operando1, char *operando2);

/**
 * @NAME: negar
 * @DESC: Funcion para invertir el operando
 */
char* negar(char *operando);

/**
 * @NAME: asignar
 * @DESC: Funcion para
 */
void asignar(char *var1, char *var2);

/**
 * @NAME: leer
 * @DESC: Funcion para la lectua de identificadores
 */
void leer(char *id);

/**
 * @NAME: escribir
 * @DESC: Funcion para escribir una expresion
 */
void escribir(char *expr);

/**
 * @NAME: fin
 * @DESC: Funcion para terminar el programa
 */
void fin(void);

#endif // SCANNER_H_INCLUDED
