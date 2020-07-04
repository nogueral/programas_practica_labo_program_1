#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define T 5

int main()
{
    int numeros[T];
    int suma;
    int opcion;
    int maximo, minimo;
    float promedio;
    int contadorPares=0, contadorImpares=0;

    do{
        printf("\n1. Inicializar: ");
        printf("\n2. Cargar: ");
        printf("\n3. Sumar e imprimir: ");
        printf("\n4. Imprimir forma creciente: ");
        printf("\n5. Imprimir forma decreciente: ");
        printf("\n6. Calcular maximo y minimo: ");
        printf("\n7. Calcular cantidad pares e impares: ");
        printf("\n8. Calcular promedio: ");
        printf("\n9. Salir: \n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            inicializarNumeros(numeros, T);
            break;
            case 2:
            getInt("Ingrese numero: ", numeros, T);
            break;
            case 3:
            suma = sumarVectores(numeros, T);
            printf("\nLa suma es: %d\n", suma);
            break;
            case 4:
            ImprimirCreciente(numeros, T);
            break;
            case 5:
            imprimirDecreciente(numeros, T);
            break;
            case 6:
            maximo = calculoMaximo(numeros, T);
            minimo = calculoMinimo(numeros, T);
            printf("\nEl maximo es %d y el minimo es %d \n", maximo, minimo);
            break;
            case 7:
            contadorPares = calculoPares(numeros, T);
            contadorImpares = calculoImpares(numeros, T);
            printf("\nLa cantidad de pares es %d y la de impares %d \n",
            contadorPares, contadorImpares);
            break;
            case 8:
            promedio = calculoPromedio(numeros, T);
            printf("\nEl promedio es: %f\n", promedio);
            break;

        }

        system("pause");
        system("cls");

    }while(opcion!=9);

    return 0;
}
