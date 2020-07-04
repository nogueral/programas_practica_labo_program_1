#include "funciones.h"
#include "clientes.h"
#include "mascotas.h"

typedef struct
{
    int idCliente;
    int contadorMascotas;

} eAux;

/** muestra el menu de opciones
 *  devuelve un numero entero que corresponde con la seleccion del usuario
 * */
int MostrarMenu(void);

/**Muestra listado de mascotas con su dueños
 * recibe array de estructura de tipo eCliente
 * recibe array de estructura de tipo eMascota
 * */
void MostrarMascotasConSuDueno(eCliente[], eMascota[]);

/**Muestra listado de dueños con sus mascotas
 * recibe array de estructura de tipo eCliente
 * recibe array de estructura de tipo eMascota
 * */
void MostrarDuenosConSusMascotas(eCliente[], eMascota[]);

/** Muestra el listado de clientes precargados a los cuales se les puede asignar una mascota
 *  recibe array de estructura de tipo eCliente
 *  devuelve el ID del cliente seleccionado
 * */
int SeleccionarIdCliente(eCliente[]);

/** Realiza la carga de una nueva mascota en el array de estructura
 *  recibe array de estructura de tipo eCliente
 *  recibe array de estructura de tipo eMascota
 *  retorna 1 (carga ok) / 0 (operacion cancelada) / -1 (no hay mas espacio)
 * */
int CargarMascota(eCliente[], eMascota[]);

/** Coloca en estado LIBRE (baja logica) una estructura de tipo eCliente y todas
 *  las mascotas que tiene asignadas (baja en cascada)
 *  recibe array de estructura tipo eCliente
 *  recibe array de estructura tipo eMascota
 *  retorna 1 (ok) / 0 (operacion cancelada) / -1 (ID inexistente)
 * */
int EliminarDuenoEnCascada(eCliente[], eMascota[]);

/** Muestra las mascotas que tienen mas de 3 años con su dueño
 *  recibe array de estructura tipo eCliente
 *  recibe array de estructura tipo eMascota
 * */
void MostrarMascotasMayoresATresAnosConSuDueno(eCliente[], eMascota[]);

/** Realiza el hardcodeo del array de estructura eAux e inicializa el contador
 *  recibe array de estructura tipo eAux
 *  recibe array de estructura tipo eCliente
 * */
void HardcodeoAuxClienteMascota (eAux[], eCliente[]);

/** Ejecuta del array de estructura eAux
 *  recibe array de estructura tipo eAux
 *  recibe array de estructura tipo eMascota
 * */
void ContadorClienteMascota (eAux[], eMascota[]);

/** Muestra los clientes que tienen unas de una mascota
 *  recibe array de estructura tipo eCliente
 *  recibe array de estructura tipo eMascota
 * */
void ClientesConMasDeUnaMascota(eCliente[], eMascota[]);

/** Realiza el ordenamiento de los dueños en funcion de la cantidad de mascotas que poseen
 *  recibe array de estructura tipo eCliente
 *  recibe array de estructura tipo eMascota
 * */
void OrdenarDuenosPorCantidadesDeMascotas(eCliente[], eMascota[]);

/** Realiza el ordenamiento de los dueños en funcion de la cantidad de mascotas que poseen
 *  y su nombre
 *  recibe array de estructura tipo eCliente
 *  recibe array de estructura tipo eMascota
 * */
void OrdenarDuenosPorCantidadesDeMascotasYPorNombre(eCliente[], eMascota[]);
