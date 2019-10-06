/********************************************
 * TP0 - 2019                               *
 *  Título: Un escaner elemental            *
 *  Número de grupo: 2                      *
 *                                          *
 *  Integrantes:                            *
 *      Costa, Leandro (151.787-9)          *
 *      Khalil, Javier (163.455-0)          *
 *      Sfara, Lucas (149.776-5)            *
 *      Szkuaron, Leandro (143.980-7)       *
 *                                          *
 * Al programa se le podrían pasar archivos *
 * por consola o desde el CodeBlocks desde  *
 * Project -> Set programs arguments        *
 ********************************************/

#include "scanner.h"

int main()
{
    int cantidadIdentificadores = 0;
    int cantidadConstantes = 0;
    int cantidadErrores = 0;

    token token;
    do {
        token = scanner();
        switch(token) {
        case IDENTIFICADOR:
            puts("identificador");
            cantidadIdentificadores++;
            break;
        case CONSTANTE_ENTERA:
            puts("constante entera");
            cantidadConstantes++;
            break;
        case ERROR:
            puts("error");
            cantidadErrores++;
            break;
        case FDT:
            break;
        }
    } while(token != FDT);

    puts("----\n");
    puts("Totales:\n");
    printf("Identificadores %d\n", cantidadIdentificadores);
    printf("Constantes enteras %d\n", cantidadConstantes);
    printf("Errores %d", cantidadErrores);

    return 0;
}
