#include <stdio.h>
#include <stdlib.h>
#include "ClientesMascotas.h"

int main()
{
    eCliente listaClientes[SIZE_CLIENTES];
    eMascota listaMascotas[SIZE_MASCOTAS];
    int opcion;
    int retornoFuncion;
    float promedio;

    InicializarClientes(listaClientes);
    HardcodeoCliente(listaClientes);

    InicializarMascotas(listaMascotas);
    HardcodeoMascotas(listaMascotas);


    do
    {
        opcion=MostrarMenu();

        switch(opcion)
        {
            case 1:
            PrintClientes(listaClientes);
            break;
            case 2:
            MostrarMascotasConSuDueno(listaClientes,listaMascotas);
            break;
            case 3:
            MostrarDuenosConSusMascotas(listaClientes,listaMascotas);
            break;
            case 4:
            retornoFuncion = CargarMascota(listaClientes,listaMascotas);
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
            case 5:
            retornoFuncion = BajaMascota(listaMascotas);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nBaja realizada con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 6:
            retornoFuncion = ModificarMascota(listaMascotas);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nModificado con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 7:
            retornoFuncion = AltaDueno(listaClientes);
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
            case 8:
            retornoFuncion = EliminarDuenoEnCascada(listaClientes,listaMascotas);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nBaja realizada con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 9:
            OrdenarMascotasPorTipo(listaMascotas);
            MostrarMascotasConSuDueno(listaClientes, listaMascotas);
            break;
            case 10:
            retornoFuncion = ModificarDueno(listaClientes);
            switch(retornoFuncion)
            {
                case 1:
                printf("\nModificado con exito\n");
                break;
                case 0:
                printf("\nOperacion cancelada\n");
                break;
                case -1:
                printf("\nID inexistente\n");
                break;
            }
            break;
            case 11:
            ClientesConMasDeUnaMascota(listaClientes,listaMascotas);
            break;
            case 12:
            MostrarMascotasMayoresATresAnosConSuDueno(listaClientes, listaMascotas);
            break;
            case 13:
            MostrarMascotasPorTipo(listaMascotas);
            break;
            case 14:
            OrdenarDuenosPorCantidadesDeMascotas(listaClientes, listaMascotas);
            MostrarDuenosConSusMascotas(listaClientes,listaMascotas);
            break;
            case 15:
            OrdenarMascotasPorNombre(listaMascotas);
            OrdenarDuenosPorCantidadesDeMascotasYPorNombre(listaClientes, listaMascotas);
            MostrarDuenosConSusMascotas(listaClientes,listaMascotas);
            break;
            case 16:
            promedio = PromedioEdadMascotas(listaMascotas);
            printf("El promedio de edad de las mascotas es: %.2f anos\n", promedio);
            break;
            case 17:
            promedio = PromedioEdadMascotasPorTipo(listaMascotas);
            printf("El promedio de edad de este tipo de mascotas es: %.2f anos\n", promedio);
            break;
            case 18:
            PromedioVaronesYMujeres(listaClientes);
            break;
        }

    system("pause");
    system("cls");

    }while(opcion!=19);

    return 0;
}
