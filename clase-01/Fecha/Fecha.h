#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

// primitivas
bool fechaSet(Fecha* f, int dia, int mes, int anio);
void fechaGet(const Fecha* f, int * dia, int * mes, int* anio);
Fecha fechaSumarDias(const Fecha* f, int dias);
// de tarea
int fechaDiferencia(const Fecha* f1, const Fecha* f2);
int fechaDiaSemana(const Fecha* f);
int fechaDiaDelAnio(const Fecha* f);
Fecha fechaDiaDelAnioAFecha(int diadelanio, int anio);
// no primitivas
void ingresarFecha(Fecha* f);
void mostrarFecha(const Fecha* f);
bool esFechaValida(int dia, int mes, int anio);
#endif // FECHA_H_INCLUDED
