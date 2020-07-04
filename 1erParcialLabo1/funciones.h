#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** Convierte cadena de caracteres a miniscula
 * Ingresa cadena
 * Ingresa largo de la cadena
**/
void ToLower (char[], int);

/** Realiza la carga de texto en una cadena de caracteres
 *  recibe variable de tipo char[] donde se realizara la carga
 *  recibe el mensaje de solicitud de ingreso al usuario
 *  recibe el largo de la cadena de caracteres
 * */
void CargarTexto (char[], char[], int);

/** Realiza la carga de un numero en una variable de tipo int
 *  recibe el mensaje de solicitud de ingreso al usuario
 *  devuelve una numero de tipo entero
 * */
int IngresarEntero (char[]);

/** Realiza la carga y validacion de una variable de tipo char
 *  recibe el mensaje de solicitud de ingreso al usuario
 *  recibe el mensaje de error en la variable ingresada por el usuario
 *  recibe el primer parametro de validacion
 *  recibe el segundo parametro de validacion
 *  devuelve variable de tipo char validada
 * */
char GetChar (char[], char[], char, char);

/** Imprime el mensaje "Desea continuar? s/n y solicita el ingreso de una opcion al usuario"
 *  devuelve la opcion del usuario
 * */
char ConfirmarOperacion (void);

/** Realiza la carga y validacion de una variable de tipo int
 *  recibe el mensaje de solicitud de ingreso al usuario
 *  recibe el mensaje de error en la variable ingresada por el usuario
 *  recibe el primer parametro de validacion
 *  recibe el segundo parametro de validacion
 *  devuelve variable de tipo int validada
 * */
int GetInt (char[], char[], int, int);

/** Permite ingresar una variable de tipo long int
 *  recibe el mensaje de solicitud de Carga
 *  devuelve variable de tipo long int
 * */
long int GetLongInt (char[]);

/** Permite ingresar una variable de tipo float
 *  recibe el mensaje de solicitud de Carga
 *  devuelve variable de tipo float
 * */
float CargarFlotante (char[]);
