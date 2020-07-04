#ifndef ABONADO_H_INCLUDED
#define ABONADO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE_ABONADO 5
#define SIZE_LLAMADAS 5
#define LIBRE 0
#define OCUPADO 1
#define FALLA_3G 1
#define FALLA_LTE 2
#define FALLA_EQUIPO 3
#define EN_CURSO 11
#define SOLUCIONADO 12
#define NO_SOLUCIONADO 13

typedef struct
{
   int idAbonado;
   long int numero;
   char nombre[20];
   char apellido[20];
   int estado;

}eAbonado;

typedef struct
{
    int idLlamada;
    int idAbonado;
    int motivo;
    int estado;
    int tiempo;
    int isEmpty;

}eLlamada;

void HardcodeoAbonado(eAbonado[]);
void HardcodeoLlamadas(eLlamada[]);
void InicializarAbonados(eAbonado listaAbonados[]);
void InicializarLlamadas(eLlamada listaLlamadas[]);
int MostrarMenu(void);
int BuscarLibre(eAbonado[]);
int GenerateIdAbonado(void);
void CargarTexto (char[], char[]);
long int GetLongInt (char[]);
char ConfirmarOperacion (void);
int CargarAbonado(eAbonado[]);
void MostrarUnAbonado(eAbonado);
void MostrarAbonados(eAbonado[]);
int ModificarAbonado (eAbonado[]);
int EliminarAbonado(eAbonado[]);
int BuscarLibreParaLlamadas(eLlamada[]);
int GenerateIdLlamada(void);
int CargarLlamada(eLlamada[], eAbonado[]);
int FinalizarLlamada(eAbonado[], eLlamada[]);
void MostrarUnLlamado (eLlamada listaLlamadas);
void MostrarLlamados(eLlamada listaLlamadas[]);
void AbonadoConMasReclamos(eAbonado[], eLlamada[]);
void ReclamoMasRealizado(eLlamada listaLlamadas[]);
/** \brief muestra el reclamo que en promedio mas demora en ser resuelto
 *
 * \param recibe como parametro el listado de llamadas
 * \param
 * \return
 *
 */

void ReclamoQueMasDemoraEnSerResuelto(eLlamada listaLlamadas[]);
#endif // ABONADO_H_INCLUDED
