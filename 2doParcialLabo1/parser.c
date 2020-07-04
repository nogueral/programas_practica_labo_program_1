
#include "parser.h"

int parser_vueloFromText(FILE* pFile, LinkedList* pArrayList)
{
    char idVuelo[50];
    char idPiloto[50];
    char idAvion[50];
    char fecha[50];
    char destino[50];
    char cantidadPasajeros[50];
    char horaDespegue[50];
    char horaLlegada[50];
    int auxScan;
    eVuelo* auxVuelo;
    int retorno=0;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        auxScan=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantidadPasajeros, horaDespegue, horaLlegada);

        do{

            auxScan=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantidadPasajeros, horaDespegue, horaLlegada);

            if(auxScan==8)
            {
              auxVuelo = vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantidadPasajeros,horaDespegue,horaLlegada);
              ll_add(pArrayList, auxVuelo);
            }

        }while(!feof(pFile));

        retorno=1;
    }


    return retorno;

}

int parser_pilotsFromText(FILE* pFile, LinkedList* pArrayList)
{
    char idPiloto[50];
    char nombre[50];
    int auxScan;
    ePiloto* auxPiloto;
    int retorno=0;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        auxScan=fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre);

        do{

            auxScan=fscanf(pFile, "%[^,],%[^\n]\n", idPiloto, nombre);

            if(auxScan==2)
            {
              auxPiloto = piloto_newParametros(idPiloto, nombre);
              ll_add(pArrayList, auxPiloto);

            }

        }while(!feof(pFile));

        retorno=1;
    }


    return retorno;

}

int parser_vuelosToText(FILE* pFile, LinkedList* pArrayList)
{
    int retorno = 0;
    int i;
    int auxIdVuelo;
    int auxIdPiloto;
    int auxIdAvion;
    char auxFecha[50];
    char auxDestino[50];
    int auxHoraSalida;
    int auxHoraLlegada;
    int auxCantPasajeros;
    eVuelo* auxVuelo;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        fprintf(pFile, "id_vuelo, id_avion, id_piloto, fecha, destino, cant_pasajeros, hora_salida, hora_llegada\n");

        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxVuelo = ll_get(pArrayList, i);
            vuelo_getIdVuelo(auxVuelo, &auxIdVuelo);
            vuelo_getIdPiloto(auxVuelo, &auxIdPiloto);
            vuelo_getIdAvion(auxVuelo, &auxIdAvion);
            vuelo_getFecha(auxVuelo, auxFecha);
            vuelo_getDestino(auxVuelo, auxDestino);
            vuelo_getCantidadPasajeros(auxVuelo, &auxCantPasajeros);
            vuelo_getHoraDespegue(auxVuelo, &auxHoraSalida);
            vuelo_getHoraLlegada(auxVuelo, &auxHoraLlegada);

            fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", auxIdVuelo, auxIdAvion, auxIdPiloto, auxFecha, auxDestino, auxCantPasajeros, auxHoraSalida, auxHoraLlegada);

        }

        printf("\nCantidad de archivos copiados: %d", ll_len(pArrayList));
        retorno = 1;
    }

    return retorno;
}
