#include <stdio.h>
#include <stdlib.h>

void inicializarNumeros(int vector[], int tam)
{
       int i;

        // inicializar
    for(i=0; i<tam; i++) {
        vector[i] = 0;
        printf("%d\n", vector[i]);
    }
}

void getInt(char mensaje[], int vector[], int tam)
{
    int i;

    // ingresa numero
    for(i=0; i<tam; i++) {
    printf("%s", mensaje);
    scanf("%d", &vector[i]);

    }

}

int sumarVectores (int vector[], int tam)
{
    int suma=0;
    int i;

    for(i=0; i<tam; i++) {

        suma+=vector[i];
    }

    return suma;
}

void ImprimirCreciente (int vector[], int tam)
{
    int i;

    for(i=0; i<tam; i++) {

        printf("%d\n", vector[i]);
    }
}

void imprimirDecreciente (int vector[], int tam)
{
    int i;

    for(i=tam-1; i>-1; i--) {

        printf("%d\n", vector[i]);
    }

}

int calculoMaximo (int vector[], int tam)
{
    int i;
    int maximo;

    for(i=0; i<tam; i++) {

        if(i==0 || maximo<vector[i]) {
            maximo=vector[i];
        }
    }

    return maximo;
}

int calculoMinimo (int vector[], int tam)
{
    int i;
    int minimo;

    for(i=0; i<tam; i++) {

        if(i==0 || minimo>vector[i]) {
            minimo = vector[i];
        }
    }
    return minimo;
}
int calculoPares (int vector [], int tam)
{
    int i;
    int pares=0;

    for(i=0; i<tam; i++) {
        int resultado;
        resultado=vector[i]%2;

        if(resultado==0){
            pares++;
        }
    }

    return pares;
}

int calculoImpares (int vector [], int tam)
{
    int i;
    int impares=0;

    for(i=0; i<tam; i++) {
        int resultado;
        resultado=vector[i]%2;

        if(resultado!=0){
            impares++;
        }
    }

    return impares;
}

float calculoPromedio (int vector[], int tam)
{
    float promedio;
    int acumulador;

    acumulador = sumarVectores(vector, tam);

    promedio = (float) acumulador / tam;

    return promedio;
}
