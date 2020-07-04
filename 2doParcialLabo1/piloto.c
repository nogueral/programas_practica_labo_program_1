#include "piloto.h"

ePiloto* piloto_new()
{
    ePiloto* pPiloto;

    pPiloto = (ePiloto*) malloc (sizeof(ePiloto));

    return pPiloto;
}


int piloto_setID (ePiloto* auxPiloto,int id)
{
    int retorno=0;

    if(auxPiloto!=NULL && id > 0)
    {
        auxPiloto->idPiloto = id;
        retorno = 1;
    }

    return retorno;

}


int piloto_getID (ePiloto* auxPiloto,int* id)
{
    int retorno=0;

    if(auxPiloto!=NULL && id!=NULL)
    {
        *id = auxPiloto->idPiloto;
        retorno = 1;
    }

    return retorno;

}

int piloto_setNombre(ePiloto* auxPiloto, char* nombre)
{
    int retorno=0;

    if(auxPiloto!=NULL && nombre!=NULL)
    {
        strlwr(nombre);
        strcpy(auxPiloto->nombre, nombre);
        retorno=1;
    }

    return retorno;

}

int piloto_getNombre(ePiloto* auxPiloto, char* nombre)
{
    int retorno=0;

    if(auxPiloto!=NULL && nombre!=NULL)
    {
        strcpy(nombre, auxPiloto->nombre);
        retorno=1;
    }

    return retorno;

}

ePiloto* piloto_newParametros(char* id, char* nombre)
{
    ePiloto* pPiloto;

    pPiloto = piloto_new();

    if(pPiloto!=NULL && nombre!= NULL && id>0)
    {
        piloto_setID(pPiloto, atoi(id));
        piloto_setNombre(pPiloto, nombre);
    }

    return pPiloto;
}


int piloto_filtrarPiloto(void* auxPiloto, char* cadena)
{
    int retorno = 0;
    ePiloto* pPiloto;
    char auxNombre[50];

    if(auxPiloto!=NULL && cadena!=NULL)
    {
        pPiloto = (ePiloto*) auxPiloto;
        piloto_getNombre(pPiloto, auxNombre);

        if(strcmp(auxNombre, cadena)==0)
        {
            retorno = 1;
        }
    }

    return retorno;
}


