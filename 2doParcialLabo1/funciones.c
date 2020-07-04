
#include "funciones.h"

int MenuPrincipal(void)
{
    int opcion;

    printf("\n/****************************************************");
    printf("\nMenu:");
    printf("\n1. Cargar archivos");
    printf("\n2. Imprimir vuelos");
    printf("\n3. Cantidad de pasajeros");
    printf("\n4. Cantidad de pasajeros a Irlanda");
    printf("\n5. Filtrar vuelos cortos");
    printf("\n6. Listar vuelos a portugal");
    printf("\n7. Filtrar a Alex Lifeson");
    printf("\n8. Generar un archivo de vuelos por nombre de piloto");
    printf("\n9. Filtrar lista de pilotos por nombre");
    printf("\n10. Salir");
    printf("\n*****************************************************/\n");
    scanf("%d", &opcion);

    return opcion;
}

int GetInt (char* mensaje, char* error, int min, int max)
{

    int num;

        printf("%s",mensaje);
        scanf("%d", &num);

        while (num < min || num > max) {

            printf("%s",error);
            scanf("%d", &num);
        }


    return num;
}

void CargarTexto (char* mensaje, char* texto, int largo)
{
    printf("%s", mensaje);
    fflush(stdin);
    fgets(texto, largo, stdin);
    texto[strlen(texto)-1]='\0';
    strlwr(texto);
}
