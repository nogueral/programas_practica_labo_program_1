#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char nombre[8];
    char apellido[8];
    char segundoNombre[8];

    char nombre2[8];
    char apellido2[30];
    char segundoNombre2[8];

    char respuesta;

    printf("Ingrese su nombre: ");
    fgets(nombre, 8, stdin);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    fgets(apellido, 8, stdin);

    strcpy(nombre2, nombre);
    strcpy(apellido2, apellido);

    strlwr(apellido2);
    strlwr(nombre2);

    nombre2[0]=toupper(nombre2[0]);
    apellido2[0]=toupper(apellido2[0]);


    printf("\nDesea ingresar tambien su segundo nombre? s/n ");
    fflush(stdin);
    scanf("%c", &respuesta);

    if(respuesta=='s') {

        printf("\nIngrese su segundo nombre: ");
        fflush(stdin);
        fgets(segundoNombre, 8, stdin);

        strcpy(segundoNombre2, segundoNombre);
        strlwr(segundoNombre2);
        segundoNombre2[0]=toupper(segundoNombre2[0]);

        strcat(apellido2, ", ");
        strcat(apellido2, nombre2);
        strcat(apellido2, " ");
        strcat(apellido2, segundoNombre2);

        puts(apellido2);

    } else {

        strcat(apellido2, ", ");
        strcat(apellido2, nombre2);
        printf(apellido2);

    }


    return 0;
}
