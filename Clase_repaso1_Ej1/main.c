#include <stdio.h>
#include <stdlib.h>

/*
Ingresar números hasta que el usuario lo decida.
Los números tienen que estar comprendidos entre -100 y 100.
Determinar:a. Cantidad de números positivos.
b. Cantidad de números negativos.
c. Promedio de números.
d. De los positivos el máximo.
*/



int main()
{
    int numero, acumulador=0, maxP;
    int respuesta=1;
    int contadorP=0, contadorN=0, contador=0;
    float promedio;

    while(respuesta==1) {

        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        while (numero > 100 || numero < -100) {
            printf("Error! Ingrese un numero entre -100 y 100: ");
            scanf("%d", &numero);

        }

    acumulador = acumulador + numero; // para calculo promedio

    if(numero>=0) {

        contadorP++;

        if (contadorP==1) {

            maxP=numero;
        }

        if (maxP<numero) {

            maxP=numero;
        }


    } // a- calcula cant positivos y max positivos

    if(numero<0) {

        contadorN++;
    } // b- calcula cant negativos



        contador++; // para calculo promedio

        printf("Ingresar otro numero:1 o salir:0 \n");
        scanf("%d", &respuesta);

        while (respuesta != 1 && respuesta !=0) {
            printf("Error! Ingresar otro numero:1 o salir:0 \n");
            scanf("%d", &respuesta);

        }
    }

    promedio = (float)acumulador / contador;
    printf("\nLa cantidad de positivos es: %d", contadorP);
    printf("\nLa cantidad de negativos es: %d", contadorN);
    printf("\nEl promedio es: %f", promedio);
    printf("\nEl maximo positivo es: %d", maxP);



    return 0;
}
