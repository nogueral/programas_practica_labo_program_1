#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void InicializarVector (int[], int, int);
int GetInt (char[], char[], int, int);
int CargarAlumno(int[], char[][20], int[], int[], int[], float[], int, int, int);
int BuscarLibre(int[], int, int);
int ModificarAlumno (int[], char[][20], int[], int[], float[], int[], int, int);
int EliminarAlumno(int[], char[][20], int[], int[], int[], float[], int, int, int);
void OrdenarAlumnosPorNombre(int[], int[], int[], float[], char[][20], int[], int, int);
void MostrarAlumnos(int[], int[], int[], float[], char[][20], int[], int, int);
float CalculoPromedio(int, int);

#endif // FUNCIONES_H_INCLUDED
