#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define SIZE_MASCOTAS 20
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    int tipo;
    char descripcion[20];
    char raza[20];
    int edad;
    float peso;
    char sexo;
    int idCliente;
    int idMascota;
    int estado;

}eMascota;

/** Inicializa el array a estado lIBRE
 *  recibe array de estructura a inicializar
 * */
void InicializarMascotas(eMascota[]);

/** Realiza el hardcode del array de estructura
 *  recibe array de estructura a hardcodear
 * */
void HardcodeoMascotas(eMascota[]);

/** Coloca en estado LIBRE (baja logica) una estructura de tipo eMascota
 *  recibe array de estructura tipo eMascota
 *  retorna 1 (ok) / 0 (operacion cancelada) / -1 (ID inexistente)
 * */
int BajaMascota(eMascota[]);

/** Busca un espacio libre en el array de estructura eMascota
 *  recibe array de estructura eMascota
 *  retorna indice encontrado o -1 en caso de no tener mas espacio en el array
 * */
int BuscarLibreMascota(eMascota[]);

/** Genera un ID autoincremental a traves de una variable static
 * devuelve el numero de ID
 * */
int GenerateIdMascota(void);

/** Asigna a la variable int TIPO, la descripcion correspondiente a la especie cargada
 *  recibe cadena de caracteres donde se cargara la descripcion
 *  recibe el tipo seleccionado por el usuario
 * */
void CargarDescripcion (char[], int);

/** Muestra los tipos de mascota disponibles
 * */
void MostrarTipoMascota (void);

/** Modifica una estructura de tipo eMascota
 *  recibe array de estructura tip eMascota
 *  devuelve 1 (ok) / 0 (operacion cancelada) / -1 (ID inexistente)
 * */
int ModificarMascota (eMascota[]);

/** Ordena el array de estructura en funcion de la variable tipo
 *  recibe array de estructura de tipo eMascota
 * */
void OrdenarMascotasPorTipo(eMascota[]);

/** Imprime el array de estructura en funcion de la variable tipo
 *  recibe array de estructura de tipo eMascota
 * */
void MostrarMascotasPorTipo (eMascota[]);

/** Ordena el array de estructura en funcion de la variable nombre
 *  recibe array de estructura de tipo eMascota
 * */
void OrdenarMascotasPorNombre(eMascota[]);

/** calcula la cantidad de mascotas cargadas en el array de estructura
 *  recibe array de estructura tipo eMascota
 *  devuelve cantidad de mascotas cargadas
 * */
int CantidadPosicionesCargadas (eMascota[]);

/** calcula la sumatoria de edades de mascotas cargadas en el array de estructura
 *  recibe array de estructura tipo eMascota
 *  devuelve suma de edades de mascotas cargadas
 * */
int SumarEdadesMascotas(eMascota[]);

/** calcula el promedio de edades de mascotas cargadas en el array de estructura
 *  recibe array de estructura tipo eMascota
 *  devuelve promedio de edades de mascotas cargadas
 * */
float PromedioEdadMascotas (eMascota[]);

/** calcula el promedio de edades por tipo de mascotas cargadas en el array de estructura
 *  recibe array de estructura tipo eMascota
 *  devuelve promedio de edades por tipo de mascotas cargadas
 * */
float PromedioEdadMascotasPorTipo (eMascota[]);
