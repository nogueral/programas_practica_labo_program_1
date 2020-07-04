#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "funciones.h"

int main()
{
    LinkedList* listaUsuarios;
    LinkedList* listaMensajes;
    int opcion;
    int retorno;
    int len;

    listaUsuarios = ll_newLinkedList();
    listaMensajes = ll_newLinkedList();

    do{
        opcion = MenuPrincipal();

        switch(opcion)
        {
        case 1:
            retorno = controller_loadUsersFromText("usuarios.csv", listaUsuarios);
            if(retorno==1)
            {
                len = ll_len(listaUsuarios);
                printf("\nCantidad de usuarios: %d", len);

            } else {

                printf("\nError\n");
            }
        break;

        case 2:
            retorno = controller_loadMessageFromText("mensajes.csv", listaMensajes);
            if(retorno==1)
            {
                len = ll_len(listaMensajes);
                printf("\nCantidad de mensajes: %d", len);

            } else {

                printf("\nError\n");
            }
        break;

        case 3:
            retorno = controller_saveAsText("feed.csv", listaMensajes, listaUsuarios);
            if(retorno==1)
            {
                printf("Operacion ok");

            } else {

                printf("\nError\n");
            }
        break;

        case 4:
            retorno = controller_list(listaUsuarios,listaMensajes);
            if(retorno==1)
            {
                printf("Operacion ok");

            } else {

                printf("\nError\n");
            }
            break;
        }

    }while(opcion!=5);

    ll_deleteLinkedList(listaUsuarios);
    ll_deleteLinkedList(listaMensajes);

    return 0;
}
