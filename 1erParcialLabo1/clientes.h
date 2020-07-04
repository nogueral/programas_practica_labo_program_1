#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define SIZE_CLIENTES 10
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    char apellido[20];
    char localidad[20];
    long int telefono;
    int edad;
    char sexo;
    int idCliente;
    int estado;

}eCliente;

/** Inicializa el array a estado lIBRE
 *  recibe array de estructura a inicializar
 * */
void InicializarClientes(eCliente[]);

/** Realiza el hardcode del array de estructura
 *  recibe array de estructura a hardcodear
 * */
void HardcodeoCliente(eCliente[]);

/** muestra los datos cargados en una estructura
 *  recibe la estructura en cuestion
 * */
void MostrarUnCliente (eCliente);

/** imprime los datos de un array de estructura en estado OCUPADO
 *  recibe el array de estructura a imprimir
 * */
void PrintClientes (eCliente[]);

/** Busca un espacio libre en el array de estructura eCliente
 *  recibe array de estructura eCliente
 *  retorna indice encontrado o -1 en caso de no tener mas espacio en el array
 * */
int BuscarLibreClientes(eCliente[]);

/** Genera un ID autoincremental a traves de una variable static
 * devuelve el numero de ID
 * */
int GenerateIdCliente(void);

/** Realiza la carga de un nuevo cliente en el array de estructura
 *  recibe array de estructura
 *  retorna 1 (carga ok) / 0 (operacion cancelada) / -1 (no hay mas espacio)
 * */
int AltaDueno(eCliente[]);

/** Realiza la modificacion cliente en el array de estructura
 *  recibe array de estructura
 *  retorna 1 (modificacion ok) / 0 (operacion cancelada) / -1 (ID inexistente)
 * */
int ModificarDueno (eCliente[]);

/** Realiza el conteo de las posiciones cargadas en el array de estructura tipo eCliente
 *  recibe array de estructura eCliente
 *  devuelve cantidad de posiciones cargadas
 * */
int CantidadClientesCargados (eCliente listaClientes[]);

/** Calcula y muestra el promedio de varones y mujeres en funcion de la cantidad de clientes cargados
 *  recibe array de estructura de tipo eCliente
 * */
void PromedioVaronesYMujeres (eCliente listaClientes[]);
