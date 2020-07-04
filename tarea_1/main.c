#include <stdio.h>
#include <stdlib.h>

/*
Crear una funcion (que recibe void).
Dicha funcion creara una estructura del tipo Alumno
(legajo, division(un solo caracter) y nota).
Hardcodear datos en la funcion y retornar un puntero a dicha variable.
Mostrar en el main dos veces dicho alumno.
*/
typedef struct
{
    int legajo;
    char division;
    int nota;

}eAlumno;

eAlumno* CrearEstructura (); // constructor por defecto
eAlumno* CrearEstructuraConParametros (int, char, int); // constructor parametrizado
void MostrarEstructura (eAlumno*);

int main()
{
    eAlumno* pAlumno;

    pAlumno = CrearEstructuraConParametros(100,'b',8);

    if(pAlumno!=NULL)
    {
        MostrarEstructura(pAlumno);
        MostrarEstructura(pAlumno);
    }

    return 0;
}

eAlumno* CrearEstructura () // constructor por defecto
{
    eAlumno* pAlumno;

    pAlumno = (eAlumno*) malloc (sizeof(eAlumno));

    return pAlumno;
}

eAlumno* CrearEstructuraConParametros (int legajo, char division, int nota) // constructor parametrizado
{
    eAlumno* pAlumno;

    pAlumno = CrearEstructura();

    if(pAlumno!=NULL)
    {
        pAlumno->legajo=legajo;
        pAlumno->division=division;
        pAlumno->nota=nota;
    }

    return pAlumno;
}

void MostrarEstructura (eAlumno* pAlumno)
{
    printf("\n%d -- %c -- %d",
    pAlumno->legajo,
    pAlumno->division,
    pAlumno->nota);
}
