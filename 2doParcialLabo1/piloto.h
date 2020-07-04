#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef piloto_H_INCLUDED
#define piloto_H_INCLUDED
typedef struct
{
    int idPiloto;
    char nombre[50];

}ePiloto;

/** \brief contructor
 *
 * \return ePiloto*
 *
 */
ePiloto* piloto_new();

/** \brief setter id piloto
 *
 * \param ePiloto* auxPiloto
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int piloto_setID (ePiloto* auxPiloto,int id);

/** \brief getter id piloto
 *
 * \param ePiloto* auxPiloto
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int piloto_getID (ePiloto* auxPiloto,int* id);

/** \brief setter nombre piloto
 *
 * \param auxPiloto ePiloto*
 * \param nombre char*
 * \return int (1 ok - 0 error).
 *
 */
int piloto_setNombre(ePiloto* auxPiloto, char* nombre);

/** \brief getter nombre piloto
 *
 * \param auxPiloto ePiloto*
 * \param nombre char*
 * \return int (1 ok - 0 error).
 *
 */
int piloto_getNombre(ePiloto* auxPiloto, char* nombre);

/** \brief constructor parametrizado
 *
 * \param id int
 * \param nombre char*
 * \return ePiloto*
 *
 */
ePiloto* piloto_newParametros(char* id, char* nombre);

int piloto_filtrarPiloto(void* auxPiloto, char* cadena);


#endif // piloto_H_INCLUDED
