
#include "funciones.h"
int MenuPrincipal(void)
{
    int opcion;

    printf("\n/****************************************************");
    printf("\nMenu:");
    printf("\n1. Cargar los datos de los usuarios desde el archivo usuarios.csv (modo texto).");
    printf("\n2. Cargar los datos de los mensajes desde el archivo mensajes.csv (modo texto).");
    printf("\n3. Guardar todos los datos al archivo feed.csv (modo texto).");
    printf("\n4. Imprimir");
    printf("\n5. Salir");
    printf("\n*****************************************************/\n");
    scanf("%d", &opcion);

    return opcion;
}
