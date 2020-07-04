#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief pide al usuario que ingrese un numero mayor a un numero
 *
 * \param el mensaje de soliciud
 * \param el mensaje de validacion
 * \param parametro minimo a ingresar
 * \return el numero que se ingresa
 *
 */
int getInt (char[], char[], int);

/** \brief contador de numeros pares entre 1 y el numero ingresado
 *
 * \param el numero ingresado
 * \return cantidad de pares entre el 1 y el numero ingresado
 *
 */
int contadorPares (int);

/** \brief contador de impares entre 1 y el numero ingresado
 *
 * \param numero ingresado
 * \param
 * \return cantidad de numeros impares entre el 1 y el numero ingresado
 *
 */
int contadorImpares (int);

/** \brief calcula la cant de divisibles entre x el numero ingresado entre 1 y un numero maximo
 *
 * \param numero ingresado
 * \param numero maximo
 * \return cantidad de divisibles entre los parametros preestablecidos
 *
 */
int numeroDivisible (int, int);

/** \brief verifica si el numero es primo o no
 *
 * \param el numero a verificar
 * \return si es primo devuelve 1, caso contrario devuelve 0
 *
 */
int numeroPrimo (int);

/** \brief cuenta la cantidad de nros primos entre el 1 y el numero ingresado, valida con
 *         funcion numeroPrimo
 * \param numero ingresado
 * \return cantidad de primos entre el 1 y el numero ingresado
 *
 */
int contadorPrimos (int);

#endif // FUNCIONES_H_INCLUDED
