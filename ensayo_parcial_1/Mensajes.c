
#include "Mensajes.h"


eMensaje* mensaje_new()
{
    eMensaje* auxMensaje;

    auxMensaje = (eMensaje*)malloc(sizeof(eMensaje));

    return auxMensaje;

}

int mensaje_setMensaje(eMensaje* auxMensaje, char* mensaje)
{
    int retorno=0;

    if(auxMensaje!=NULL && mensaje!=NULL)
    {
        strlwr(mensaje);
        strcpy(auxMensaje->mensaje, mensaje);
        retorno=1;
    }

    return retorno;
}

int mensaje_setPopularidad(eMensaje* auxMensaje, int popularidad)
{
    int retorno=0;

    if(auxMensaje!=NULL && popularidad > 0)
    {
        auxMensaje->popularidad = popularidad;
        retorno = 1;
    }

    return retorno;

}

int mensaje_setIdMensaje(eMensaje* auxMensaje, int id)
{
    int retorno=0;

    if(auxMensaje!=NULL && id > 0)
    {
        auxMensaje->idMensaje = id;
        retorno = 1;
    }

    return retorno;

}

int mensaje_setIdUsuario(eMensaje* auxMensaje, int id)
{
    int retorno=0;

    if(auxMensaje!=NULL && id > 0)
    {
        auxMensaje->idUsuario = id;
        retorno = 1;
    }

    return retorno;

}


eMensaje* mensaje_newParametros(char* idMensajeMsg,char* MensajeMsg,char* popularidadMsg, char* idUsuarioMsg)
{
    eMensaje* auxMensaje;

    auxMensaje = mensaje_new();

    if(auxMensaje!=NULL && idMensajeMsg!=NULL && MensajeMsg!=NULL && popularidadMsg!=NULL && idUsuarioMsg!=NULL)
    {
       mensaje_setIdMensaje(auxMensaje, atoi(idMensajeMsg));
       mensaje_setMensaje(auxMensaje, MensajeMsg);
       mensaje_setPopularidad(auxMensaje, atoi(popularidadMsg));
       mensaje_setIdUsuario(auxMensaje, atoi(idUsuarioMsg));

    }

    return auxMensaje;

}


int mensaje_getMensaje(eMensaje* auxMensaje, char* mensaje)
{
    int retorno=0;

    if(auxMensaje!=NULL)
    {
        strcpy(mensaje, auxMensaje->mensaje);
        retorno=1;
    }

    return retorno;
}

int mensaje_getPopularidad(eMensaje* auxMensaje, int* popularidad)
{
    int retorno=0;

    if(auxMensaje!=NULL)
    {
        *popularidad = auxMensaje->popularidad;
        retorno = 1;
    }

    return retorno;

}

int mensaje_getIdMensaje(eMensaje* auxMensaje, int* id)
{
    int retorno=0;

    if(auxMensaje!=NULL)
    {
        *id = auxMensaje->idMensaje;
        retorno = 1;
    }

    return retorno;

}

int mensaje_getIdUsuario(eMensaje* auxMensaje, int* id)
{
    int retorno=0;

    if(auxMensaje!=NULL)
    {
        *id = auxMensaje->idUsuario;
        retorno = 1;
    }

    return retorno;

}
