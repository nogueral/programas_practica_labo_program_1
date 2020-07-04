#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int numero;
    int pares, impares;
    int divisibles;
    int primo, cantidadPrimos;

    numero = getInt ("Ingrese un numero positivo: ",
    "Error, ingrese un numero mayor o igual a 0: ", 0);
    printf("\nEl numero es: %d", numero);

    pares = contadorPares(numero);
    printf("\nLa cantidad de pares es: %d", pares);

    impares = contadorImpares(numero);
    printf("\nLa cantidad de impares es: %d", impares);

    divisibles = numeroDivisible(numero, 101);
    printf("\nLa cantidad de divisibles es: %d", divisibles);

    primo = numeroPrimo(numero);
    if(primo==1) {
        printf("\nEl numero es primo");
    } else {
        printf("\nEl numero no es primo");
    }

    cantidadPrimos = contadorPrimos(numero);
    printf("\nOa cantidad de primos es: %d", cantidadPrimos);


    return 0;
}
