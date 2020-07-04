#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados;
    int len;

    listaEmpleados = ll_newLinkedList();
    Employee* pEmpleado;
    Employee* auxEmpleado;
    int retorno;
    /*len = ll_len(listaEmpleados);
    printf("Largo: %d", len);*/

    pEmpleado = employee_newParametros("1","jose","18","3000");
    retorno = ll_add(listaEmpleados, pEmpleado);
    len = ll_len(listaEmpleados);
    printf("Largo: %d\n Retorno: %d\n", len, retorno);
    retorno = ll_add(listaEmpleados, pEmpleado);
    len = ll_len(listaEmpleados);
    printf("Largo: %d\n Retorno: %d\n", len, retorno);
    retorno = ll_add(listaEmpleados, pEmpleado);
    len = ll_len(listaEmpleados);
    printf("Largo: %d\n Retorno: %d\n", len, retorno);
    retorno = ll_add(listaEmpleados, pEmpleado);
    len = ll_len(listaEmpleados);
    printf("Largo: %d\n Retorno: %d\n", len, retorno);

    auxEmpleado = (Employee*) ll_get(listaEmpleados,2);
    if(auxEmpleado=!NULL)
    {
        printf("get ok");

    } else {

        printf("no existe");
    }


    return 0;
}
