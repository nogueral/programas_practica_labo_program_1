#include <stdio.h>
#include <stdlib.h>

/** \brief Carga datos al programa desde un archivo en formato texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_loadFromText(char* path, LinkedList* pArrayList);

int controller_noguera_loadPilotsFromText(char* path, LinkedList* pArrayList);


/** \brief Muestra listado de pilotos con nombre en lugar de id.
 *
 * \param listaVuelos LinkedList*
 * \param listaPilotos LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_ListarVuelos(LinkedList* listaVuelos, LinkedList* listaPilotos);

/** \brief Muestra la cantidad total de pasajeros en una lista
 *
 * \param pArrayList LinkedList*
 * \param acumuladorPasajeros int*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_cantidadPasajeros(LinkedList* pArrayList, int* acumuladorPasajeros);


/** \brief Muestra la cantidad total de pasajeros a Irlanda en una lista
 *
 * \param pArrayList LinkedList*
 * \param acumuladorPasajeros int*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_cantidadPasajerosIrlanda(LinkedList* pArrayList, int* acumuladorPasajeros);


/** \brief genera un archivo nuevo con vuelos de menos de 3hs
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_saveAsTextVuelosCortos(char* path, LinkedList* pArrayList);

/** \brief genera un listado solo de vuelos a portugal
 *
 * \param pArrayList LinkedList*
 * \param pArrayListPilots LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_ListDestinoPortugal(LinkedList* pArrayList, LinkedList* pArrayListPilots);

/** \brief genera un listado excluyendo al piloto alex lifeson
 *
 * \param pArrayList LinkedList*
 * \param pArrayListPilots LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_filtrarPiloto(LinkedList* pArrayList, LinkedList* pArrayListPilots);

/** \brief guarda datos en archivo
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_saveAsText(char* path, LinkedList* pArrayList);

/** \brief muestra una lista con todos los pilotos disponibles
 *
 * \param pArrayList LinkedList*
 * \param
 * \return int (1 ok - 0 error).
 *
 */

int controller_noguera_listarPilotos(LinkedList* pArrayList);


/** \brief genera un nuevo archivo filtrando por pilotos
 *
 * \param pArrayList LinkedList*
 * \param pArrayListPilots LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int controller_noguera_seleccionarPiloto(LinkedList* pArrayList, LinkedList* pArrayListPilots);
int controller_noguera_filtrarPilotosPorNombre(LinkedList* pArrayList);

