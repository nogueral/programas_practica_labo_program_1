#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 5
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;

}eEmpleado;

int MostrarMenu(void);
void InicializarEstructura(eEmpleado[], int, int);
void InicializarID(eEmpleado[], int);
int BuscarLibre(eEmpleado[], int, int);
int CargarEmpleado(eEmpleado[], int, int, int);
int ModificarEmpleado (eEmpleado[], int, int);
int EliminarEmpleado(eEmpleado[], int, int, int);
void MostrarEmpleado (eEmpleado);
void OrdenarEmpleadosAscendente(eEmpleado[], int);
void OrdenarEmpleadosDescendente(eEmpleado[], int);
void MostrarTodosLosEmpleados(eEmpleado[], int, int);
int CantidadPosicionesCargadas (eEmpleado[], int, int);
float SumarSalarios (eEmpleado[], int, int);
float PromedioSalarios (eEmpleado[], int, int);
int CantidadEmpleadosSuperanSalarioPromedio (eEmpleado[], int, float);


int main()
{
    eEmpleado listaEmpleados[TAM];
    int valorRetorno;
    int opcion;
    float promedio;
    float suma;
    int contador;

    InicializarEstructura(listaEmpleados, TAM, LIBRE);
    InicializarID(listaEmpleados, TAM);

    do{
        opcion = MostrarMenu();

        switch(opcion)
        {
        case 1:
            valorRetorno=CargarEmpleado(listaEmpleados, TAM, LIBRE, OCUPADO);
            switch(valorRetorno)
            {
            case 1:
                printf("\nEmpleado cargado exitosamente\n");
                break;
            case 0:
                printf("\nOperacion cancelada\n");
                break;
            case -1:
                printf("\nNo hay mas espacio\n");
                break;
            }
            break;
        case 2:
             valorRetorno=ModificarEmpleado(listaEmpleados, TAM, OCUPADO);
             switch(valorRetorno)
             {
             case 1:
                printf("\nEmpleado modificado con exito\n");
                break;
             case 0:
                printf("\nOperacion cancelada\n");
                break;
             case -1:
                printf("\nNo se encuentra ID\n");
                break;
             }
            break;
        case 3:
             valorRetorno=EliminarEmpleado(listaEmpleados, TAM, LIBRE, OCUPADO);
             switch(valorRetorno)
             {
             case 1:
                printf("\nEmpleado eliminado exitosamente\n");
                break;
             case 0:
                printf("\nOperacion cancelada\n");
                break;
             case -1:
                printf("\nNo se encuentra el ID\n");
                break;
             }
             break;
        case 4:
              printf("\nDesea ordenar de forma: \n1. Ascendente \n2. Descendente \n3. Suma, promedio y cantidad de empleados que superan el salario promedio ");
              scanf("%d", &opcion);
              switch(opcion)
              {
              case 1:
                  OrdenarEmpleadosAscendente(listaEmpleados, TAM);
                  MostrarTodosLosEmpleados(listaEmpleados, TAM, OCUPADO);
                  break;
              case 2:
                  OrdenarEmpleadosDescendente(listaEmpleados, TAM);
                  MostrarTodosLosEmpleados(listaEmpleados, TAM, OCUPADO);
                  break;
              case 3:
                  promedio=PromedioSalarios(listaEmpleados, TAM, OCUPADO);
                  printf("\nEl promedio de salarios es: %.2f", promedio);
                  suma=SumarSalarios(listaEmpleados, TAM, OCUPADO);
                  printf("\nLa suma de salarios es: %.2f", suma);
                  contador=CantidadEmpleadosSuperanSalarioPromedio(listaEmpleados, TAM, promedio);
                  printf("\nLa cantidad de empleados que superan el salario promedio es: %d", contador);
                  break;
              }
              break;

        }

    }while(opcion!=5);



    return 0;
}

int MostrarMenu(void)
{
    int opcion;

    printf("\n1. Altas: \n2. Modificar: \n3. Baja: \n4. Informar: \n5. Salir: \nSeleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void InicializarEstructura(eEmpleado listadoEmpleados[], int tam, int valorLibre)
{
       int i;

    for(i=0; i<tam; i++)
    {
        listadoEmpleados[i].isEmpty = valorLibre;
    }
}

void InicializarID(eEmpleado listadoEmpleados[], int tam)
{
       int i;

    for(i=0; i<tam; i++)
    {
        listadoEmpleados[i].id = i+1;
    }
}

int BuscarLibre(eEmpleado listadoEmpleados[], int tam, int valorLibre)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(listadoEmpleados[i].isEmpty==valorLibre)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int CargarEmpleado(eEmpleado listadoEmpleados[], int tam, int valorLibre, int valorOcupado)
{
    int indiceEncontrado;
    char respuesta;

    indiceEncontrado = BuscarLibre(listadoEmpleados, tam, valorLibre);

    if(indiceEncontrado!=-1)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(listadoEmpleados[indiceEncontrado].name);

        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(listadoEmpleados[indiceEncontrado].lastname);

        printf("\nIngrese salario: ");
        scanf("%f", &listadoEmpleados[indiceEncontrado].salary);

        do{
            printf("\nIngrese sector: \n1. Direccion: \n2. Contaduria y Finanzas: \n3. Produccion: \n4. Ventas: \n5. Administracion: ");
            scanf("%d", &listadoEmpleados[indiceEncontrado].sector);
        }while(listadoEmpleados[indiceEncontrado].sector<1 || listadoEmpleados[indiceEncontrado].sector>5);

        do{  printf("\n Desea confirmar la operacion? s/n: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta=tolower(respuesta);
            }while(respuesta!='s' && respuesta!='n');

            if(respuesta=='s')
            {
                printf("\nSu numero de ID es: %d", listadoEmpleados[indiceEncontrado].id);
                listadoEmpleados[indiceEncontrado].isEmpty = valorOcupado;
                indiceEncontrado = 1;

            } else {

                indiceEncontrado = 0;
            }

    }

    return indiceEncontrado;
}



int ModificarEmpleado (eEmpleado listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int auxiliarID;
    int opcion;
    char respuesta;
    int valorDeRetorno=-1;

    printf("\nIngrese ID: ");
    scanf("%d", &auxiliarID);

    for(i=0; i<tam; i++)
    {
        if(listadoEmpleados[i].isEmpty==valorOcupado && auxiliarID==listadoEmpleados[i].id)
        {

            printf("\n Desea modificar el ID %d del empleado %s %s? s/n: ", listadoEmpleados[i].id, listadoEmpleados[i].name, listadoEmpleados[i].lastname);
            fflush(stdin);
            scanf("%c", &respuesta);
            respuesta=tolower(respuesta);

            if(respuesta=='s')
            {
                   do{
                        printf("\n Ingrese el dato a modificar: ");
                        printf("\n 1. Nombre: \n 2. Apellido: \n 3. Sueldo: \n 4. Sector: \n 5. Salir: \n");
                        scanf("%d", &opcion);
                   }while(opcion<1 || opcion>5);

                    switch(opcion)
                    {
                    case 1:
                    printf("\nIngrese nombre: ");
                    fflush(stdin);
                    gets(listadoEmpleados[i].name);
                    valorDeRetorno=1;
                    printf("\nDato modificado con exito!\n");
                    break;
                    case 2:
                    printf("\nIngrese apellido: ");
                    fflush(stdin);
                    gets(listadoEmpleados[i].lastname);
                    valorDeRetorno=1;
                    printf("\nDato modificado con exito!\n");
                    break;
                    case 3:
                    printf("\nIngrese salario: ");
                    scanf("%f", &listadoEmpleados[i].salary);
                    valorDeRetorno=1;
                    printf("\nDato modificado con exito!\n");
                    break;
                    case 4:
                    do{
                    printf("\nIngrese sector: \n1. Direccion: \n2. Contaduria y Finanzas: \n3. Produccion: \n4. Ventas: \n5. Administracion: ");
                    scanf("%d", &listadoEmpleados[i].sector);
                    }while(listadoEmpleados[i].sector<1 || listadoEmpleados[i].sector>5);
                    case 5:
                    valorDeRetorno=0;
                    break;
                    }

            } else {
                valorDeRetorno=0;
            }
        }

    }


    return valorDeRetorno;

}

int EliminarEmpleado(eEmpleado listadoEmpleados[], int tam, int valorLibre, int valorOcupado)
{
    int i;
    int auxiliarID;
    int valorRetorno=-1;
    char respuesta;

    printf("\nlIngrese ID: ");
    scanf("%d", &auxiliarID);

    for(i=0;i<tam; i++)
    {
        if(listadoEmpleados[i].isEmpty==valorOcupado && auxiliarID==listadoEmpleados[i].id)
        {
           do{  printf("\nDesea eliminar el ID %d del empleado %s %s? s/n: ", listadoEmpleados[i].id, listadoEmpleados[i].name, listadoEmpleados[i].lastname);
                fflush(stdin);
                scanf("%c", &respuesta);
                respuesta=tolower(respuesta);
           }while(respuesta!='s' && respuesta!='n');

            if(respuesta=='s'){

                listadoEmpleados[i].isEmpty=valorLibre;
                valorRetorno=1;

            } else {

                valorRetorno=0;
            }

        }

    }

    return valorRetorno;
}

void MostrarEmpleado (eEmpleado listadoEmpleados)
{
            printf("%10d %10s %10s %10.2f %10d\n",
            listadoEmpleados.id,
            listadoEmpleados.name,
            listadoEmpleados.lastname,
            listadoEmpleados.salary,
            listadoEmpleados.sector);
}

void OrdenarEmpleadosAscendente(eEmpleado listadoEmpleados[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoEmpleados[i].lastname,listadoEmpleados[j].lastname)>0)
            {
               auxEmpleado = listadoEmpleados[i];
               listadoEmpleados[i] = listadoEmpleados[j];
               listadoEmpleados[j] = auxEmpleado;
            }

        }
    }

}

void OrdenarEmpleadosDescendente(eEmpleado listadoEmpleados[], int tam)
{
    int i;
    int j;
    eEmpleado auxEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoEmpleados[i].lastname,listadoEmpleados[j].lastname)<0)
            {
               auxEmpleado  =  listadoEmpleados[i];
               listadoEmpleados[i] = listadoEmpleados[j];
               listadoEmpleados[j] = auxEmpleado;
            }

        }
    }

}
void MostrarTodosLosEmpleados(eEmpleado listadoEmpleados[], int tam, int valorOcupado)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoEmpleados[i].isEmpty==valorOcupado)
        {
            MostrarEmpleado(listadoEmpleados[i]);
        }
    }

}

int CantidadPosicionesCargadas (eEmpleado listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int contador=0;

    for(i=0; i<tam; i++){
        if(listadoEmpleados[i].isEmpty==valorOcupado){
            contador++;
        }
    }
    return contador;
}

float SumarSalarios (eEmpleado listadoEmpleados[], int tam, int valorOcupado)
{
    float suma=0;
    int i;

    for(i=0; i<tam; i++) {

        if(listadoEmpleados[i].isEmpty==valorOcupado)
        {
        suma+=listadoEmpleados[i].salary;
        }

    }

    return suma;
}

float PromedioSalarios (eEmpleado listadoEmpleados[], int tam, int valorOcupado)
{
    float promedio;
    float acumulador;
    int contador;

    acumulador=SumarSalarios(listadoEmpleados, tam, valorOcupado);
    contador=CantidadPosicionesCargadas(listadoEmpleados, tam, valorOcupado);

    promedio = (float)acumulador/contador;

    return promedio;
}

int CantidadEmpleadosSuperanSalarioPromedio (eEmpleado listadoEmpleados[], int tam, float promedio)
{
    int i;
    int contador=0;

    for(i=0; i<tam; i++)
    {
        if(listadoEmpleados[i].salary>promedio)
        {
            contador++;
        }
    }
    return contador;
}
