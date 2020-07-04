#include <stdio.h>
#include <stdlib.h>

int controller_loadUsersFromText(char* path, LinkedList* listaUsuarios);
int controller_loadMessageFromText(char* path, LinkedList* listaMensajes);
int controller_saveAsText(char* path, LinkedList* listaMensajes, LinkedList* listaUsuarios);
int controller_list(LinkedList* listaUsuarios, LinkedList* listaMensajes);
