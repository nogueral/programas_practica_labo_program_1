#include "ClientesMascotas.h"

int MostrarMenu(void)
{
    int opcion;
    printf("\n*****MENU*****");
    printf("\n1. Lista clientes");
    printf("\n2. Lista mascotas");
    printf("\n3. Lista de clientes con mascotas");
    printf("\n4. Cargar mascota");
    printf("\n5. Baja mascota");
    printf("\n6. Modificar mascota");
    printf("\n7. Alta dueno");
    printf("\n8. Eliminar dueno en cascada");
    printf("\n9. Ordenar mascotas por tipo y listarlas con su dueno");
    printf("\n10. Modificar dueno");
    printf("\n11. Listar clientes con mas de una mascota");
    printf("\n12. Listar mascotas de mas de tres anos, con sus respectivos duenos");
    printf("\n13. Listar mascotas por un tipo en particular");
    printf("\n14. Ordenar duenos por cantidad de mascotas y mostrar");
    printf("\n15. Ordenar duenos por cantidad de mascotas y por nombre y mostrar");
    printf("\n16. Promedio de edad entre mascotas");
    printf("\n17. Promedio de edad entre mascotas por tipo");
    printf("\n18. Promedio de varones y mujeres");
    printf("\n19. Salir");
    printf("\nSeleccione la opcion que desee: ");
    scanf("%d", &opcion);
    printf("\n**************\n");


    return opcion;
}

void MostrarMascotasConSuDueno(eCliente listaClientes[], eMascota listaMascotas[])
{
    int i;//Mascotas
    int j;//dueños

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO)
        {

        for(j=0; j<SIZE_CLIENTES; j++)
        {
            if(listaMascotas[i].estado==OCUPADO && listaMascotas[i].idCliente==listaClientes[j].idCliente)
            {
                   printf("%10s %10d %10s %10s %10d %10.2f %10c %10s %10s\n",
                            listaMascotas[i].nombre,
                            listaMascotas[i].idMascota,
                            listaMascotas[i].descripcion,
                            listaMascotas[i].raza,
                            listaMascotas[i].edad,
                            listaMascotas[i].peso,
                            listaMascotas[i].sexo,
                            listaClientes[j].nombre,
                            listaClientes[j].apellido);
                            break;
            }

        }

        }

    }

}

void MostrarDuenosConSusMascotas(eCliente listaClientes[], eMascota listaMascotas[])
{
    int i;//duenos
    int j;//mascotas
    char flagTieneMascota;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
       if(listaClientes[i].estado==OCUPADO)
       {

        printf("Cliente: %s %s\n", listaClientes[i].nombre, listaClientes[i].apellido);
        flagTieneMascota='n';

        for(j=0; j<SIZE_MASCOTAS; j++)
        {
            if(listaMascotas[j].estado == OCUPADO && listaMascotas[j].idCliente /*FK*/ == listaClientes[i].idCliente /*PK*/)
            {
                printf("%10s %10d %10s %10s %10d %10.2f %10c\n",
                listaMascotas[j].nombre,
                listaMascotas[j].idMascota,
                listaMascotas[j].descripcion,
                listaMascotas[j].raza,
                listaMascotas[j].edad,
                listaMascotas[j].peso,
                listaMascotas[j].sexo);
                flagTieneMascota='s';

            }

        }

        if(flagTieneMascota=='n')
        {
            printf("Este cliente no tiene mascotas\n");
        }

       }

    }
}

int SeleccionarIdCliente(eCliente listaClientes[])
{
    int i;
    int retorno;
    int idCliente;

    do{

    printf("\nSE IMPRIME LISTADO DE CLIENTES: \n");
    PrintClientes(listaClientes);
    printf("\nIngrese ID cliente: ");
    scanf("%d", &idCliente);

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==OCUPADO && listaClientes[i].idCliente==idCliente)
        {
            retorno=idCliente;
            break;
        }
    }

    }while(retorno!=idCliente);

    return retorno;
}

int CargarMascota(eCliente listaClientes[], eMascota listaMascotas[])
{
    int indiceEncontrado;
    char respuesta;

    indiceEncontrado = BuscarLibreMascota(listaMascotas);

    if(indiceEncontrado!=-1)
    {
        listaMascotas[indiceEncontrado].idCliente=SeleccionarIdCliente(listaClientes);

        CargarTexto("Ingrese nombre: ", listaMascotas[indiceEncontrado].nombre,20);
        MostrarTipoMascota();
        listaMascotas[indiceEncontrado].tipo=GetInt("Ingrese ID tipo: ",
        "Error, fuera de parametro, reingrese: ", 100, 102);
        CargarDescripcion(listaMascotas[indiceEncontrado].descripcion,
        listaMascotas[indiceEncontrado].tipo);
        CargarTexto("Ingrese raza: ", listaMascotas[indiceEncontrado].raza,20);
        listaMascotas[indiceEncontrado].edad=IngresarEntero("Ingrese edad: ");
        listaMascotas[indiceEncontrado].peso=CargarFlotante("Ingrese peso: ");
        listaMascotas[indiceEncontrado].sexo=GetChar("Ingrese sexo f o m: ",
        "Error, fuera de parametro, reingrese: ", 'f','m');

        respuesta=ConfirmarOperacion();

            if(respuesta=='s')
            {
                listaMascotas[indiceEncontrado].idMascota = GenerateIdMascota();
                printf("\nEl numero de ID es: %d", listaMascotas[indiceEncontrado].idMascota);
                listaMascotas[indiceEncontrado].estado = OCUPADO;
                indiceEncontrado = 1;

            } else {

                indiceEncontrado = 0;
            }

    }

    return indiceEncontrado;
}

int EliminarDuenoEnCascada(eCliente listaClientes[], eMascota listaMascotas[])
{
    int i; // cliente
    int j; // mascotas
    int auxiliarID;
    int valorRetorno=-1;
    char respuesta;

    printf("\nlIngrese ID Cliente: ");
    scanf("%d", &auxiliarID);

    for(i=0;i<SIZE_CLIENTES; i++)
    {
        if(listaClientes[i].estado==OCUPADO && auxiliarID==listaClientes[i].idCliente)
        {
            printf("\nEsta por eliminar el ID %d del cliente %s %s y todas sus mascotas: ",
            listaClientes[i].idCliente, listaClientes[i].nombre, listaClientes[i].apellido);

            respuesta=ConfirmarOperacion();

            if(respuesta=='s'){

                listaClientes[i].estado=LIBRE;

                for(j=0; j<SIZE_MASCOTAS; j++)
                {
                    if(listaMascotas[j].estado==OCUPADO && listaMascotas[j].idCliente==listaClientes[i].idCliente)
                    {

                    listaMascotas[j].estado=LIBRE;

                    }

                }

                valorRetorno=1;

            } else {

                valorRetorno=0;
            }

        }

    }

    return valorRetorno;
}

void MostrarMascotasMayoresATresAnosConSuDueno(eCliente listaClientes[], eMascota listaMascotas[])
{
    int i;//Mascotas
    int j;//dueños

    for(i=0; i<SIZE_MASCOTAS; i++)
    {
        if(listaMascotas[i].estado==OCUPADO)
        {

        for(j=0; j<SIZE_CLIENTES; j++)
        {
            if(listaMascotas[i].estado==OCUPADO && listaMascotas[i].idCliente==listaClientes[j].idCliente)
            {
                if(listaMascotas[i].edad>3)
                {
                    printf("%10s %10d %10s %10s %10d %10.2f %10c %10s %10s\n",
                    listaMascotas[i].nombre,
                    listaMascotas[i].idMascota,
                    listaMascotas[i].descripcion,
                    listaMascotas[i].raza,
                    listaMascotas[i].edad,
                    listaMascotas[i].peso,
                    listaMascotas[i].sexo,
                    listaClientes[j].nombre,
                    listaClientes[j].apellido);
                }
            }

        }

        }

    }

}

void HardcodeoAuxClienteMascota (eAux clienteMascotas[], eCliente listaClientes[])
{
    int i;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        clienteMascotas[i].idCliente=listaClientes[i].idCliente;
        clienteMascotas[i].contadorMascotas=0;
    }

}

void ContadorClienteMascota (eAux clienteMascotas[], eMascota listaMascotas[])
{
    int i;
    int j;

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        for(j=0; j<SIZE_MASCOTAS; j++)
        {
            if(listaMascotas[j].estado==OCUPADO && listaMascotas[j].idCliente==clienteMascotas[i].idCliente)
            {
                clienteMascotas[i].contadorMascotas++;
            }
        }
    }
}

void ClientesConMasDeUnaMascota(eCliente listaClientes[], eMascota listaMascotas[])
{

    eAux clienteMascotas[SIZE_CLIENTES];
    int i;

    HardcodeoAuxClienteMascota(clienteMascotas, listaClientes);

    ContadorClienteMascota(clienteMascotas, listaMascotas);

    for(i=0; i<SIZE_CLIENTES; i++)
    {
        if(clienteMascotas[i].contadorMascotas>1)
        {
            printf("El cliente %s %s tiene %d mascotas\n", listaClientes[i].nombre,
            listaClientes[i].apellido, clienteMascotas[i].contadorMascotas);
        }
    }
}

void OrdenarDuenosPorCantidadesDeMascotas(eCliente listaClientes[], eMascota listaMascotas[])
{
    eAux clienteMascotas[SIZE_CLIENTES];
    eAux auxiliarClienteMascotas;
    eCliente auxiliarCliente;
    int i;
    int j;


    HardcodeoAuxClienteMascota(clienteMascotas, listaClientes);

    ContadorClienteMascota(clienteMascotas, listaMascotas);

    for(i=0; i<SIZE_CLIENTES-1; i++)
    {
        if(listaClientes[i].estado!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<SIZE_CLIENTES; j++)
        {
             if(listaClientes[j].estado!=OCUPADO)
             {
                 continue;
             }
            if(clienteMascotas[i].contadorMascotas > clienteMascotas[j].contadorMascotas)
            {
                auxiliarCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxiliarCliente;

                auxiliarClienteMascotas = clienteMascotas[i];
                clienteMascotas[i] = clienteMascotas[j];
                clienteMascotas[j] = auxiliarClienteMascotas;

            }
        }

    }

}

void OrdenarDuenosPorCantidadesDeMascotasYPorNombre(eCliente listaClientes[], eMascota listaMascotas[])
{
    eAux clienteMascotas[SIZE_CLIENTES];
    eAux auxiliarClienteMascotas;
    eCliente auxiliarCliente;
    int i;
    int j;

    HardcodeoAuxClienteMascota(clienteMascotas, listaClientes);

    ContadorClienteMascota(clienteMascotas, listaMascotas);

    for(i=0; i<SIZE_CLIENTES-1; i++)
    {
        if(listaClientes[i].estado!=OCUPADO)
        {
            continue;
        }
        for(j=i+1; j<SIZE_CLIENTES; j++)
        {
             if(listaClientes[j].estado!=OCUPADO)
             {
                 continue;
             }
            if(clienteMascotas[i].contadorMascotas > clienteMascotas[j].contadorMascotas)
            {
                auxiliarCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxiliarCliente;

                auxiliarClienteMascotas = clienteMascotas[i];
                clienteMascotas[i] = clienteMascotas[j];
                clienteMascotas[j] = auxiliarClienteMascotas;
            }
            if(clienteMascotas[i].contadorMascotas==clienteMascotas[j].contadorMascotas && strcmp(listaClientes[i].nombre,listaClientes[j].nombre)>0)
            {
                auxiliarCliente = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = auxiliarCliente;

                auxiliarClienteMascotas = clienteMascotas[i];
                clienteMascotas[i] = clienteMascotas[j];
                clienteMascotas[j] = auxiliarClienteMascotas;

            }
        }

    }

}

