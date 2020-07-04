#include <stdio.h>
#include <stdlib.h>


int getInt (char mensaje[], char error[], int a)
{
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);

    while(numero<a) {
    printf("%s", error);
    scanf("%d", &numero);

    }

    return numero;
}

int contadorPares (int a)
{
    int pares=0;
    int contador;

    for(contador=1; contador<=a; contador++) {
        int resto;
        resto=contador%2;

        if(resto==0) {
            pares++;
        }

    }

    return pares;

}

int contadorImpares (int a)
{
    int contador;
    int impares=0;

    for(contador=1; contador<=a; contador++){
    int resto;
    resto=contador%2;

    if(resto==1){

        impares++;
    }

    }

    return impares;
}

int numeroDivisible (int a, int max)
{
    int divisibles=0;
    int contador;

    for(contador=1; contador<max; contador++) {
        int resto;
        resto=contador%a;

        if(resto==0) {
            divisibles++;
        }
    }

    return divisibles;
}

int numeroPrimo (int a)
{
    int primo=0;
    int contadorPrimos=0;
    int contador=0;

    for(contador=1; contador<=a; contador++) {
        int resto;
        resto = a % contador;

        if(resto==0) {
            contadorPrimos++;
        }
    }

    if(contadorPrimos==2) {
        primo=1;
    }

    return primo;
}

int contadorPrimos (int a)
{
    int primo;
    int contador;
    int acumulador=0;

    for(contador=1; contador<=a; contador++) {
        primo = numeroPrimo(contador);
        if(primo==1) {
            acumulador++;
        }

    }
    return acumulador;
}

