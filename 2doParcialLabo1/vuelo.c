#include "vuelo.h"

eVuelo* vuelo_new()
{
    eVuelo* pVuelo;

    pVuelo = (eVuelo*) malloc (sizeof(eVuelo));

    return pVuelo;
}

int vuelo_setIdVuelo (eVuelo* auxVuelo,int id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id > 0)
    {
        auxVuelo->idVuelo = id;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getIdVuelo (eVuelo* auxVuelo,int* id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id!=NULL)
    {
        *id = auxVuelo->idVuelo;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setIdAvion (eVuelo* auxVuelo,int id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id > 0)
    {
        auxVuelo->idAvion = id;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getIdAvion (eVuelo* auxVuelo,int* id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id!=NULL)
    {
        *id = auxVuelo->idAvion;
        retorno = 1;
    }

    return retorno;

}
int vuelo_setIdPiloto (eVuelo* auxVuelo,int id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id > 0)
    {
        auxVuelo->idPiloto = id;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getIdPiloto (eVuelo* auxVuelo,int* id)
{
    int retorno=0;

    if(auxVuelo!=NULL && id!=NULL)
    {
        *id = auxVuelo->idPiloto;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setFecha(eVuelo* auxVuelo, char* fecha)
{
    int retorno=0;

    if(auxVuelo!=NULL && fecha!=NULL)
    {
        strcpy(auxVuelo->fecha, fecha);
        retorno=1;
    }

    return retorno;

}

int vuelo_getFecha(eVuelo* auxVuelo, char* fecha)
{
    int retorno=0;

    if(auxVuelo!=NULL && fecha!=NULL)
    {
        strcpy(fecha, auxVuelo->fecha);
        retorno=1;
    }

    return retorno;

}

int vuelo_setDestino(eVuelo* auxVuelo, char* destino)
{
    int retorno=0;

    if(auxVuelo!=NULL && destino!=NULL)
    {
        strlwr(destino);
        strcpy(auxVuelo->destino, destino);
        retorno=1;
    }

    return retorno;

}

int vuelo_getDestino(eVuelo* auxVuelo, char* destino)
{
    int retorno=0;

    if(auxVuelo!=NULL && destino!=NULL)
    {
        strcpy(destino, auxVuelo->destino);
        retorno=1;
    }

    return retorno;

}

int vuelo_setCantidadPasajeros (eVuelo* auxVuelo,int cantidadPasajeros)
{
    int retorno=0;

    if(auxVuelo!=NULL && cantidadPasajeros > 0)
    {
        auxVuelo->cantidadPasajeros = cantidadPasajeros;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getCantidadPasajeros (eVuelo* auxVuelo,int* cantidadPasajeros)
{
    int retorno=0;

    if(auxVuelo!=NULL && cantidadPasajeros!=NULL)
    {
        *cantidadPasajeros = auxVuelo->cantidadPasajeros;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setHoraDespegue (eVuelo* auxVuelo,int horaDespegue)
{
    int retorno=0;

    if(auxVuelo!=NULL && horaDespegue > 0)
    {
        auxVuelo->horaDespegue = horaDespegue;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getHoraDespegue (eVuelo* auxVuelo,int* horaDespegue)
{
    int retorno=0;

    if(auxVuelo!=NULL && horaDespegue!=NULL)
    {
         *horaDespegue = auxVuelo->horaDespegue;
        retorno = 1;
    }

    return retorno;

}

int vuelo_setHoraLlegada (eVuelo* auxVuelo,int horaLlegada)
{
    int retorno=0;

    if(auxVuelo!=NULL && horaLlegada > 0)
    {
        auxVuelo->horaLlegada = horaLlegada;
        retorno = 1;
    }

    return retorno;

}

int vuelo_getHoraLlegada (eVuelo* auxVuelo,int* horaLlegada)
{
    int retorno=0;

    if(auxVuelo!=NULL && horaLlegada!=NULL)
    {
        *horaLlegada = auxVuelo->horaLlegada;
        retorno = 1;
    }

    return retorno;

}

eVuelo* vuelo_newParametros(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantidadPasajeros, char* horaDespegue, char* horaLlegada)
{
    eVuelo* pVUelo;

    pVUelo = vuelo_new();

    if(pVUelo!=NULL && idVuelo!=NULL && idAvion!=NULL && idPiloto !=NULL && fecha!=NULL && destino!=NULL && cantidadPasajeros!=NULL && horaDespegue!=NULL && horaLlegada!=NULL)
    {
        vuelo_setIdVuelo(pVUelo, atoi(idVuelo));
        vuelo_setIdAvion(pVUelo, atoi(idAvion));
        vuelo_setIdPiloto(pVUelo, atoi(idPiloto));
        vuelo_setFecha(pVUelo, fecha);
        vuelo_setDestino(pVUelo, destino);
        vuelo_setCantidadPasajeros(pVUelo, atoi(cantidadPasajeros));
        vuelo_setHoraDespegue(pVUelo, atoi(horaDespegue));
        vuelo_setHoraLlegada(pVUelo, atoi(horaLlegada));
    }

    return pVUelo;
}

int vuelo_contarPasajeros(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxCantPasajeros;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;

        vuelo_getCantidadPasajeros(pVuelo, &auxCantPasajeros);
        retorno = auxCantPasajeros;
    }

    return retorno;
}

int vuelo_pasajerosIrlanda(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    char auxDestino[20];

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getDestino(pVuelo, auxDestino);

        if(strcmp(auxDestino,"irlanda")==0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_vuelosCortos(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxHoraDespegue;
    int auxHoraLlegada;
    int duracion;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getHoraDespegue(pVuelo, &auxHoraDespegue);
        vuelo_getHoraLlegada(pVuelo, &auxHoraLlegada);
        duracion = auxHoraLlegada-auxHoraDespegue;

        if(duracion<3)
        {
            retorno = 1;
        }

    }

    return retorno;
}

int vuelo_pasajerosPortugal(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    char auxDestino[20];

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getDestino(pVuelo, auxDestino);

        if(strcmp(auxDestino,"portugal")==0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarPiloto(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto!=1)
        {
            retorno = 1;
        }
    }

    return retorno;
}


int vuelo_filtrarAlexLifeson(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==1)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarRichardBach(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==2)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarJohnKerry(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==3)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarErwinRommel(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==4)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarStephenCoots(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==5)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarMommyWheildon(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==6)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarDelNottram(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==7)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarEmmottFritchley(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==8)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarTrevorKall(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==9)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_filtrarRossieArnout(void* auxVuelo)
{
    int retorno = 0;
    eVuelo* pVuelo;
    int auxIdPiloto;

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getIdPiloto(pVuelo, &auxIdPiloto);

        if(auxIdPiloto==10)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int vuelo_segunDestino(void* auxVuelo, char* cadena)
{
    int retorno = 0;
    eVuelo* pVuelo;
    char auxDestino[50];

    if(auxVuelo!=NULL)
    {
        pVuelo = (eVuelo*) auxVuelo;
        vuelo_getDestino(pVuelo, auxDestino);

        if(strcmp(auxDestino, cadena)==0)
        {
            retorno = 1;
        }
    }

    return retorno;
}
