#include <stdio.h>
#include "Fecha.h"
#include <stdbool.h>

int cantDiasMes(int mes, int anio);
bool esBisesto(int anio);
int cantDiasDesde1601(const Fecha* f);

//Primitivas
bool fechaSet(Fecha* f, int dia, int mes, int anio)
{
     if(!esFechaValida(dia, mes, anio))
     {
         return false;
     }
     f->dia = dia;
     f->mes = mes;
     f->anio = anio;

     return true;
}

void fechaGet(const Fecha* f, int * dia, int * mes, int* anio)
{
     *dia = f->dia;
     *mes = f->mes;
     *anio = f->anio;
}

Fecha fechaSumarDias(const Fecha* f, int dias)
{
     Fecha fSuma = *f;
     fSuma.dia += dias;
     int cdm;

     while(fSuma.dia > (cdm = cantDiasMes(fSuma.mes, fSuma.anio)))
     {
         fSuma.dia -= cdm;
         fSuma.mes++;

         if(fSuma.mes > 12)
         {
             fSuma.mes = 1;
             fSuma.anio++;
         }
     }
     return fSuma;
}

int fechaDiaDelAnio(const Fecha* f)
{
    /* Copia por valor, creo una variable local con los mismos datos
    que la original, para trabajar sin modificar f
    */
    Fecha fCont = *f;
    int cdm = 0, i;

    for(i = 0;i < fCont.mes; i++)
    {
        cdm += cantDiasMes(i, fCont.anio);
    }

    cdm += fCont.dia;

    return cdm;
}

Fecha fechaDiaDelAnioAFecha(int diadelanio, int anio)
{
     //Estructura que creamos de datos
     Fecha fAux;
     int cdm, mes = 1;
     while(diadelanio > (cdm = cantDiasMes(mes, anio)))
     {
         diadelanio -= cdm;
         mes ++;
     }
     fAux.dia = diadelanio;
     fAux.mes = mes;
     fAux.anio = anio;
     return fAux;
}

// No primitivas
void ingresarFecha(Fecha* f)
{
     int dia, mes, anio;
     puts("Ingrese una fecha (D/M/A):");
     scanf("%d/%d/%d", &dia, &mes, &anio);
     while(!fechaSet(f, dia, mes, anio))
     {
         puts("Fecha invalida. Ingresala de nuevo (D/M/A):");
         scanf("%d/%d/%d", &dia, &mes, &anio);
     }
}

void mostrarFecha(const Fecha* f)
{
     int dia, mes, anio;
     fechaGet(f, &dia, &mes, &anio);
     printf("%02d/%02d/%04d", dia, mes, anio);
}

bool esFechaValida(int dia, int mes, int anio)
{
     if(anio < 1601)
     {
         return false;
     }
     if(mes<1 || mes > 12)
     {
         return false;
     }
     if(dia < 1 || dia > cantDiasMes(mes, anio))
     {
         return false;
     }
     return true;
}
int fechaDiferencia(const Fecha* f1, const Fecha* f2)
{
    int totalF1 = cantDiasDesde1601(f1);
    int totalF2 = cantDiasDesde1601(f2);
    int resultado = 0;
    if(totalF1 > totalF2)
    {
        resultado = totalF1 - totalF2;
    }
    else{
        resultado = totalF2 - totalF1;
    }
    return resultado;
}

int fechaDiaSemana(const Fecha* f)
{
    int distanciaTotal = cantDiasDesde1601(f);
    int resultado = (distanciaTotal - 1) % 7;

    return resultado;
}

int cantDiasDesde1601(const Fecha* f)
{
    int i;
    int acum = 0;
    for(i=1601;i < f->anio ;i++)
    {
        acum += (esBisesto(i) ? 366 : 365);
    }
    acum += fechaDiaDelAnio(f);

    return acum;
}

int cantDiasMes(int mes, int anio)
{
     int cdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

     if(mes == 2 && esBisesto(anio))
     {
         return 29;
     }

     return cdm[mes];
}

bool esBisesto(int anio)
{
     return anio % 4 == 0 && (anio % 100 !=0 || anio % 400 == 0);
}
