#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 5

int main()
{
    int array[T];
    char respuesta;
    InicializarVector(array, T);

    array[2]=4;
    array[3]=5;

    do{

        CargarNumero(array, T);

        printf("\nDesea ingresar otro dato? s/n ");
        fflush(stdin);
        scanf("%c", &respuesta);

    }while(respuesta=='s');

    return 0;
}
