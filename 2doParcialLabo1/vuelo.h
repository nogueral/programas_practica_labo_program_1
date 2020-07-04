#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef vuelo_H_INCLUDED
#define vuelo_H_INCLUDED
typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[20];
    int cantidadPasajeros;
    int horaDespegue;
    int horaLlegada;

}eVuelo;


/** \brief constructor
 *
 * \return eVuelo*
 *
 */
eVuelo* vuelo_new();

/** \brief setter id vuelo
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setIdVuelo (eVuelo* auxVuelo,int id);

/** \brief getter id vuelo
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getIdVuelo (eVuelo* auxVuelo,int* id);

/** \brief setter id avion
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setIdAvion (eVuelo* auxVuelo,int id);

/** \brief getter id avion
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getIdAvion (eVuelo* auxVuelo,int* id);

/** \brief setter id piloto
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setIdPiloto (eVuelo* auxVuelo,int id);

/** \brief getter id piloto
 *
 * \param eVuelo* auxVuelo
 * \param int id
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getIdPiloto (eVuelo* auxVuelo,int* id);

/** \brief setter fecha
 *
 * \param auxVuelo eVuelo*
 * \param fecha char*
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setFecha(eVuelo* auxVuelo, char* fecha);

/** \brief getter fecha
 *
 * \param auxVuelo eVuelo*
 * \param fecha char*
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getFecha(eVuelo* auxVuelo, char* fecha);

/** \brief setter destino
 *
 * \param auxVuelo eVuelo*
 * \param destino char*
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setDestino(eVuelo* auxVuelo, char* destino);

/** \brief getter destino
 *
 * \param auxVuelo eVuelo*
 * \param destino char*
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getDestino(eVuelo* auxVuelo, char* destino);

/** \brief setter cantidad de pasajeros
 *
 * \param eVuelo* auxVuelo
 * \param int cantidadPasajeros
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_setCantidadPasajeros (eVuelo* auxVuelo,int cantidadPasajeros);

/** \brief getter cantidad de pasajeros
 *
 * \param eVuelo* auxVuelo
 * \param int cantidadPasajeros
 * \return int (1 ok - 0 error).
 *
 */
int vuelo_getCantidadPasajeros (eVuelo* auxVuelo,int* cantidadPasajeros);

/** \brief setter hora despegue
 *
 * \param eVuelo* auxVuelo
 * \param int horaDespegue
 * \return  int (1 ok - 0 error).
 *
 */
int vuelo_setHoraDespegue (eVuelo* auxVuelo,int horaDespegue);

/** \brief getter hora despegue
 *
 * \param eVuelo* auxVuelo
 * \param int horaDespegue
 * \return  int (1 ok - 0 error).
 *
 */
int vuelo_getHoraDespegue (eVuelo* auxVuelo,int* horaDespegue);


/** \brief setter hora llegada
 *
 * \param eVuelo* auxVuelo
 * \param int horaLlegada
 * \return  int (1 ok - 0 error).
 *
 */
int vuelo_setHoraLlegada (eVuelo* auxVuelo,int horaLlegada);

/** \brief getter hora llegada
 *
 * \param eVuelo* auxVuelo
 * \param int horaLlegada
 * \return  int (1 ok - 0 error).
 *
 */
int vuelo_getHoraLlegada (eVuelo* auxVuelo,int* horaLlegada);

/** \brief constructor parametrizado
 *
 * \param idVuelo char*
 * \param idAvion char*
 * \param idPiloto char*
 * \param fecha char*
 * \param destino char*
 * \param cantidadPasajeros char*
 * \param horaDespegue char*
 * \param horaLlegada char*
 * \return eVuelo*
 *
 */
eVuelo* vuelo_newParametros(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantidadPasajeros, char* horaDespegue, char* horaLlegada);

/** \brief parametro determinante para funcion ll_count
 *
 * \param auxVuelo void*
 * \return int cantidad de pasajeros contenido en el elemento
 *
 */
int vuelo_contarPasajeros(void* auxVuelo);

/** \brief verifica si el elemento contiene como destino de vuelo "irlanda"
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 otro destino).
 *
 */
int vuelo_pasajerosIrlanda(void* auxVuelo);

/** \brief verifica si el elemento contiene un vuelo menor a 3hs
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 duracion mayor).
 *
 */
int vuelo_vuelosCortos(void* auxVuelo);

/** \brief verifica si el elemento contiene como destino de vuelo "portugal"
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 otro destino).
 *
 */
int vuelo_pasajerosPortugal(void* auxVuelo);

/** \brief verifica si el elemento contiene al piloto alex lifeson
 *
 * \param auxVuelo void*
 * \return int (1 no lo contiene - 0 si lo contiene).
 *
 */
int vuelo_filtrarPiloto(void* auxVuelo);

/** \brief filtra los elementos que contienen solo al piloto alex lifeson
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 no lo contiene)
 *
 */
int vuelo_filtrarAlexLifeson(void* auxVuelo);

/** \brief filtra los elementos que contienen solo al piloto richard bach
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 no lo contiene)
 *
 */
int vuelo_filtrarRichardBach(void* auxVuelo);

/** \brief filtra los elementos que contienen solo al piloto john kerry
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 no lo contiene)
 *
 */
int vuelo_filtrarJohnKerry(void* auxVuelo);

/** \brief filtra los elementos que contienen solo al piloto erwin rommel
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 no lo contiene)
 *
 */
int vuelo_filtrarErwinRommel(void* auxVuelo);

/** \brief filtra los elementos que contienen solo al pilotostephen coots
 *
 * \param auxVuelo void*
 * \return int (1 ok - 0 no lo contiene)
 *
 */
int vuelo_filtrarStephenCoots(void* auxVuelo);

int vuelo_filtrarMommyWheildon(void* auxVuelo);
int vuelo_filtrarDelNottram(void* auxVuelo);
int vuelo_filtrarEmmottFritchley(void* auxVuelo);
int vuelo_filtrarTrevorKall(void* auxVuelo);
int vuelo_filtrarRossieArnout(void* auxVuelo);
int vuelo_segunDestino(void* auxVuelo, char* cadena);

#endif // vuelo_H_INCLUDED
