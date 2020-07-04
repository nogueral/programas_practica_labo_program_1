#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM 3
#define LIBRE 0
#define OCUPADO 1



int main()
{

    int opcion;
    int legajo[TAM];
    int nota1[TAM];
    int nota2[TAM];
    char nombre[TAM][20];
    float promedio[TAM];
    int estado[TAM];
    int retornoFuncion;

    InicializarVector(estado, TAM, LIBRE);

    do
    {
        printf("\n1. Cargar alumno\n");
        printf("2. Modificar alumno\n");
        printf("3. Eliminar alumno\n");
        printf("4. Ordenar alumnos por nombre\n");
        printf("5. Listar alumnos\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            retornoFuncion = CargarAlumno(legajo, nombre, nota1, nota2, estado, promedio, TAM, LIBRE, OCUPADO);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nAlumno cargado con exito");
                break;
                case -1:
                printf("\nNo hay mas espacio");
                break;
            }
            break;
            case 2:
            retornoFuncion = ModificarAlumno(legajo, nombre, nota1, nota2, promedio, estado, TAM, OCUPADO);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nAlumno modificado con exito");
                break;
                case -1:
                printf("\nNo se ha podido realizar la operacion");
                break;
            }
            break;
            case 3:
            retornoFuncion = EliminarAlumno(legajo, nombre, nota1, nota2, estado, promedio, TAM, LIBRE, OCUPADO);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nBaja realizada con exito");
                case -1:
                printf("\nOperacion cancelada");
            }
            break;
            case 4:
            OrdenarAlumnosPorNombre(legajo, nota1, nota2, promedio, nombre, estado, TAM, OCUPADO);
            break;
            case 5:
            MostrarAlumnos(legajo, nota1, nota2, promedio, nombre, estado, TAM, OCUPADO);
            break;
        }

    }while(opcion!=6);


    return 0;
}
