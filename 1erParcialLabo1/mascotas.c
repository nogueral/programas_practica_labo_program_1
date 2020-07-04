#include "mascotas.h"

void InicializarMascotas(eMascota listaMascotas[])
{
     int i;

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        listaMascotas[i].estado = LIBRE;
    }

}

void HardcodeoMascotas(eMascota listaMascotas[])
{
    char nombre[11][20]={"olivia","emma","ramon","pepe","orion",
                    "indio","maria","juan","pipo","zack","pedro"};
    int tipo[11]={100,100,101,101,100,101,102,101,100,100,101};
    char descripcion[11][20]={"gato","gato","perro","perro","gato",
                            "perro","raro","perro","gato","gato","perro"};
    char raza[11][20]={"generico","generico","generico","generico","generico",
                        "pitbull","raro","labrador","generico","generico","bulldog"};
    int edad[11]={5,4,4,3,2,1,8,9,7,6,5};
    float peso[11]={4.5,3.2,5.4,2.3,3.3,8.5,2.25,7.63,3.4,4.2,8.7};
    char sexo[11]={'f','f','m','m','m','m','m','m','m','m','m'};
    int idCliente[11]={1004,1004,1000,1000,1000,1003,1003,1001,1002,1002,1002};
    int idMascota[11]={100,101,102,103,104,105,106,107,108,109,110};
    int estado[11]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,
                    OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<11; i++)
    {
        strcpy(listaMascotas[i].nombre, nombre[i]);
        listaMascotas[i].tipo=tipo[i];
        strcpy(listaMascotas[i].descripcion, descripcion[i]);
        strcpy(listaMascotas[i].raza, raza[i]);
        listaMascotas[i].edad=edad[i];
        listaMascotas[i].peso=peso[i];
        listaMascotas[i].sexo=sexo[i];
        listaMascotas[i].idCliente=idCliente[i];
        listaMascotas[i].idMascota=idMascota[i];
        listaMascotas[i].estado=estado[i];

    }

}

int BuscarLibreMascota(eMascota listaMascotas[])
{
    int i;
    int indice = -1;

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int GenerateIdMascota(void)
{
    static int generatedIdMascota = 110;

    generatedIdMascota++;

    return generatedIdMascota;

}

int BajaMascota(eMascota listaMascotas[])
{
    int i;
    int auxiliarID;
    int valorRetorno=-1;
    char respuesta;

    printf("\nlIngrese ID de la mascota: ");
    scanf("%d", &auxiliarID);

    for(i=0;i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO && auxiliarID==listaMascotas[i].idMascota)
        {
           printf("\nEsta por eliminar el ID %d de la mascota %s ",
           listaMascotas[i].idMascota, listaMascotas[i].nombre);

           respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {

                listaMascotas[i].estado=LIBRE;
                valorRetorno=1;

            } else {

                valorRetorno=0;
            }
        }
    }

    return valorRetorno;
}

void CargarDescripcion (char descripcion[], int tipo)
{
    int i;
    int id[3]={100,101,102};
    char especie[3][20]={"gato","perro","raro"};

    for(i=0; i<3; i++)
    {
        if(id[i]==tipo)
        {
            strcpy(descripcion, especie[i]);
            break;
        }
    }

}

void MostrarTipoMascota (void)
{
    int i;
    int id[3]={100,101,102};
    char tipo[3][20]={"gato","perro","raro"};

    for(i=0; i<3; i++)
    {
        printf("ID: %d tipo: %s\n", id[i], tipo[i]);
    }
}

int ModificarMascota (eMascota listaMascotas[])
{
    int i;
    int auxiliarID;
    int opcion;
    char respuesta;
    int valorDeRetorno;
    char flagModifica='n';

    printf("\nIngrese ID Cliente: ");
    scanf("%d", &auxiliarID);

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO && auxiliarID==listaMascotas[i].idMascota)
        {
            printf("\nEsta por modificar el ID %d de la mascota %s",
            listaMascotas[i].idMascota, listaMascotas[i].nombre);

            respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                   do{

                    printf("\n 1. Nombre \n 2. Tipo \n 3. Raza \n 4. Edad \n 5. Peso \n 6. Sexo \n 7. Salir ");
                    printf("\n Ingrese el dato a modificar: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                    case 1:
                    CargarTexto("Ingrese el nombre: ", listaMascotas[i].nombre, 20);
                    flagModifica='s';
                    break;
                    case 2:
                    MostrarTipoMascota();
                    listaMascotas[i].tipo=GetInt("Ingrese tipo: ",
                    "Error, fuera de parametro, reingrese: ", 100, 102);
                    CargarDescripcion(listaMascotas[i].descripcion,
                    listaMascotas[i].tipo);
                    flagModifica='s';
                    break;
                    case 3:
                    CargarTexto("Ingrese raza: ", listaMascotas[i].raza,20);
                    flagModifica='s';
                    break;
                    case 4:
                    listaMascotas[i].edad=IngresarEntero("Ingrese edad: ");
                    flagModifica='s';
                    break;
                    case 5:
                    listaMascotas[i].peso=CargarFlotante("Ingrese peso: ");
                    flagModifica='s';
                    break;
                    case 6:
                    listaMascotas[i].sexo=GetChar("Ingrese sexo f o m: ",
                    "Error, fuera de parametro, reingrese: ", 'f','m');
                    flagModifica='s';
                    break;
                    }

                   } while(opcion!=7);

                   if(flagModifica=='s')
                   {
                        valorDeRetorno=1;
                        break;
                   } else {
                        valorDeRetorno=0;
                        break;

                   }

            } else {
                valorDeRetorno=0;
                break;
            }

        } else {

            valorDeRetorno=-1;
        }

    }


    return valorDeRetorno;

}

void OrdenarMascotasPorTipo(eMascota listaMascotas[])
{
    int i;
    int j;
    eMascota auxiliarMascota;

    for(i=0; i<SIZE_MASCOTAS-1; i++)
    {
        if(listaMascotas[i].estado!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<SIZE_MASCOTAS; j++)
        {
             if(listaMascotas[j].estado!=OCUPADO)
             {
                 continue;
             }
            if(listaMascotas[i].tipo>listaMascotas[j].tipo)
            {
                auxiliarMascota = listaMascotas[i];
                listaMascotas[i] = listaMascotas[j];
                listaMascotas[j] = auxiliarMascota;

            }
        }
    }
}

void MostrarMascotasPorTipo (eMascota listaMascotas[])
{
    int i;
    int tipo;

    MostrarTipoMascota();

    tipo=GetInt("Ingrese ID tipo: ", "Error, fuera de parametro, reingrese: ", 100, 102);

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO && listaMascotas[i].tipo==tipo)
        {
                printf("%10s %10d %10s %10s %10d %10.2f %10c\n",
                listaMascotas[i].nombre,
                listaMascotas[i].idMascota,
                listaMascotas[i].descripcion,
                listaMascotas[i].raza,
                listaMascotas[i].edad,
                listaMascotas[i].peso,
                listaMascotas[i].sexo);
        }
    }
}

void OrdenarMascotasPorNombre(eMascota listaMascotas[])
{
    eMascota auxiliarMascota;
    int i;
    int j;


    for(i=0; i<SIZE_MASCOTAS-1; i++)
    {
        if(listaMascotas[i].estado!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<SIZE_MASCOTAS; j++)
        {
             if(listaMascotas[j].estado!=OCUPADO)
             {
                 continue;
             }
            if(strcmp(listaMascotas[i].nombre, listaMascotas[j].nombre)>0)
            {
                auxiliarMascota = listaMascotas[i];
                listaMascotas[i] = listaMascotas[j];
                listaMascotas[j] = auxiliarMascota;
            }
        }
    }
}

int CantidadPosicionesCargadas (eMascota listaMascotas[])
{
    int i;
    int contador=0;

    for(i=0; i<SIZE_MASCOTAS; i++){
        if(listaMascotas[i].estado==OCUPADO){
            contador++;
        }
    }
    return contador;
}

int SumarEdadesMascotas(eMascota listaMascotas[])
{
    int suma=0;
    int i;

    for(i=0; i<SIZE_MASCOTAS; i++) {

        if(listaMascotas[i].estado==OCUPADO)
        {
            suma+=listaMascotas[i].edad;
        }

    }

    return suma;
}

float PromedioEdadMascotas (eMascota listaMascotas[])
{
    float promedio;
    int suma;
    int contador;

    suma=SumarEdadesMascotas(listaMascotas);
    contador=CantidadPosicionesCargadas(listaMascotas);

    promedio=(float)suma/contador;

    return promedio;
}

float PromedioEdadMascotasPorTipo (eMascota listaMascotas[])
{
    float promedio;
    int suma=0;
    int contador=0;
    int tipo;
    int i;

    MostrarTipoMascota();
    tipo=GetInt("Ingrese ID tipo: ", "Error, fuera de parametro, reingrese: ", 100, 102);

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO && listaMascotas[i].tipo==tipo)
        {
            suma+=listaMascotas[i].edad;
            contador++;
        }
    }

    promedio=(float)suma/contador;

    return promedio;
}
