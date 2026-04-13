#include <stdio.h>
#include <stdlib.h>
#include "../Fecha/Fecha.h"
#define DIAS_A_SUMAR 90
int main()
{
    // parte 1
    Fecha fecha;
    // Carga de fecha incial
    ingresarFecha(&fecha);
    printf("Fecha ingresada:\n");
    mostrarFecha(&fecha);
    putchar('\n');

    /*
    // parte 2: suma
    Fecha fSum = fechaSumarDias(&fecha1, DIAS_A_SUMAR);
    printf("Nueva fecha. Se le sumo %d\n", DIAS_A_SUMAR);
    mostrarFecha(&fSum);
    putchar('\n');
    */

    /*
    // parte 3
    Fecha fecha;
    printf("fecha Dia Del Anio:\n");
    printf("%d\n", fechaDiaDelAnio(&fecha));
    */

    /*
    // parte 4
    Fecha fecha1;
    ingresarFecha(&fecha1);
    printf("Fecha ingresada:\n");
    mostrarFecha(&fecha1);
    putchar('\n');

    ingresarFecha(&fecha2);
    printf("Fecha 2 ingresada:\n");
    mostrarFecha(&fecha2);
    putchar('\n');

    printf("La diferencia es de %d dias", fechaDiferencia(&fecha1, &fecha2));
    */



    /*
    // parte 5
    printf("Dado un dia y el anio devolver la fecha\n");
    Fecha fNueva = fechaDiaDelAnioAFecha(60, 2026);
    mostrarFecha(&fNueva);
    */

    char diasSemana[7][10] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    int n = fechaDiaSemana(&fecha);
    printf("El dia de la semana es: %s", diasSemana[n]);
    return 0;
}
