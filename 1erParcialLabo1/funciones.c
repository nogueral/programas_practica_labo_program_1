#include "funciones.h"

void ToLower (char palabra [], int tam)
{
    int i;

        for(i=0; i<tam; i++) {
        palabra[i]=tolower(palabra[i]);
    }
}

void CargarTexto (char mensaje[], char texto[], int largo)
{
    printf("%s", mensaje);
    fflush(stdin);
    fgets(texto, largo, stdin);
    ToLower(texto,largo);
    texto[strlen(texto)-1]='\0';
}

int IngresarEntero (char mensaje[])
{
    int num;

        printf("%s",mensaje);
        scanf("%d", &num);

    return num;
}

char GetChar (char mensaje[], char error[], char a, char b)
{
    char opcion;

        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);

        while (opcion != a && opcion != b) {

            printf("%s",error);
            fflush(stdin);
            scanf("%c", &opcion);
            opcion=tolower(opcion);
        }

    return opcion;
}

char ConfirmarOperacion (void)
{
    char respuesta;

    do{  printf("\n Desea continuar? s/n: ");
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta=tolower(respuesta);
    }while(respuesta!='s' && respuesta!='n');

    return respuesta;
}

int GetInt (char mensaje[], char error[], int min, int max)
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

long int GetLongInt (char mensaje[])
{
    long int num;

        printf("%s",mensaje);
        scanf("%ld", &num);

    return num;
}

float CargarFlotante (char mensaje[])
{
    float num;

        printf("%s",mensaje);
        scanf("%f", &num);

    return num;
}
