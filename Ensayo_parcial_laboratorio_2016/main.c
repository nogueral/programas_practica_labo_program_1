#include <stdio.h>
#include <stdlib.h>
#include "abonado.h"

int main()
{
    eAbonado listaAbonados[SIZE_ABONADO];
    eLlamada listaLlamadas[SIZE_LLAMADAS];

    //InicializarAbonados(listaAbonados);
    //InicializarLlamadas(listaLlamadas);

    HardcodeoAbonado(listaAbonados);
    HardcodeoLlamadas(listaLlamadas);

    int opcion;
    int retornoFuncion;

       do
    {
        opcion=MostrarMenu();

        switch(opcion)
        {
            case 1:
            retornoFuncion = CargarAbonado(listaAbonados);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nCargado con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nNo hay mas espacio\n");
                break;
            }
            break;
            case 2:
            retornoFuncion=ModificarAbonado(listaAbonados);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nModificado con exito\n");
                break;
                case 0:
                printf("\nNo se modificaron los datos, operacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 3:
            retornoFuncion=EliminarAbonado(listaAbonados);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nBaja realizada con exito\n");
                break;
                case 0:
                printf("\nNo se modificaron datos, operacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 4:
            retornoFuncion=CargarLlamada(listaLlamadas, listaAbonados);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nCargado con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nNo hay mas espacio\n");
                break;
                case -2:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 5:
            retornoFuncion=FinalizarLlamada(listaAbonados, listaLlamadas);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nModificado con exito\n");
                break;
                case 0:
                printf("\nNo se modificaron los datos, operacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 6:
            printf("\nSE MUESTRAN ABONADOS: \n");
            MostrarAbonados(listaAbonados);
            printf("\nSE MUESTRAN LLAMADAS: \n");
            printf("Falla 3G (1) Falla LTE (2) Falla equipo (3): \n");
            printf("En curso (11) Solucionado (12) No solucionado (13): \n");
            MostrarLlamados(listaLlamadas);
            printf("\nABONADO CON MAS RECLAMOS: \n");
            AbonadoConMasReclamos(listaAbonados, listaLlamadas);
            printf("\nSE MUESTRA EL RECLAMO MAS REALIZADO: \n");
            ReclamoMasRealizado(listaLlamadas);
            printf("\nSE MUESTRA EL RECLAMO QUE EN PROMEDIO MAS DEMORA EN SER RESUELTO: \n");
            ReclamoQueMasDemoraEnSerResuelto(listaLlamadas);
            break;
        }

    }while(opcion!=7);


    return 0;
}
