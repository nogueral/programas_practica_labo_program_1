#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idMensaje;
    char mensaje[2000];
    int popularidad;
    int idUsuario;

}eMensaje;

typedef struct
{
    int idMensaje;
    char mensaje[2000];
    int popularidadMsj;
    int idUsuario;
    char nick[50];
    int popularidadUsr;

}eAux;

eMensaje* mensaje_new();

int mensaje_setMensaje(eMensaje* auxMensaje, char* mensaje);
int mensaje_setPopularidad(eMensaje* auxMensaje, int popularidad);
int mensaje_setIdMensaje(eMensaje* auxMensaje, int id);
int mensaje_setIdUsuario(eMensaje* auxMensaje, int id);
eMensaje* mensaje_newParametros(char* idMensajeMsg,char* MensajeMsg,char* popularidadMsg, char* idUsuarioMsg);
int mensaje_getMensaje(eMensaje* auxMensaje, char* mensaje);
int mensaje_getPopularidad(eMensaje* auxMensaje, int* popularidad);
int mensaje_getIdMensaje(eMensaje* auxMensaje, int* id);
int mensaje_getIdUsuario(eMensaje* auxMensaje, int* id);

