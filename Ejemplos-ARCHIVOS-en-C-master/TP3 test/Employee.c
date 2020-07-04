#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
    Employee* auxEmpleado;

    auxEmpleado = (Employee*)malloc(sizeof(Employee));

    return auxEmpleado;

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxEmpleado;

    auxEmpleado = employee_new();

    if(auxEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!= NULL)
    {
       employee_setId(auxEmpleado, atoi(idStr));
       employee_setNombre(auxEmpleado, nombreStr);
       employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadasStr));
       employee_setSueldo(auxEmpleado, atoi(sueldoStr));

    }

    return auxEmpleado;

}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL)
    {
        strlwr(nombre);
        strcpy(this->nombre, nombre);
        retorno=1;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=1;
    }

    return retorno;

}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;


}

int employee_setId(Employee* this,int id)
{
    int retorno=0;

    if(this!=NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }

    return retorno;

}
int employee_getId(Employee* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;


}


int employee_CompareByName(void* empleado1, void* empleado2)
{
    Employee* auxEmpleado1;
    Employee* auxEmpleado2;
    int retorno;

    if(empleado1!=NULL && empleado2!=NULL)
    {
        auxEmpleado1 = (Employee*) empleado1;
        auxEmpleado2 = (Employee*) empleado2;

        retorno=strcmp(auxEmpleado1->nombre, auxEmpleado2->nombre);

    }


    return retorno;
}

int employee_CompareById(void* empleado1, void* empleado2)
{
    Employee* auxEmpleado1;
    Employee* auxEmpleado2;
    int retorno;

    if(empleado1!=NULL && empleado2!=NULL)
    {
        auxEmpleado1 = (Employee*) empleado1;
        auxEmpleado2 = (Employee*) empleado2;

        if(auxEmpleado1->id > auxEmpleado2->id)
        {
            retorno=1;

        }

        if(auxEmpleado1->id < auxEmpleado2->id)
        {
            retorno=-1;
        }

        if(auxEmpleado1->id == auxEmpleado2->id)
        {
            retorno=0;
        }

    }

    return retorno;
}

int employee_CompareByHsTrabajadas(void* empleado1, void* empleado2)
{
    Employee* auxEmpleado1;
    Employee* auxEmpleado2;
    int retorno;

    if(empleado1!=NULL && empleado2!=NULL)
    {
        auxEmpleado1 = (Employee*) empleado1;
        auxEmpleado2 = (Employee*) empleado2;

        if(auxEmpleado1->horasTrabajadas > auxEmpleado2->horasTrabajadas)
        {
            retorno=1;

        }

        if(auxEmpleado1->horasTrabajadas < auxEmpleado2->horasTrabajadas)
        {
            retorno=-1;
        }

        if(auxEmpleado1->horasTrabajadas == auxEmpleado2->horasTrabajadas)
        {
            retorno=0;
        }
    }

    return retorno;
}

int employee_CompareBySueldo(void* empleado1, void* empleado2)
{
    Employee* auxEmpleado1;
    Employee* auxEmpleado2;
    int retorno;

    if(empleado1!=NULL && empleado2!=NULL)
    {
        auxEmpleado1 = (Employee*) empleado1;
        auxEmpleado2 = (Employee*) empleado2;

        if(auxEmpleado1->sueldo > auxEmpleado2->sueldo)
        {
            retorno=1;

        }

        if(auxEmpleado1->sueldo < auxEmpleado2->sueldo)
        {
            retorno=-1;
        }

        if(auxEmpleado1->sueldo == auxEmpleado2->sueldo)
        {
            retorno=0;
        }
    }

    return retorno;
}

