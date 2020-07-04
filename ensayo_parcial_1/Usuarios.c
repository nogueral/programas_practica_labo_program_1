
#include "Usuarios.h"


eUsuario* usuario_new()
{
    eUsuario* auxUsuario;

    auxUsuario = (eUsuario*)malloc(sizeof(eUsuario));

    return auxUsuario;

}

int usuario_setNick(eUsuario* auxUsuario, char* nick)
{
    int retorno=0;

    if(auxUsuario!=NULL && nick!=NULL)
    {
        strlwr(nick);
        strcpy(auxUsuario->nick, nick);
        retorno=1;
    }

    return retorno;
}

int usuario_setPopularidad(eUsuario* auxUsuario, int popularidad)
{
    int retorno=0;

    if(auxUsuario!=NULL && popularidad > 0)
    {
        auxUsuario->popularidad = popularidad;
        retorno = 1;
    }

    return retorno;

}

int usuario_setID(eUsuario* pUsuario, int id)
{
    int retorno=0;

    if(pUsuario!=NULL && id > 0)
    {
        pUsuario->idUsuario = id;
        retorno = 1;
    }

    return retorno;

}

eUsuario* usuario_newParametros(char* idUsr,char* nickUsr,char* popularidadUsr)
{
    eUsuario* auxUsuario;

    auxUsuario = usuario_new();

    if(auxUsuario!=NULL && idUsr!=NULL && nickUsr!=NULL && popularidadUsr!=NULL)
    {
       usuario_setID(auxUsuario, atoi(idUsr));
       usuario_setNick(auxUsuario, nickUsr);
       usuario_setPopularidad(auxUsuario, atoi(popularidadUsr));

    }

    return auxUsuario;

}


int usuario_getNick(eUsuario* auxUsuario, char* nick)
{
    int retorno=0;

    if(auxUsuario!=NULL)
    {
        strcpy(nick, auxUsuario->nick);
        retorno=1;
    }

    return retorno;
}

int usuario_getPopularidad(eUsuario* auxUsuario, int* popularidad)
{
    int retorno=0;

    if(auxUsuario!=NULL)
    {
        *popularidad = auxUsuario->popularidad;
        retorno = 1;
    }

    return retorno;

}

int usuario_getID(eUsuario* pUsuario, int* id)
{
    int retorno=0;

    if(pUsuario!=NULL)
    {
        *id = pUsuario->idUsuario;
        retorno = 1;
    }

    return retorno;

}
