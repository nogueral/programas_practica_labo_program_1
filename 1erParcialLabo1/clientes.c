#include "clientes.h"

void InicializarClientes(eCliente listaClientes[])
{
     int i;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        listaClientes[i].estado = LIBRE;
    }

}

void HardcodeoCliente(eCliente listaClientes[])
{
    char nombre[5][20]={"pablo","mauricio","nicolas","laura","maria"};
    char apellido[5][20]={"bustamente","sivak","gomez","diaz","losa"};
    char localidad[5][20]={"avellaneda","lanus","vicente lopez","capital federal","capital federal"};
    long int telefono[5]={1530226655,1544223311,1577889922,1511446699,1588779922};
    int edad[5]={30,35,43,38,54};
    char sexo[5]={'m','m','m','f','f'};
    int idCliente[5]={1000,1001,1002,1003,1004};
    int estado[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;

    for(i=0; i<5; i++)
    {
        strcpy(listaClientes[i].nombre, nombre[i]);
        strcpy(listaClientes[i].apellido, apellido[i]);
        strcpy(listaClientes[i].localidad, localidad[i]);
        listaClientes[i].telefono=telefono[i];
        listaClientes[i].edad=edad[i];
        listaClientes[i].sexo=sexo[i];
        listaClientes[i].idCliente=idCliente[i];
        listaClientes[i].estado=estado[i];

    }

}

void MostrarUnCliente (eCliente listaClientes)
{
    printf("%10d %10s %10s %20s %20ld %10d %10c\n",
    listaClientes.idCliente,
    listaClientes.nombre,
    listaClientes.apellido,
    listaClientes.localidad,
    listaClientes.telefono,
    listaClientes.edad,
    listaClientes.sexo);
}

void PrintClientes (eCliente listaClientes[])
{
    int i;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==OCUPADO)
        {
            MostrarUnCliente(listaClientes[i]);
        }

    }

}

int BuscarLibreClientes(eCliente listaClientes[])
{
    int i;
    int indice = -1;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int GenerateIdCliente(void)
{
    static int generatedIdCliente = 1004;

    generatedIdCliente++;

    return generatedIdCliente;

}

int AltaDueno(eCliente listaClientes[])
{
    int indiceEncontrado;
    char respuesta;

    indiceEncontrado = BuscarLibreClientes(listaClientes);

    if(indiceEncontrado!=-1)
    {

        CargarTexto("Ingrese nombre: ", listaClientes[indiceEncontrado].nombre, 20);
        CargarTexto("Ingrese apellido: ", listaClientes[indiceEncontrado].apellido, 20);
        CargarTexto("Ingrese localidad: ", listaClientes[indiceEncontrado].localidad, 20);
        listaClientes[indiceEncontrado].telefono=GetLongInt("Ingrese telefono: ");
        listaClientes[indiceEncontrado].edad=IngresarEntero("Ingrese su edad: ");
        listaClientes[indiceEncontrado].sexo=GetChar("Ingrese sexo f o m: ",
        "Error, fuera de parametro. Ingrese f o m: ", 'f', 'm');

        respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                listaClientes[indiceEncontrado].idCliente = GenerateIdCliente();
                printf("\nEl numero de ID es: %d", listaClientes[indiceEncontrado].idCliente);
                listaClientes[indiceEncontrado].estado = OCUPADO;
                indiceEncontrado = 1;

            } else {

                indiceEncontrado = 0;
            }

    }

    return indiceEncontrado;
}

int ModificarDueno (eCliente listaClientes[])
{
    int i;
    int auxiliarID;
    int opcion;
    char respuesta;
    int valorDeRetorno;
    char flagModifica='n';

    printf("\nIngrese ID Cliente: ");
    scanf("%d", &auxiliarID);

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==OCUPADO && auxiliarID==listaClientes[i].idCliente)
        {
            printf("\nEsta por modificar el ID %d del cliente %s %s",
            listaClientes[i].idCliente, listaClientes[i].nombre, listaClientes[i].apellido);

            respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                   do{

                    printf("\n 1. Nombre \n 2. apellido \n 3. Localidad \n 4. Telefono \n 5. Edad \n 6. Sexo \n 7. Salir ");
                    printf("\n Ingrese el dato a modificar: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                    case 1:
                    CargarTexto("Ingrese el nombre: ", listaClientes[i].nombre, 20);
                    flagModifica='s';
                    break;
                    case 2:
                    CargarTexto("Ingrese el apellido: ", listaClientes[i].apellido, 20);
                    flagModifica='s';
                    break;
                    case 3:
                    CargarTexto("Ingrese localidad: ", listaClientes[i].localidad,20);
                    flagModifica='s';
                    break;
                    case 4:
                    listaClientes[i].telefono=GetLongInt("Ingrese telefono: ");
                    flagModifica='s';
                    break;
                    case 5:
                    listaClientes[i].edad=IngresarEntero("Ingrese edad: ");
                    flagModifica='s';
                    break;
                    case 6:
                    listaClientes[i].sexo=GetChar("Ingrese sexo f o m: ",
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

int CantidadClientesCargados (eCliente listaClientes[])
{
    int i;
    int contador=0;

    for(i=0; i<SIZE_CLIENTES; i++){
        if(listaClientes[i].estado==OCUPADO){
            contador++;
        }
    }
    return contador;
}
void PromedioVaronesYMujeres (eCliente listaClientes[])
{
    int i;
    int cantidadVarones=0;
    int cantidadMujeres=0;
    int cantidadClientes;
    float promedioVarones;
    float promedioMujeres;

    cantidadClientes=CantidadClientesCargados(listaClientes);

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==OCUPADO && listaClientes[i].sexo=='f')
        {
            cantidadMujeres++;
        }

        if(listaClientes[i].estado==OCUPADO && listaClientes[i].sexo=='m')
        {
            cantidadVarones++;
        }
    }

    promedioMujeres=(float)cantidadMujeres/cantidadClientes;
    promedioVarones=(float)cantidadVarones/cantidadClientes;

    printf("El promedio de mujeres es de: %.2f", promedioMujeres);
    printf("\nEl promedio de varones es de: %.2f\n", promedioVarones);

}
