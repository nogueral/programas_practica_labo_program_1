#include "abonado.h"

void HardcodeoAbonado(eAbonado listaAbonados[])
{
    int idAbonado[5]={100,101,102,103,104};
    long int numero[5]={1522223333,1522223333,1522223333,1522223333,1522223333};
    char nombre[5][20]={"Maria","Juan","Nicolas","Pedro","Jose"};
    char apellido[5][20]={"Perez","Medina","Flores","Gomez","Gomez"};
    int estado[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<SIZE_ABONADO; i++)
    {
        listaAbonados[i].idAbonado=idAbonado[i];
        listaAbonados[i].numero=numero[i];
        strcpy(listaAbonados[i].nombre, nombre[i]);
        strcpy(listaAbonados[i].apellido, apellido[i]);
        listaAbonados[i].estado=estado[i];
    }

}
void InicializarAbonados(eAbonado listaAbonados[])
{
       int i;

    for(i=0; i<SIZE_ABONADO; i++)
    {
        listaAbonados[i].estado = LIBRE;
    }

}

void HardcodeoLlamadas(eLlamada listaLlamadas[])
{
    int idAbonado[5]={100,101,101,103,103};
    int idLlamada[5]={1001,1002,1003,1004,1005};
    int motivo[5]={FALLA_3G,FALLA_EQUIPO,FALLA_3G,FALLA_LTE,FALLA_EQUIPO};
    int estado[5]={NO_SOLUCIONADO,SOLUCIONADO,NO_SOLUCIONADO,SOLUCIONADO,EN_CURSO};
    int tiempo[5]={5,7,4,3,1};
    int isEmpty[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<SIZE_LLAMADAS; i++)
    {
        listaLlamadas[i].idAbonado=idAbonado[i];
        listaLlamadas[i].idLlamada=idLlamada[i];
        listaLlamadas[i].motivo=motivo[i];
        listaLlamadas[i].estado=estado[i];
        listaLlamadas[i].tiempo=tiempo[i];
        listaLlamadas[i].isEmpty=isEmpty[i];
    }

}
void InicializarLlamadas(eLlamada listaLlamadas[])
{
       int i;

    for(i=0; i<SIZE_LLAMADAS; i++)
    {
        listaLlamadas[i].isEmpty = LIBRE;
    }

}
int MostrarMenu(void)
{
    int opcion;

    printf("\n1. Cargar\n2. Modificar\n3. Eliminar\n4. Cargar llamada\n5. Fin llamada\n6. Listar\n7. Salir\nSeleccione la opcion que desee: ");
    scanf("%d", &opcion);

    return opcion;
}
int BuscarLibre(eAbonado listaAbonados[])
{
    int i;
    int indice = -1;

    for(i=0; i<SIZE_ABONADO; i++)
    {
        if(listaAbonados[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int GenerateIdAbonado(void)
{
    static int generatedIdAbonado = 100;

    generatedIdAbonado++;

    return generatedIdAbonado;

}
void CargarTexto (char mensaje[], char texto[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(texto);
}
long int GetLongInt (char mensaje[])
{
    long int num;

        printf("%s",mensaje);
        scanf("%ld", &num);

    return num;
}
char ConfirmarOperacion (void)
{
    char respuesta;

    do{  printf("\n Desea continuar? s/n: ");
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta=tolower(respuesta);
    }while(respuesta!='s' && respuesta!='n');

    return respuesta;
}
int CargarAbonado(eAbonado listaAbonados[])
{
    int indiceEncontrado;
    char respuesta;

    indiceEncontrado = BuscarLibre(listaAbonados);

    if(indiceEncontrado!=-1)
    {


        CargarTexto("Ingrese su nombre: ", listaAbonados[indiceEncontrado].nombre);

        CargarTexto("Ingrese su apellido: ", listaAbonados[indiceEncontrado].apellido);

        listaAbonados[indiceEncontrado].numero=GetLongInt("Ingrese su numero telefonico: ");

        respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                listaAbonados[indiceEncontrado].idAbonado = GenerateIdAbonado();
                printf("\nSu numero de ID es: %d", listaAbonados[indiceEncontrado].idAbonado);
                listaAbonados[indiceEncontrado].estado = OCUPADO;
                indiceEncontrado = 1;

            } else {

                indiceEncontrado = 0;
            }

    }

    return indiceEncontrado;
}
void MostrarUnAbonado (eAbonado listaAbonados)
{
    printf("%10d %10s %10s %20ld\n",
    listaAbonados.idAbonado,
    listaAbonados.nombre,
    listaAbonados.apellido,
    listaAbonados.numero);
}

void MostrarAbonados(eAbonado listaAbonados[])
{
    int i;

    for(i=0; i<SIZE_ABONADO; i++)
    {
        if(listaAbonados[i].estado==OCUPADO)
        {
           MostrarUnAbonado(listaAbonados[i]);
        }
    }
}
int ModificarAbonado (eAbonado listaAbonados[])
{
    int i;
    int auxiliarID;
    int opcion;
    char respuesta;
    int valorDeRetorno;
    char flagModifica='n';

    printf("\nIngrese ID: ");
    scanf("%d", &auxiliarID);

    for(i=0; i<SIZE_ABONADO; i++)
    {
        if(listaAbonados[i].estado==OCUPADO && auxiliarID==listaAbonados[i].idAbonado)
        {
            printf("\nEsta por modificar el ID %d del abonado %s %s ",
                   listaAbonados[i].idAbonado, listaAbonados[i].nombre,
                   listaAbonados[i].apellido);

            respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                   do{
                    printf("\n Ingrese el dato a modificar: ");
                    printf("\n 1. Nombre: \n 2. Apellido: \n 3. Salir: \n");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                    case 1:
                    CargarTexto("Ingrese su nombre: ", listaAbonados[i].nombre);
                    valorDeRetorno=1;
                    flagModifica='s';
                    break;
                    case 2:
                    CargarTexto("Ingrese su nombre: ", listaAbonados[i].apellido);
                    valorDeRetorno=1;
                    flagModifica='s';
                    break;
                    }
                   } while(opcion!=3);

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
int EliminarAbonado(eAbonado listaAbonados[])
{
    int i;
    int auxiliarID;
    int valorRetorno=-1;
    char respuesta;

    printf("\nlIngrese ID: ");
    scanf("%d", &auxiliarID);

    for(i=0;i<SIZE_ABONADO; i++)
    {
        if(listaAbonados[i].estado==OCUPADO && auxiliarID==listaAbonados[i].idAbonado)
        {
           printf("\nEsta por eliminar el ID %d del abonado %s %s", listaAbonados[i].idAbonado,
                   listaAbonados[i].nombre,
                   listaAbonados[i].apellido);

           respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {

                listaAbonados[i].estado=LIBRE;
                valorRetorno=1;

            } else {

                valorRetorno=0;
            }

        }

    }

    return valorRetorno;
}
int BuscarLibreParaLlamadas(eLlamada listaLlamadas[])
{
    int i;
    int indice = -1;

    for(i=0; i<SIZE_LLAMADAS; i++)
    {
        if(listaLlamadas[i].isEmpty==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int GenerateIdLlamada(void)
{
    static int generatedIdLlamada = 1000;

    generatedIdLlamada++;

    return generatedIdLlamada;

}
int CargarLlamada(eLlamada listaLlamadas[], eAbonado listaAbonados[])
{

    int i;
    int auxiliarID;
    int indiceEncontrado;
    int opcion;
    char respuesta;
    int valorDeRetorno=-1;

    indiceEncontrado=BuscarLibreParaLlamadas(listaLlamadas);

    if(indiceEncontrado!=-1)
    {
        printf("\nIngrese ID de abonado: ");
        scanf("%d", &auxiliarID);

        for(i=0; i<SIZE_ABONADO; i++)
        {
            if(listaAbonados[i].estado==OCUPADO && auxiliarID==listaAbonados[i].idAbonado)
            {
            printf("\nEsta por cargar un reclamo en el ID %d del abonado %s %s ",
                   listaAbonados[i].idAbonado, listaAbonados[i].nombre,
                   listaAbonados[i].apellido);

            respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
              do{printf("\nIngrese codigo motivo: ");
              printf("\nFalla 3G (1) \nFalla LTE (2)\nFalla equipo (3): ");
              scanf("%d", &opcion);
              }while(opcion!=1 && opcion!=2 && opcion!=3);

              listaLlamadas[indiceEncontrado].motivo=opcion;
              listaLlamadas[indiceEncontrado].estado=EN_CURSO;
              listaLlamadas[indiceEncontrado].idAbonado=listaAbonados[i].idAbonado;
              listaLlamadas[indiceEncontrado].isEmpty=OCUPADO;
              listaLlamadas[indiceEncontrado].idLlamada=GenerateIdLlamada();
              listaLlamadas[indiceEncontrado].tiempo=0;
              printf("\nSu numero de reclamo es: %d", listaLlamadas[indiceEncontrado].idLlamada);
              valorDeRetorno=1;
              break;

            } else {

                valorDeRetorno=0;
                break;
            }

            } else {

                valorDeRetorno=-2;
            }
        }

    }

    return valorDeRetorno;
}
int FinalizarLlamada(eAbonado listaAbonados[], eLlamada listaLlamadas[])
{
    int i;
    int auxiliarID;
    int valorRetorno=-1;
    char respuesta;
    int opcion;

    printf("\nlIngrese ID del reclamo: ");
    scanf("%d", &auxiliarID);

    for(i=0;i<SIZE_LLAMADAS; i++)
    {
        if(listaLlamadas[i].isEmpty==OCUPADO && auxiliarID==listaLlamadas[i].idLlamada)
        {
           printf("\nEsta por modificar el estado del reclamo ID %d del abonado %s %s",
                   listaAbonados[i].idAbonado,
                   listaAbonados[i].nombre,
                   listaAbonados[i].apellido);

           respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                do{printf("\nSeleccione el estado: \n1. Solucionado: \n2. No solucionado: \n");
                scanf("%d", &opcion);
                }while(opcion!=1 && opcion!=2);
                if(opcion==1)
                {
                    listaLlamadas[i].estado=SOLUCIONADO;

                } else {

                    listaLlamadas[i].estado=NO_SOLUCIONADO;
                }

                printf("\nIngrese la cantidad de dias que demoro la reparacion: ");
                scanf("%d", &listaLlamadas[i].tiempo);
                valorRetorno=1;

            } else {

                valorRetorno=0;
            }

        }

    }

    return valorRetorno;
}

void MostrarUnLlamado (eLlamada listaLlamadas)
{
    printf("%10d %10d %10d %10d %10d\n",
    listaLlamadas.idAbonado,
    listaLlamadas.idLlamada,
    listaLlamadas.motivo,
    listaLlamadas.estado,
    listaLlamadas.tiempo);
}

void MostrarLlamados(eLlamada listaLlamadas[])
{
    int i;

    for(i=0; i<SIZE_LLAMADAS; i++)
    {
        if(listaLlamadas[i].isEmpty==OCUPADO)
        {
           MostrarUnLlamado(listaLlamadas[i]);
        }
    }
}
void AbonadoConMasReclamos(eAbonado listaAbonados[], eLlamada listaLlamadas[])
{
    int i; // Llamados
    int j; // Abonados
    int contador[SIZE_ABONADO];
    int maximo;

    for(j=0; j<SIZE_ABONADO; j++)
    {
        contador[j]=0;
    }

    for (j=0; j<SIZE_ABONADO; j++)
    {
        for(i=0; i<SIZE_LLAMADAS; i++)
        {
            if(listaLlamadas[i].idAbonado == listaAbonados[j].idAbonado)
            {
                contador[j]++;
            }
        }

        if(j==0 || contador[j]>maximo)
        {
            maximo=contador[j];
        }

    }

    for(j=0; j<SIZE_ABONADO; j++)
    {
        if(contador[j]==maximo && listaAbonados[j].estado==OCUPADO)
        {
            printf("\nEl abonado %s %s tiene %d reclamos", listaAbonados[j].nombre,
                   listaAbonados[j].apellido,
                   maximo);
        }
    }


}
void ReclamoMasRealizado(eLlamada listaLlamadas[])
{
    int i; // Llamados
    int j; // reclamos
    int reclamos[3]={1,2,3};
    int contador[3];
    int maximo;

    for(j=0; j<3; j++)
    {
        contador[j]=0;
    }

    for (j=0; j<3; j++) //reclamos
    {
        for(i=0; i<SIZE_LLAMADAS; i++) //llamadas
        {
            if(listaLlamadas[i].motivo == reclamos[j])
            {
                contador[j]++;
            }
        }

        if(j==0 || contador[j]>maximo)
        {
            maximo=contador[j];
        }

    }

    for(j=0; j<3; j++)
    {
        if(contador[j]==maximo)
        {
            printf("\nEl reclamo %d tiene %d reclamos", reclamos[j], maximo);
        }
    }


}
void ReclamoQueMasDemoraEnSerResuelto(eLlamada listaLlamadas[])
{
    int i; // Llamados
    int j; // reclamos
    int reclamos[3]={1,2,3};
    int contador[3];
    float maximo;
    float promedio[3];
    int acumulador[3];

    for(j=0; j<3; j++)
    {
        contador[j]=0;
        acumulador[j]=0;
    }

    for (j=0; j<3; j++) //reclamos
    {
        for(i=0; i<SIZE_LLAMADAS; i++) //llamadas
        {
            if(listaLlamadas[i].motivo == reclamos[j])
            {
                contador[j]++;
                acumulador[j]+=listaLlamadas[i].tiempo;

            }
        }

        promedio[j]=(float)acumulador[j]/contador[j];

        if(j==0 || promedio[j]>maximo)
        {
            maximo=promedio[j];
        }

    }

    for(j=0; j<3; j++)
    {
        if(promedio[j]==maximo)
        {
            printf("\nEl reclamo %d es el que en promedio mas tarda en ser resuelto con %.2f dias",
                   reclamos[j], maximo);
        }
    }


}
