
#include "piloto.h"
#include "vuelo.h"
#include "parser.h"
#include "funciones.h"
#include "Linkedlist.h"

int controller_noguera_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo;
    int retorno;

    pArchivo = fopen(path, "r");

    if(pArchivo!=NULL && pArrayList!=NULL)
    {
        parser_vueloFromText(pArchivo, pArrayList);
        retorno = 1;
        fclose(pArchivo);

    } else {


        retorno = 0;
    }

return retorno;
}

int controller_noguera_loadPilotsFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo;
    int retorno;

    pArchivo = fopen(path, "r");

    if(pArchivo!=NULL && pArrayList!=NULL)
    {
        parser_pilotsFromText(pArchivo, pArrayList);
        retorno = 1;
        fclose(pArchivo);

    } else {


        retorno = 0;
    }

return retorno;
}

int controller_noguera_ListarVuelos(LinkedList* listaVuelos, LinkedList* listaPilotos)
{
    int i;
    int j;
    int retorno=0;
    int lenPilotos, lenVuelos;
    eVuelo* auxVuelo;
    ePiloto* auxPiloto;
    int auxIdPiloto;
    int auxIdPiloto2;
    int auxIdVuelo;
    int auxIdAvion;
    char auxNombre[50];
    char auxFecha[50];
    char auxDestino[50];
    int auxCantPasajeros;
    int auxHoraLlegada;
    int auxHoraDespegue;
    int contador=0;


    if(listaPilotos!=NULL && listaVuelos!=NULL)
    {
        lenPilotos = ll_len(listaPilotos);
        lenVuelos = ll_len(listaVuelos);

        for(i=0; i<lenVuelos; i++)
        {
            auxVuelo = ll_get(listaVuelos, i);
            vuelo_getIdPiloto(auxVuelo, &auxIdPiloto);

            for(j=0; j<lenPilotos; j++)
            {
                auxPiloto = ll_get(listaPilotos, j);
                piloto_getID(auxPiloto, &auxIdPiloto2);

                if(auxIdPiloto==auxIdPiloto2)
                {

                    vuelo_getIdVuelo(auxVuelo, &auxIdVuelo);
                    vuelo_getIdAvion(auxVuelo, &auxIdAvion);
                    piloto_getNombre(auxPiloto, auxNombre);
                    vuelo_getFecha(auxVuelo, auxFecha);
                    vuelo_getDestino(auxVuelo, auxDestino);
                    vuelo_getCantidadPasajeros(auxVuelo, &auxCantPasajeros);
                    vuelo_getHoraDespegue(auxVuelo, &auxHoraDespegue);
                    vuelo_getHoraLlegada(auxVuelo, &auxHoraLlegada);


                    printf("%10d %10d %20s %15s %15s %10d %10d %10d\n",
                           auxIdVuelo, auxIdAvion, auxNombre, auxFecha,
                           auxDestino, auxCantPasajeros, auxHoraDespegue,
                           auxHoraLlegada);
                           break;
                }


            }



            contador++;

            if(contador%25==0)
            {
                system("pause");
            }

        }

        retorno=1;
    }

    return retorno;
}

int controller_noguera_cantidadPasajeros(LinkedList* pArrayList, int* acumuladorPasajeros)
{
    int retorno = 0;

    if(pArrayList!=NULL && acumuladorPasajeros!=NULL)
    {
        *acumuladorPasajeros = ll_count(pArrayList, vuelo_contarPasajeros);
        retorno = 1;
    }


    return retorno;
}

int controller_noguera_cantidadPasajerosIrlanda(LinkedList* pArrayList, int* acumuladorPasajeros)
{
    int retorno = 0;
    LinkedList* auxLista;


    if(pArrayList!=NULL && acumuladorPasajeros!=NULL)
    {
        auxLista = ll_newLinkedList();

        if(auxLista!=NULL)
        {
            auxLista = ll_filter(pArrayList, vuelo_pasajerosIrlanda);

            *acumuladorPasajeros = ll_count(auxLista, vuelo_contarPasajeros);
            retorno = 1;
        }
    }


    return retorno;
}

int controller_noguera_saveAsTextVuelosCortos(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    FILE* pArchivo;
    LinkedList* auxLista;

    if(path!=NULL && pArrayList!=NULL)
    {
        auxLista = ll_newLinkedList();
        pArchivo = fopen(path, "w");

        if(auxLista!=NULL && pArchivo!=NULL)
        {
            auxLista = ll_filter(pArrayList, vuelo_vuelosCortos);
            parser_vuelosToText(pArchivo, auxLista);
            fclose(pArchivo);
            retorno = 1;

        }
    }


    return retorno;
}

int controller_noguera_ListDestinoPortugal(LinkedList* pArrayList, LinkedList* pArrayListPilots)
{
    int retorno=0;
    LinkedList* auxLista;

    auxLista = ll_newLinkedList();

    if(pArrayList!=NULL && auxLista!=NULL && pArrayListPilots!=NULL)
    {
       auxLista = ll_filter(pArrayList, vuelo_pasajerosPortugal);
       printf("Cantidad de elementos: %d\n", ll_len(auxLista));
       controller_noguera_ListarVuelos(auxLista, pArrayListPilots);
       retorno = 1;

    }


    return retorno;
}

int controller_noguera_filtrarPiloto(LinkedList* pArrayList, LinkedList* pArrayListPilots)
{
    int retorno=0;
    LinkedList* auxLista;

    auxLista = ll_newLinkedList();

    if(pArrayList!=NULL && auxLista!=NULL && pArrayListPilots!=NULL)
    {
       auxLista = ll_filter(pArrayList, vuelo_filtrarPiloto);
       printf("Cantidad de elementos: %d\n", ll_len(auxLista));
       controller_noguera_ListarVuelos(auxLista, pArrayListPilots);
       retorno = 1;

    }


    return retorno;
}

int controller_noguera_saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    FILE* pArchivo;

    pArchivo = fopen(path, "w");

    if(path!=NULL && pArrayList!=NULL && pArchivo!=NULL)
    {

        parser_vuelosToText(pArchivo, pArrayList);
        fclose(pArchivo);
        retorno = 1;


    }


    return retorno;
}

int controller_noguera_listarPilotos(LinkedList* pArrayList)
{
    int i;
    int auxID;
    char auxNombre[50];
    ePiloto* auxPiloto;
    int retorno=0;

    if(pArrayList!=NULL)
    {
        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxPiloto = ll_get(pArrayList, i);
            piloto_getID(auxPiloto, &auxID);
            piloto_getNombre(auxPiloto, auxNombre);
            printf("ID: %d - Nombre: %s\n", auxID, auxNombre);
            retorno=1;
        }
    }

    return retorno;

}

int controller_noguera_seleccionarPiloto(LinkedList* pArrayList, LinkedList* pArrayListPilots)
{
    int retorno=0;
    LinkedList* auxLista;
    int opcion;

    auxLista = ll_newLinkedList();

    if(pArrayList!=NULL && auxLista!=NULL)
    {
        controller_noguera_listarPilotos(pArrayListPilots);

        opcion = GetInt("Seleccione la opcion deseada: ", "Error, fuera de parametro: ", 1, 10);

        switch(opcion)
        {
            case 1:
            auxLista = ll_filter(pArrayList, vuelo_filtrarAlexLifeson);
            retorno = controller_noguera_saveAsText("AlexLifeson.csv", auxLista);
            break;
            case 2:
            auxLista = ll_filter(pArrayList, vuelo_filtrarRichardBach);
            retorno = controller_noguera_saveAsText("RichardBach.csv", auxLista);
            break;
            case 3:
            auxLista = ll_filter(pArrayList, vuelo_filtrarJohnKerry);
            retorno = controller_noguera_saveAsText("JohnKerry.csv", auxLista);
            break;
            case 4:
            auxLista = ll_filter(pArrayList, vuelo_filtrarErwinRommel);
            retorno = controller_noguera_saveAsText("ErwinRommel.csv", auxLista);
            break;
            case 5:
            auxLista = ll_filter(pArrayList, vuelo_filtrarStephenCoots);
            retorno = controller_noguera_saveAsText("StephenCoots.csv", auxLista);
            break;
            case 6:
            auxLista = ll_filter(pArrayList, vuelo_filtrarMommyWheildon);
            retorno = controller_noguera_saveAsText("MommyWheildon.csv", auxLista);
            break;
            case 7:
            auxLista = ll_filter(pArrayList, vuelo_filtrarDelNottram);
            retorno = controller_noguera_saveAsText("DelNottram.csv", auxLista);
            break;
            case 8:
            auxLista = ll_filter(pArrayList, vuelo_filtrarEmmottFritchley);
            retorno = controller_noguera_saveAsText("EmmottFritchley.csv", auxLista);
            break;
            case 9:
            auxLista = ll_filter(pArrayList, vuelo_filtrarTrevorKall);
            retorno = controller_noguera_saveAsText("TrevorKall.csv", auxLista);
            break;
            case 10:
            auxLista = ll_filter(pArrayList, vuelo_filtrarRossieArnout);
            retorno = controller_noguera_saveAsText("RossieArnout.csv", auxLista);
            break;
        }
    }

    return retorno;
}

int controller_noguera_filtrarPilotosPorNombre(LinkedList* pArrayList)
{
    char cadena[50];
    LinkedList* auxLista;
    int retorno=0;
    int len;

    CargarTexto("Ingrese el nombre del piloto: ", cadena, 50);
    auxLista = ll_newLinkedList();

    if(pArrayList!=NULL && cadena!=NULL && auxLista!=NULL)
    {
        auxLista = ll_filterParametro(pArrayList, piloto_filtrarPiloto, cadena);
        len = ll_len(auxLista);

        if(len==0)
        {
            printf("\nNo existe piloto\n");


        } else {

            printf("Cantidad de elementos cargados: %d\n", len);
            controller_noguera_listarPilotos(auxLista);
        }

        retorno=1;
    }

    return retorno;
}
