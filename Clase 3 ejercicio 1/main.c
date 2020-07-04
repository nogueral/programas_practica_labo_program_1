#include <stdio.h>
#include <stdlib.h>

/*
Pedirle al usuario que ingrese legajo,
altura y sexo y mostrar los datos.
(Utilizar 3 funciones distintas para tal cometido)
*/

int getInt (char[], char[], int, int);
char getChar (char[], char[], char, char);
float getFloat (char[], char[], float, float);

int main()
{
    int legajo;
    char sexo;
    float altura;

    legajo = getInt("Ingrese legajo: ", "Legajos comprendidos entre 100 y 999. Reingrese: ",
                    100, 999);

    sexo = getChar("Ingrese sexo f o m: ", "Error, el sexo debe ser f o m. Reingrese: ",
                   'f', 'm');

    altura = getFloat("Ingrese altura: ",
                      "La altura debe estar comprendida entre 1.50 y 1.98. Reingrese: ",
                      1.50, 1.98);


    return 0;
}

int getInt (char mensaje[], char error[], int min, int max) {

    int valor;

    printf("%s", mensaje);
    scanf("%d", &valor);

    while(valor < min || valor > max) {

        printf("%s", error);
        scanf("%d", &valor);
    }


    return valor;
}

char getChar (char mensaje[], char error[], char a, char b) {

    char valor;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &valor);

    while(valor != a && valor != b) {

        printf("%s", error);
        fflush(stdin);
        scanf("%c", &valor);
    }

    return valor;
}

float getFloat (char mensaje[], char error[], float min, float max){

    float valor;

    printf("%s", mensaje);
    scanf("%f", &valor);

    while(valor < min || valor > max) {

        printf("%s", error);
        scanf("%f", &valor);
    }



    return valor;
}
