#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Inicializa el vector
 *
 * \param [] int se ingresa el vector
 * \param int se ingresa el tamaño del vector
 * \return void
 *
 */
void inicializarNumeros(int [], int);

/** \brief Ingresa un vector de forma secuencial
 *
 * \param char[] mensaje de solicitud de ingreso
 * \param int[] se ingresa el vector
 * \param int se ingresa el tamaño del vector
 * \return void
 *
 */
void getInt(char[], int[], int);

/** \brief realiza la sumatoria de vectores
 *
 * \param se ingresa el vector
 * \param se ingresa el tamaño
 * \return devuelve el resultado de la sumatoria
 *
 */
int sumarVectores (int[], int);

/** \brief imprime el vector de forma creciente
 *
 * \param se ingresa el vector
 * \param se ingresa el tamaño
 * \return devuelve la impresion del vector de forma creciente
 *
 */
void ImprimirCreciente (int[], int);

/** \brief imprime el vector de forma decreciente
 *
 * \param se ingresa el vector
 * \param se ingresa el tamaño del vector
 * \return devuelve la immpresion de forma decreciente
 *
 */
void imprimirDecreciente (int[], int);

/** \brief calcula el maximo valor dentro del vector
 *
 * \param se ingresa el vector
 * \param se ingresa el tamaño del vector
 * \return devuelve el numero maximo existente dentro del vector en cuestion
 *
 */
int calculoMaximo (int [], int);

/** \brief calcula el minimo valor dentro del vector
 *
 * \param se ingresa el vector
 * \param se ingresa el tamaño
 * \return devuelve el numero minimo existente dentro del vector en cuestion
 *
 */
int calculoMinimo (int [], int);

/** \brief calcula cantidad de pares dentro del vector
 *
 * \param ingreso del vector
 * \param ingreso del tamaño del vector
 * \return devuelve cantidad de numeros pares existentes dentro del vector
 *
 */
int calculoPares (int [], int);

/** \brief calcula la cantidad de impares dentro del vector
 *
 * \param ingreso del vector
 * \param ingreso del tamaño del vector
 * \return devuelve la cantidad de numeros impares existentes dentro del vector
 *
 */
int calculoImpares (int [], int);

/** \brief calcula promedio de los numeros existentes dentro del vector
 *
 * \param ingreso del vector
 * \param ingreso del tamaño del vector
 * \return devuelve el promedio
 *
 */
float calculoPromedio (int [], int);

#endif // FUNCIONES_H_INCLUDED
