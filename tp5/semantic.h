#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

void declarar(char *id);
void leer(char *id);
void escribir(char *expr);
char* invertir(char *operando);
char* multiplicar(char *operando1, char *operando2);
char* sumar(char *operando1, char *operando2);
char* restar(char *operando1, char *operando2);
char* dividir(char *operando1, char *operando2);
void asignar(char *var1, char *var2);
void inicio(void);
void fin(void);

#endif // SCANNER_H_INCLUDED
