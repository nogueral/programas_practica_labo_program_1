/*
3. Crear una funcion que reciba como parametros un array del tipo Alumno (legajo, nombre, promedio).
Dicha función permitirá realizar el ordenamiento del array por nombre, y ante igualdad de nombre,
por promedio de menor a mayor. Realizar las comprobaciones desde el main.
*/
#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define SIZE 5

typedef struct
{
    int legajo;
    char nombre[20];
    float promedio;
    int estado;

}eAlumno;

typedef int (*tpfOrdenar) (eAlumno*, int);

int InicializarEstructura(eAlumno* listaAlumnos, int tam);
void HardcodeoAlumnos(eAlumno* punteroAlumnos);
int OrdenarPorNombreYPromedio(eAlumno* listaAlumnos, int tam);
int OrdenarPorNombreYLegajo(eAlumno* listaAlumnos, int tam);
int Ordenar(eAlumno*, int, tpfOrdenar pOrdenar);
void MostrarEstructura(eAlumno* listaAlumnos, int tam);
int main()
{
    eAlumno listaAlumnos[SIZE];
    int retorno;

    retorno=InicializarEstructura(listaAlumnos, SIZE);
    if(retorno==0)
    {
        printf("Ok inicializacion");

    } else {

        printf("Puntero no inicializado");
    }

    HardcodeoAlumnos(listaAlumnos);

    retorno=Ordenar(listaAlumnos, SIZE, OrdenarPorNombreYLegajo);
    if(retorno==0)
    {
        printf("\nSE MUESTRA CADENA ORDENADA POR NOMBRE Y LEGAJO: ");
        MostrarEstructura(listaAlumnos, SIZE);

    } else {

        printf("Puntero no inicializado");
    }

    retorno=Ordenar(listaAlumnos, SIZE, OrdenarPorNombreYPromedio);
    if(retorno==0)
    {
        printf("\nSE MUESTRA CADENA ORDENADA POR NOMBRE Y PROMEDIO: ");
        MostrarEstructura(listaAlumnos, SIZE);

    } else {

        printf("Puntero no inicializado");
    }


    return 0;
}

int InicializarEstructura(eAlumno* listaAlumnos, int tam)
{
    int i;
    int retorno=-1;

    if(listaAlumnos!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            (listaAlumnos+i)->estado=LIBRE;
        }

       retorno=0;
    }

    return retorno;
}

void HardcodeoAlumnos(eAlumno* listaAlumnos)
{
    int i;
    int legajo[5]={100,101,102,103,104};
    char nombre[5][20]={"leandro","leandro","pedro","nicolas","laura"};
    float promedio[5]={5.5,4.5,8,9,7.5};
    int estado[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    if(listaAlumnos!=NULL)
    {
         for(i=0;i<5;i++)
        {
            (listaAlumnos+i)->legajo=legajo[i];
            strcpy((listaAlumnos+i)->nombre, nombre[i]);
            (listaAlumnos+i)->promedio=promedio[i];
            (listaAlumnos+i)->estado=estado[i];
        }


    }

}

int OrdenarPorNombreYPromedio(eAlumno* listaAlumnos, int tam)
{
    int i;
    int j;
    eAlumno auxiliar;
    int retorno;


    if(listaAlumnos!=NULL)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp((listaAlumnos+i)->nombre,(listaAlumnos+j)->nombre)>0 || (strcmp((listaAlumnos+i)->nombre,(listaAlumnos+j)->nombre)==0 && (listaAlumnos+i)->promedio>(listaAlumnos+j)->promedio))
                {
                    auxiliar=*(listaAlumnos+i);
                    *(listaAlumnos+i)=*(listaAlumnos+j);
                    *(listaAlumnos+j)=auxiliar;
                }
            }
        }

        retorno = 0;

    }  else {

        retorno = -1;
    }

    return retorno;
}
int OrdenarPorNombreYLegajo(eAlumno* listaAlumnos, int tam)
{
    int i;
    int j;
    eAlumno auxiliar;
    int retorno;


    if(listaAlumnos!=NULL)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp((listaAlumnos+i)->nombre,(listaAlumnos+j)->nombre)>0 || (strcmp((listaAlumnos+i)->nombre,(listaAlumnos+j)->nombre)==0 && (listaAlumnos+i)->legajo>(listaAlumnos+j)->legajo))
                {
                    auxiliar=*(listaAlumnos+i);
                    *(listaAlumnos+i)=*(listaAlumnos+j);
                    *(listaAlumnos+j)=auxiliar;
                }
            }
        }

        retorno = 0;

    }  else {

        retorno = -1;
    }

    return retorno;
}

int Ordenar(eAlumno*listaAlumnos, int tam, tpfOrdenar pOrdenar)
{
    int retorno;

    retorno = pOrdenar(listaAlumnos, tam);

    return retorno;
}

void MostrarEstructura(eAlumno* listaAlumnos, int tam)
{
    int i;

    if(listaAlumnos!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            printf("\n%10d %20s %10.2f ",
            (listaAlumnos+i)->legajo,
            (listaAlumnos+i)->nombre,
            (listaAlumnos+i)->promedio);
        }
    }
}
