
#include "Linkedlist.h"
#include "Usuarios.h"
#include "Mensajes.h"

int controller_loadUsersFromText(char* path, LinkedList* listaUsuarios)
{
    FILE* pArchivo;
    int retorno = 0;
    eUsuario* auxUsuario;
    char idUsuario[50];
    char nick[50];
    char popularidad[50];
    int auxScan;

    pArchivo = fopen(path, "r");

    if(pArchivo!=NULL && listaUsuarios!=NULL)
    {
        auxScan = fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", idUsuario, nick, popularidad);

        do{
            auxScan = fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", idUsuario, nick, popularidad);

            if(auxScan==3)
            {
                auxUsuario = usuario_newParametros(idUsuario, nick, popularidad);
                ll_add(listaUsuarios, auxUsuario);
            }


        }while(!feof(pArchivo));

        fclose(pArchivo);
        retorno = 1;
    }

    return retorno;
}

int controller_loadMessageFromText(char* path, LinkedList* listaMensajes)
{
    FILE* pArchivo;
    int retorno = 0;
    eMensaje* auxMensaje;
    char idUsuario[50];
    char idMensaje[50];
    char mensaje[2000];
    char popularidad[50];
    int auxScan;

    pArchivo = fopen(path, "r");

    if(pArchivo!=NULL && listaMensajes!=NULL)
    {
        auxScan = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idMensaje, idUsuario, popularidad, mensaje);
        printf("cant datos: %d", auxScan);

        do{

            auxScan = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idMensaje, idUsuario, popularidad, mensaje);

            if(auxScan==4)
            {
                auxMensaje = mensaje_newParametros(idMensaje, mensaje, popularidad, idUsuario);
                ll_add(listaMensajes, auxMensaje);
            }

        } while (!feof(pArchivo));


        fclose(pArchivo);
        retorno = 1;
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* listaMensajes, LinkedList* listaUsuarios)
{
    int i;
    int j;
    int len, lenUsr;
    eMensaje* auxMensaje;
    eUsuario* auxUsuario;
    int auxIdMensaje;
    int auxPopMensaje;
    char auxMsg[2000];
    int auxIdUsuario;
    int auxPopUsuario;
    char auxNick[50];
    FILE* pArchivo;
    int retorno = 0;

    pArchivo = fopen(path, "w");
    len = ll_len(listaMensajes);
    lenUsr = ll_len(listaUsuarios);

    if(listaMensajes!=NULL && listaUsuarios!=NULL && pArchivo!=NULL)
    {
        fprintf(pArchivo, "id_mensaje, popularidad_mensaje, idUsuario, nick, popularidad_usuario, mensaje\n");

    for(i=0; i<len; i++)
    {
        auxMensaje = ll_get(listaMensajes, i);

        for(j=0; j<lenUsr; j++)
        {
            auxUsuario = ll_get(listaUsuarios, j);

            if(auxMensaje->idUsuario==auxUsuario->idUsuario)
            {
                mensaje_getIdMensaje(auxMensaje, &auxIdMensaje);
                mensaje_getMensaje(auxMensaje, auxMsg);
                mensaje_getPopularidad(auxMensaje, &auxPopMensaje);
                usuario_getID(auxUsuario, &auxIdUsuario);
                usuario_getNick(auxUsuario, auxNick);
                usuario_getPopularidad(auxUsuario, &auxPopUsuario);

                 fprintf(pArchivo, "%d, %d, %d, %s, %d, %s\n", auxIdMensaje, auxPopMensaje, auxIdUsuario, auxNick, auxPopUsuario, auxMsg);

                break;
            }


        }
    }


       fclose(pArchivo);
       retorno = 1;
    }


    return retorno;

}

int controller_list(LinkedList* listaUsuarios, LinkedList* listaMensajes)
{
    int i;
    int j;
    int lenUsuarios;
    int lenMensajes;
    eUsuario* auxUsuario;
    eMensaje* auxMensaje;
    int retorno= 0;

    if(listaUsuarios!=NULL && listaMensajes!=NULL)
    {
        lenMensajes = ll_len(listaMensajes);
        lenUsuarios = ll_len(listaUsuarios);

        printf("id_mensaje, mensaje, popularidad_mensaje, idUsuario, nick, popularidad_usuario\n");

        for(i=0; i<lenMensajes; i++)
        {
            auxMensaje = ll_get(listaMensajes, i);

            for(j=0; j<lenUsuarios; j++)
            {
                auxUsuario = ll_get(listaUsuarios, j);

                if(auxMensaje->idUsuario==auxUsuario->idUsuario)
                {
                    printf("%d -- %s -- %d -- %d -- %s -- %d\n", auxMensaje->idMensaje, auxMensaje->mensaje,
                           auxMensaje->popularidad, auxUsuario->idUsuario, auxUsuario->nick, auxUsuario->popularidad);

                    break;
                }
            }
        }

        retorno = 1;
    }


    return retorno;
}

