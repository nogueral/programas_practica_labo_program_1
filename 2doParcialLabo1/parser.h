#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "vuelo.h"
#include "piloto.h"

/** \brief copia datos desde un archivo en formato texto a una lista
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int parser_vueloFromText(FILE* pFile, LinkedList* pArrayList);

int parser_pilotsFromText(FILE* pFile, LinkedList* pArrayList);

/** \brief copia datos desde una lista a un archivo en formato texto
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int (1 ok - 0 error).
 *
 */
int parser_vuelosToText(FILE* pFile, LinkedList* pArrayList);
