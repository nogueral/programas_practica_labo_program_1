#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

void InicializarVector(int vector[], int tam, int valorLibre)
{
       int i;

    for(i=0; i<tam; i++) {
        vector[i] = valorLibre;
    }
}

int GetInt (char mensaje[], char error[], int min, int max) {

    int num;

        printf("%s",mensaje);
        scanf("%d", &num);

        while (num < min || num > max) {

            printf("%s",error);
            scanf("%d", &num);
        }
    return num;
}



int CargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], int estado[], float promedio[], int tam, int valorLibre, int valorOcupado)
{
    int indiceEncontrado;

    indiceEncontrado = BuscarLibre(estado, tam, valorLibre);

    if(indiceEncontrado!=-1)
    {
        legajo[indiceEncontrado] = GetInt("Ingrese legajo: ", "Error, reingrese: ", 100, 105);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre[indiceEncontrado]);

        nota1[indiceEncontrado] = GetInt("Ingrese nota: ", "Error, reingrese: ", 1, 10);
        nota2[indiceEncontrado] = GetInt("Ingrese nota: ", "Error, reingrese: ", 1, 10);

        promedio[indiceEncontrado] = CalculoPromedio(nota1[indiceEncontrado], nota2[indiceEncontrado]);

        estado[indiceEncontrado] = valorOcupado;
        indiceEncontrado = 1;
    }

    return indiceEncontrado;
}

int BuscarLibre(int vector[], int tam, int valorLibre)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(vector[i]==valorLibre)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int ModificarAlumno (int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int estado[], int tam, int valorOcupado)
{
    int i;
    int auxiliarLegajo;
    int opcion;
    int valorDeRetorno=-1;

    printf("\nIngrese legajo: ");
    scanf("%d", &auxiliarLegajo);

    for(i=0; i<tam; i++)
    {
        if(estado[i]==valorOcupado && auxiliarLegajo==legajo[i])
           {

            printf("\n Ingrese el dato a modificar: ");
            printf("\n 1 . Nombre: ");
            printf("\n 2 . Nota 1: ");
            printf("\n 3 . Nota 2: ");
            printf("\n 4. Salir: \n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("\n Ingrese el nombre: ");
                fflush(stdin);
                gets(nombre[i]);
                valorDeRetorno=1;
                break;
            case 2:
                nota1[i]=GetInt("\n Ingrese nota: ", "\n Error, reingrese nota", 1, 10);
                promedio[i]=CalculoPromedio(nota1[i], nota2[i]);
                valorDeRetorno=1;
                break;
            case 3:
                nota2[i]=GetInt("\n Ingrese nota: ", "\n Error, reingrese nota", 1, 10);
                promedio[i]=((float)nota1[i]+nota2[i])/2;
                valorDeRetorno=1;
                break;
            }

           }

    }


    return valorDeRetorno;

}


int EliminarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], int estado[], float promedio[], int tam, int valorLibre, int valorOcupado)
{
    int i;
    int auxiliarLegajo;
    int valorRetorno;
    char respuesta;

    printf("\nlIngrese legajo: ");
    scanf("%d", &auxiliarLegajo);

    for(i=0;i<tam; i++)
    {
        if(estado[i]==valorOcupado && auxiliarLegajo==legajo[i])
        {
            printf("\nDesea confirmar la operacion? s/n: ");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta=='s'){

                estado[i]=valorLibre;
                valorRetorno=1;

            } else {

                valorRetorno=-1;
            }

        }

    }

    return valorRetorno;
}


void MostrarAlumnos(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(estado[i]==valorOcupado)
        {
            printf("%10d %10d %10d %10.2f %10s\n", legajo[i], nota1[i], nota2[i], promedio[i], nombre[i]);
        }
    }
}


void OrdenarAlumnosPorNombre(int legajo[], int nota1[], int nota2[], float promedio[], char nombre[][20], int estado[], int tam, int valorOcupado)
{
    int i;
    int j;

    char auxString[20];
    int auxInt;
    float auxFloat;

    for(i=0; i<tam-1; i++)
    {
        if(estado[i]!=valorOcupado)
        {
            continue;
        }
        for(j=i+1; j<tam; j++)
        {
             if(estado[j]!=valorOcupado)
             {
                 continue;
             }
            if(strcmp(nombre[i], nombre[j])>0)
            {
                strcpy(auxString, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString);

                auxInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxInt;

                auxInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxInt;

                auxInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxInt;

                auxFloat = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxFloat;


            }
        }
    }
}

float CalculoPromedio(int nota1, int nota2)
{
    return ((float)nota1+nota2)/2;
}
