#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "funciones.h"
#include "piloto.h"
#include "vuelo.h"

int main()
{
    int opcion;
    int len;
    int retorno;
    int cantidadPasajeros;
    LinkedList* listaVuelos;
    LinkedList* listaPilotos;

    listaPilotos = ll_newLinkedList();
    listaVuelos = ll_newLinkedList();

    controller_noguera_loadPilotsFromText("pilotos.csv", listaPilotos);
    len = ll_len(listaPilotos);
    printf("La aerolinea cuenta con %d pilotos", len);

    do{
            opcion = MenuPrincipal();

            switch(opcion)
            {
            case 1:
                retorno = controller_noguera_loadFromText("Vuelos.csv", listaVuelos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");
                    len = ll_len(listaVuelos);
                    printf("\nDatos de vuelos cargados: %d\n", len);

                } else {
                    printf("\nError\n");
                }
                break;

            case 2:
                retorno = controller_noguera_ListarVuelos(listaVuelos, listaPilotos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;

            case 3:
                retorno = controller_noguera_cantidadPasajeros(listaVuelos, &cantidadPasajeros);
                if(retorno==1)
                {
                    printf("\nLa cantidad total de pasajeros es: %d\n", cantidadPasajeros);

                } else {
                    printf("\nError\n");
                }
                break;

            case 4:
                retorno = controller_noguera_cantidadPasajerosIrlanda(listaVuelos, &cantidadPasajeros);
                if(retorno==1)
                {
                    printf("\nLa cantidad de pasajeros a Irlanda: %d\n", cantidadPasajeros);

                } else {
                    printf("\nError\n");
                }
                break;

            case 5:
                retorno = controller_noguera_saveAsTextVuelosCortos("vuelos_cortos.csv", listaVuelos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;

            case 6:
                retorno = controller_noguera_ListDestinoPortugal(listaVuelos, listaPilotos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;

            case 7:
                retorno = controller_noguera_filtrarPiloto(listaVuelos, listaPilotos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;

            case 8:
                retorno = controller_noguera_seleccionarPiloto(listaVuelos, listaPilotos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;

            case 9:
                retorno = controller_noguera_filtrarPilotosPorNombre(listaPilotos);
                if(retorno==1)
                {
                    printf("\nOperacion ok\n");

                } else {
                    printf("\nError\n");
                }
                break;
            }



    system("pause");
    system("cls");

    }while(opcion!=10);

    ll_deleteLinkedList(listaPilotos);
    ll_deleteLinkedList(listaVuelos);

    return 0;
}
