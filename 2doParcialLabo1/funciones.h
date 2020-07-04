#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Menu de opciones
 *
 * \param void
 * \return int seleccion del usuario
 *
 */
int MenuPrincipal(void);

/** \brief solicita un numero entero al usuario
 *
 * \param char* mensaje
 * \param char* error
 * \param int min
 * \param int max
 * \return numero entero, seleccion del usuario
 *
 */
int GetInt (char* mensaje, char* error, int min, int max);
void CargarTexto (char* mensaje, char* texto, int largo);
