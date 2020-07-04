#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*
Crear una función que permita ingresar un numero al usuario
y lo retorne. Crear una función que reciba el radio de un círculo
y retorne su área. Utilizar las funciones de los puntos 1 y 2
para hacer un programa que calcule el área de un círculo cuyo
radio es ingresado por el usuario. Documentar las funciones al estilo Doxygen.
*/


int main()
{
  float numero;

  numero = getFloat("Ingrese el valor del radio: ");
  printf("\nEl radio es: %.2f", numero);

  numero = areaCirculo(numero);
  printf("\nEl area del circulo es: %.2f", numero);


    return 0;
}
