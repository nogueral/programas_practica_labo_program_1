#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*
Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efect�e el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla
*/

int main()
{


    int numero1=5, numero2=4;

    funcionProducto(numero1, numero2);
    funcionCuadrado(numero1, numero1);

    printf("Hola muindo");

    return 0;
}
