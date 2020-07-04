#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idUsuario;
    char nick[50];
    int popularidad;

} eUsuario;

eUsuario* usuario_new();
int usuario_setNick(eUsuario* auxUsuario, char* nick);
int usuario_setPopularidad(eUsuario* auxUsuario, int popularidad);
int usuario_setID(eUsuario* pUsuario, int id);
eUsuario* usuario_newParametros(char* idUsr,char* nickUsr,char* popularidadUsr);
int usuario_getNick(eUsuario* auxUsuario, char* nick);
int usuario_getPopularidad(eUsuario* auxUsuario, int* popularidad);
int usuario_getID(eUsuario* pUsuario, int* id);
