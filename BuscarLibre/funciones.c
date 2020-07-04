#include <stdio.h>
#include <stdlib.h>

void InicializarVector(int vector[], int tam)
{
       int i;

    for(i=0; i<tam; i++) {
        vector[i] = 0;
        printf("%d", vector[i]);
    }
}

void CargarNumero (int vector[], int tam)
{
    int encontro;

    encontro = BuscarLibre (vector, tam, 0);

    if(encontro!=-1) {
        printf("\nIngrese numero: ");
        scanf("%d", &vector[encontro]);

    } else {
        printf("\nEspacio agotado");
        }
}


int BuscarLibre (int vector[], int tam, int valor)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++){

        if(vector[i]==valor) {
            indice = i;
            break;
        }
    }

    return indice;
}

